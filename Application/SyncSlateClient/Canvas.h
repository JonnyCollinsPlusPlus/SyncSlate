#pragma once
#include "Canvas.cpp"
#include "../State/Stroke.h"
#include "../State/WIPStroke.h"
#include <vector>
class Canvas{
private:
    std::vector<Stroke> committedStrokes;
    std::vector<WIPStroke> foreignWIPStrokes;
    WIPStroke localWIPStroke;
};