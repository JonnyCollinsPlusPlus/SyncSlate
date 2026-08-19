#include "Canvas.h"
#include <imgui.h>
void Canvas::draw(){
    ImGui::Begin("My First Tool", &window_active, ImGuiWindowFlags_MenuBar);

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
            if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
            if (ImGui::MenuItem("Close", "Ctrl+W")) { window_active = false; }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    static float samples[100];
    for (int n = 0; n < 100; n++)
        samples[n] = sinf(n * 0.2f + (float)ImGui::GetTime() * 1.5f);
    ImGui::PlotLines("Samples", samples, 100);

    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Important Stuff");
    ImGui::BeginChild("Scrolling");
    for (int n = 0; n < 50; n++)
        ImGui::Text("%04d: Some text", n);
    ImGui::EndChild();

    ImGui::End();
}