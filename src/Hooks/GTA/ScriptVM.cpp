#include "../Hooks.hpp"
#include "../../Util/Joaat.hpp"
#include "../../GTA/Natives.hpp"
#include "../../GUI/GUI.hpp"

namespace Spyral
{
    rage::eThreadState GTA::ScriptVM(void* stack, std::int64_t** globals, rage::scrProgram* program, rage::scrThreadContext* thread)
    {
        const auto result = Hooking::GetHook<DetourHook>("ScriptVM")->Original<decltype(&ScriptVM)>()(stack, globals, program, thread);
        if (thread->m_script_hash == "main_persistent"_J)
        {
            // TODO: Tick scripts...
        }
        return result;
    }
}