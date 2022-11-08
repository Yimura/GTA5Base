#include "GUI.hpp"
#include "../Renderer/Renderer.hpp"
#include "Menu/Menu.hpp"

namespace Spyral
{
    GUI::GUI()
        : m_IsOpen(false)
    {
        Renderer::AddDXCallback(Menu::Main, -1);
        Renderer::AddWindowProcedureCallback([this](HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
        {
            GUI::WndProc(hwnd, msg, wparam, lparam);
        }, 9999);
    }

    GUI::~GUI()
    {

    }

    void GUI::ToggleMouse()
    {
        auto& io = ImGui::GetIO();
        if (GUI::IsOpen())
        {
            io.MouseDrawCursor = true;
            io.ConfigFlags &= ~ImGuiConfigFlags_NoMouse;
        }
        else
        {
            io.MouseDrawCursor = false;
            io.ConfigFlags |= ImGuiConfigFlags_NoMouse;
        }
    }

    void GUI::WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        if (msg == WM_KEYUP && wparam == VK_INSERT)
        {
            m_IsOpen = !m_IsOpen;
            ToggleMouse();
        }
    }
}