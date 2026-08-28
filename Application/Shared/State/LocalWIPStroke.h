#pragma once
#include "Stroke.h"
class LocalWIPStroke : public Stroke{
private:
    std::vector<StrokePoint*> points;
protected:
public:
    virtual void draw(ImDrawList* draw_list) override;
};