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
	ForeignWIPStroke();
    virtual void draw(ImDrawList* draw_list) override;
	virtual void UpdateLibraryValues(std::vector<INetworkedValue*>* values) override;
	virtual void UpdateEngineValues(std::vector<INetworkedValue*>* values, LibSettings* settings) override;
};

