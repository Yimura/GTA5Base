#pragma once
#include "common.hpp"
#include "script/scrNativeHandler.hpp"

namespace Spyral
{
    constexpr auto NativeCount = 6439;
    using CrossMap = std::array<std::pair<rage::scrNativeHash, rage::scrNativeHash>, NativeCount>;
    extern CrossMap gCrossMap;
}