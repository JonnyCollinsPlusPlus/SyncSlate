#pragma once
#include <imgui.h>
#include <vector>
#include "StrokePoint.h"
#include "StrokeStream.h"
#include "Stroke.h"
class ForeignWIPStroke : public Stroke
{
private:
	StrokeStream stream;
protected:
public:
    void draw(ImDrawList* draw_list);

};

