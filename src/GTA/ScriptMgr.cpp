#include "ScriptMgr.hpp"
#include "script/scrThreadContext.hpp"

namespace Spyral
{
    std::shared_ptr<Script> ScriptMgr::AddScriptImpl(Script* script)
    {
        return m_Scripts.emplace_back(std::shared_ptr<Script>(script));
    }

    void ScriptMgr::TickScriptsImpl(void* stack, std::int64_t** globals, rage::scrProgram* program, rage::scrThreadContext* thread)
    {
        if (thread->m_script_hash != "main_persistent"_J)
            return;

        // Required to be able to switch to other threads
        static void* _ = ConvertThreadToFiber(nullptr);

        for (const auto& script : m_Scripts)
        {
            script->Tick();
        }
    }
}