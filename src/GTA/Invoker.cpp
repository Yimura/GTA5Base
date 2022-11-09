#include "CrossMap.hpp"
#include "Invoker.hpp"
#include "Pointers.hpp"

namespace Spyral
{
    Invoker::NativeCallContext::NativeCallContext()
    {
        m_return_value = &m_ReturnStack[0];
        m_args = &m_ArgStack[0];
    }

    void Invoker::CacheHandlersImpl()
    {
        for (const auto [ firstHash, currHash ] : gCrossMap)
        {
            auto handler = Pointers::GetNativeHandler(Pointers::NativeRegistrationTable, currHash);

            m_HandlerCache.emplace(firstHash, handler);
        }

        m_HandlersCached = true;
    }

    void Invoker::BeginCallImpl()
    {
        m_CallContext.reset();
    }

    void Invoker::EndCallImpl(rage::scrNativeHash hash)
    {
        if (const auto& it = m_HandlerCache.find(hash); it != m_HandlerCache.end())
        {
            const auto& handler = it->second;

            handler(&m_CallContext);
            return Pointers::FixVectors(&m_CallContext);
        }

        LOGF(WARNING, "Failed to find '%X' native's handler.", hash);
    }
}