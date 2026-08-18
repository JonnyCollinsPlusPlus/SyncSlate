#pragma once
#include "Canvas.cpp"
#include "../State/Stroke.h"
#include <vector>
class Canvas{
private:
    std::vector<Stroke> committedStrokes;
};