#include "Canvas.h"
#include <imgui.h>
Canvas::Canvas() : board(std::make_unique<Whiteboard>()) {
    
}
void Canvas::draw(){
    ImGuiIO& io = ImGui::GetIO();
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);

    ImGuiWindowFlags flags = ImGuiWindowFlags_NoTitleBar
        | ImGuiWindowFlags_NoResize
        | ImGuiWindowFlags_NoMove
        | ImGuiWindowFlags_NoCollapse
        | ImGuiWindowFlags_NoBringToFrontOnFocus
        | ImGuiWindowFlags_NoNavFocus;
    ImGui::Begin("Canvas", &window_active, flags);

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Open..", "Ctrl+O")) { /* Do stuff */ }
            if (ImGui::MenuItem("Save", "Ctrl+S")) { /* Do stuff */ }
            if (ImGui::MenuItem("Close", "Ctrl+W")) { window_active = false; }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    std::vector<Stroke*>* strokes = (board->getAllStrokes());
    for (Stroke* s : *strokes){
        s->draw(draw_list);
    }
    //draw_list->AddLine(ImVec2(10, 10), ImVec2(200, 200), IM_COL32(0, 255, 255, 150), 30);
    ImGui::TextColored(ImVec4(1, 1, 0, 1), "Important Stuff");
    ImGui::BeginChild("Scrolling");
    for (int n = 0; n < 50; n++)
        ImGui::Text("%04d: Some text", n);
    ImGui::EndChild();

    ImGui::End();
}

void Canvas::MakeTestStroke(){
    CompletedStroke *s = new CompletedStroke(10, 10, 50, 50);
    CompletedStroke s2 = *s;
	board->GiveStroke(s2);
    //must register object with engine
    //TODO do this by returning the object back through call layers to a layer
    // where the wrapper is referenced and calling the register there
}