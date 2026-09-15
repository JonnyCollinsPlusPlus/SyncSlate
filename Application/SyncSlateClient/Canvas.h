#pragma once
#include "../shared/State/Whiteboard.h"
#include <memory>
class Canvas{
private:
    bool window_active;
    std::unique_ptr<Whiteboard> board;
protected:
public:
    Canvas();
    void draw();
    Stroke* MakeTestStroke();

};