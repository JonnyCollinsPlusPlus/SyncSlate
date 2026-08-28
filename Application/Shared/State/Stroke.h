#pragma once
#include <vector>
#include <SDL3/SDL.h>
#include "../Networking/CustomStreaming/NetworkedValue.h"
#include "StrokePoint.h"
#include "imgui.h"
class Stroke{
private:
protected:
	int strokeId;
public:
	virtual void draw(ImDrawList* draw_list) = 0;
};

