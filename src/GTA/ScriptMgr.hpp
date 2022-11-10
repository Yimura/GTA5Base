#pragma once
#include "common.hpp"
#include "fwdec.hpp"
#include "Script.hpp"

namespace Spyral
{
    using ScriptList = std::vector<std::shared_ptr<Script>>;

    class ScriptMgr
    {
    private:
        ScriptMgr() = default;

    public:
        ~ScriptMgr() = default;

        static ScriptList& Scripts()
        {
            return GetInstance().m_Scripts;
        }

        static std::shared_ptr<Script> AddScript(Script* script)
        { return GetInstance().AddScriptImpl(script); }
        static void TickScripts(void* stack, std::int64_t** globals, rage::scrProgram* program, rage::scrThreadContext* thread)
        { GetInstance().TickScriptsImpl(stack, globals, program, thread); }

    private:
        std::shared_ptr<Script> AddScriptImpl(Script* script);
        void TickScriptsImpl(void* stack, std::int64_t** globals, rage::scrProgram* program, rage::scrThreadContext* thread);

        static ScriptMgr& GetInstance()
        {
            static ScriptMgr i{};

            return i;
        }

    private:
        ScriptList m_Scripts;

    };
}