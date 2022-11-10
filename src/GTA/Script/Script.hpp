#pragma once
#include "common.hpp"

namespace Spyral
{
    using script_func_t = std::function<void()>;

    class Script
    {
    public:
        /**
         * @brief Construct a new Script object
         * 
         * @param func Function to execute
         * @param stackSize Different stack size value to be used in CreateFiber
         */
        explicit Script(const script_func_t func, const std::size_t stackSize = 0);
        virtual ~Script();

        void Tick();
        #undef Yield
        void Yield(std::optional<std::chrono::high_resolution_clock::duration> time = std::nullopt);

        static const Script* Current();

    private:
        void IntermediateFunction();

    private:
        void* m_ScriptFiber;
        void* m_MainFiber;

        const script_func_t m_ScriptFunction;

        std::optional<std::chrono::high_resolution_clock::time_point> m_WakeTime;

    };
}