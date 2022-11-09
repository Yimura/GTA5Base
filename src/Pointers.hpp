#pragma once
#include "common.hpp"
#include "GTA/fwdec.hpp"
#include "script/scrNativeHandler.hpp"

namespace Spyral::Pointers
{
    extern void Destroy();
    extern void Init();

    inline std::int64_t** Globals;
    inline void** ScriptVM;
    inline rage::scrProgramTable* ScriptProgramTable;
    inline void (*FixVectors)(rage::scrNativeCallContext* callContext);
    inline rage::scrNativeHandler (*GetNativeHandler)(rage::scrNativeRegistrationTable* registrationTable, rage::scrNativeHash hash);
    inline rage::scrNativeRegistrationTable* NativeRegistrationTable;

    inline IDXGISwapChain** SwapChain;
    inline WNDPROC WndProc;
    inline HWND hwnd;
}