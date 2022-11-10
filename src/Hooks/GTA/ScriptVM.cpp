#include "../Hooks.hpp"
#include "../../GTA/ScriptMgr.hpp"

namespace Spyral
{
    rage::eThreadState GTA::ScriptVM(void* stack, std::int64_t** globals, rage::scrProgram* program, rage::scrThreadContext* thread)
    {
        const auto result = Hooking::GetHook<DetourHook>("ScriptVM")->Original<decltype(&ScriptVM)>()(stack, globals, program, thread);
        ScriptMgr::TickScripts(stack, globals, program, thread);
        return result;
    }
}