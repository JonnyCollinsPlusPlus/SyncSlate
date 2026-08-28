#pragma once
#include "Stroke.h"
#include "ForeignWIPStroke.h"
#include "LocalWIPStroke.h"
#include <vector>
#include <imgui.h>

class Whiteboard{
private:
    std::vector<Stroke> committedStrokes;
    std::vector<ForeignWIPStroke> foreignWIPStrokes;
    LocalWIPStroke localWIPStroke;
protected:
public:
    std::vector<Stroke*> getAllStrokes();
};