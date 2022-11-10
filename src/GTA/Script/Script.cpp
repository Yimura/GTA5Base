#include "Script.hpp"

namespace Spyral
{
    Script::Script(const script_func_t func, const std::size_t stackSize) :
        m_ScriptFunction(func)
    {
        m_ScriptFiber = CreateFiber(stackSize, [](void* param)
        {
            reinterpret_cast<Script*>(param)->IntermediateFunction();
        }, this);
    }

    Script::~Script()
    {
        if (m_ScriptFiber)
            DeleteFiber(m_ScriptFiber);
    }

    void Script::Tick()
    {
        m_MainFiber = GetCurrentFiber();
        if (!m_WakeTime.has_value() || m_WakeTime <= std::chrono::high_resolution_clock::now())
        {
            SwitchToFiber(m_ScriptFiber);
        }
    }

    void Script::Yield(std::optional<std::chrono::high_resolution_clock::duration> time)
    {
        m_WakeTime = std::nullopt;
        if (time.has_value())
        {
            m_WakeTime = std::chrono::high_resolution_clock::now() + time.value();
        }

        SwitchToFiber(m_MainFiber);
    }

    const Script* Script::Current()
    {
        return reinterpret_cast<Script*>(GetFiberData());
    }

    void Script::IntermediateFunction()
    {
        while(true)
        {
            m_ScriptFunction();
            Yield();
        }
    }
}