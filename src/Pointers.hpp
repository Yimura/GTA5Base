#pragma once
#include "common.hpp"
#include "script/scrProgramTable.hpp"

namespace Spyral::Pointers
{
    extern void Destroy();
    extern void Init();

    inline std::int64_t** Globals;
    inline void** ScriptVM;
    inline rage::scrProgramTable* ScriptProgramTable;

    inline IDXGISwapChain** SwapChain;
    inline WNDPROC WndProc;
    inline HWND hwnd;
}