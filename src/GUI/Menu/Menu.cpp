#include "Menu.hpp"
#include "GTA/ScriptGlobal.hpp"

namespace Spyral
{
    void Menu::Main()
    {
        if (!GUI::IsOpen())
            return;

        if (ImGui::Begin("Test"))
        {
            if (ImGui::Button("Trigger Off-Radar"))
            {
                *ScriptGlobal(2689235).At(0, 453).Add(208).As<int*>() = true;
                *ScriptGlobal(2703735).Add(56).As<int*>() = INT_MAX;
            }

            if (ImGui::Button("Unload"))
                gRunning = false;
        }
        ImGui::End();
    }
}