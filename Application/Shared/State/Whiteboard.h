#pragma once
#include "Stroke.h"
#include "ForeignWIPStroke.h"
#include "LocalWIPStroke.h"
#include "CompletedStroke.h"
#include <vector>
#include <imgui.h>

class Whiteboard{
private:
    std::vector<CompletedStroke> committedStrokes;
    std::vector<ForeignWIPStroke> foreignWIPStrokes;
    LocalWIPStroke* localWIPStroke;
protected:
public:
    Whiteboard();   
    std::vector<Stroke*>* getAllStrokes();
    void GiveStroke(CompletedStroke s);
};