#include "Pointers.hpp"
#include "Memory/ModuleMgr.hpp"
#include "Memory/PatternScanner.hpp"

#include "script/scrProgramTable.hpp"
#include "script/scrNativeRegistrationTable.hpp"

namespace Spyral
{
    void Pointers::Destroy()
    {
        
    }

    void Pointers::Init()
    {
        const auto module = ModuleMgr::GetModule("GTA5.exe");
        PatternScanner scanner(module);

		scanner.Add("IDXGISwapChain", "48 8B 0D ? ? ? ? 48 85 C9 0F 84 02 02 00 00", [](AddressHelper addr)
		{
            SwapChain = addr.Add(3).Relative().As<IDXGISwapChain**>();

            return true;
		});

        scanner.Add("WNDPROC", "48 8B C4 48 89 58 08 4C 89 48 20 55 56 57 41 54 41 55 41 56 41 57 48 8D 68 A1 48 81 EC F0", [](AddressHelper addr)
        {
            WndProc = addr.As<WNDPROC>();

            return true;
        });

        scanner.Add("ScriptPrograms", "48 8B 1D ? ? ? ? 41 83 F8 FF", [](AddressHelper addr)
        {
            ScriptProgramTable = addr.Add(3).Relative().As<rage::scrProgramTable*>();

            return true;
        });

        scanner.Add("NativeRegistrationTable/GetNativeHandler", "48 8D 0D ? ? ? ? 48 8B 14 FA E8 ? ? ? ? 48 85 C0 75 0A", [](AddressHelper addr)
        {
            NativeRegistrationTable = addr.Add(3).Relative().As<rage::scrNativeRegistrationTable*>();
			GetNativeHandler = addr.Add(12).Relative().As<decltype(GetNativeHandler)>();

            return true;
        });

        scanner.Add("FixVectors", "83 79 18 00 48 8B D1 74 4A FF 4A 18 48 63 4A 18 48 8D 41 04 48 8B 4C CA", [](AddressHelper addr)
        {
            FixVectors = addr.As<decltype(FixVectors)>();

            return true;
        });

        scanner.Add("ScriptVM/ScriptGlobals", "48 85 FF 48 89 1D", [](AddressHelper addr)
        {
            Globals = addr.Sub(12).Relative().As<std::int64_t**>();
            ScriptVM = addr.Sub(4).Relative().As<void**>();
            
            return true;
        });

		scanner.Scan();

        if (hwnd = FindWindowA("grcWindow", nullptr); !hwnd)
            LOG(WARNING) << "Failed to find game window.";

        LOG(INFO) << "Finished module address lookups.";
    }
}
