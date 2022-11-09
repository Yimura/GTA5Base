#pragma once
#include <cstdint>
#include <string_view>

namespace Spyral
{
    using joaat_t = uint32_t;
    using long_joaat_t = uint64_t;

    inline constexpr char ToLower(char c)
    {
        return c >= 'A' && c <= 'Z' ? c | 1 << 5 : c;
    }

    /**
     * @brief Generate a 32bit hash from a string
     */
    extern constexpr joaat_t Joaat(const std::string_view b);
    /**
     * @brief Generate a 64bit hash from a string
     */
    extern constexpr long_joaat_t LongJoaat(const std::string_view b);

    inline consteval joaat_t operator ""_J(const char* s, std::size_t n)
    {
        joaat_t result = 0;

        for (std::size_t i = 0; i < n; i++)
        {            
            result += ToLower(s[i]);
            result += (result << 10);
            result ^= (result >> 6);
        }
        
        result += (result << 3);
        result ^= (result >> 11);
        result += (result << 15);

        return result;
    }
    inline consteval long_joaat_t operator ""_LJ(const char* s, std::size_t n)
    {
        long_joaat_t result = 0;

        for (std::size_t i = 0; i < n; i++)
        {            
            result += ToLower(s[i]);
            result += (result << 20);
            result ^= (result >> 12);
        }
        
        result += (result << 6);
        result ^= (result >> 22);
        result += (result << 30);

        return result;
    }
}