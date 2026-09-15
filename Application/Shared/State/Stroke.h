#pragma once
#include <vector>
#include <SDL3/SDL.h>
#include "../Networking/CustomStreaming/NetworkedValue.h"
#include "StrokePoint.h"
#include "imgui.h"
#include "../Networking/Wrapper/IEngineObject.h"

class Stroke : public IEngineObject{
private:
protected:
	int strokeId;
public:
	virtual void draw(ImDrawList* draw_list) = 0;
};

