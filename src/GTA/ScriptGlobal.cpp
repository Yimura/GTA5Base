#include "Pointers.hpp"
#include "ScriptGlobal.hpp"

namespace Spyral
{
    ScriptGlobal::ScriptGlobal(std::size_t index)
        : m_index(index)
    {
        
    }

    ScriptGlobal ScriptGlobal::Add(std::ptrdiff_t offset)
    {
        return m_index + offset;
    }

    ScriptGlobal ScriptGlobal::At(std::ptrdiff_t idx, std::size_t size)
    {
        return m_index + 1 + (idx * size);
    }

    void* ScriptGlobal::Address() const
    {
        return Pointers::Globals[m_index >> 0x12 & 0x3F] + (m_index & 0x3FFFF);
    }
}