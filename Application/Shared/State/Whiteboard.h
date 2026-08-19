#pragma once
#include "Stroke.h"
#include "WIPStroke.h"
#include <vector>

class Whiteboard{
private:
    std::vector<Stroke> committedStrokes;
    std::vector<WIPStroke> foreignWIPStrokes;
    WIPStroke localWIPStroke;
protected:
public:
};