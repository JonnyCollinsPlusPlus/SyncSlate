#pragma once
#include "Stroke.h"
class CompletedStroke : public Stroke{
private:
    std::vector<StrokePoint*> points;

protected:
public:
    CompletedStroke(int x1, int y1, int x2, int y2);
    virtual void draw(ImDrawList* draw_list) override;
};