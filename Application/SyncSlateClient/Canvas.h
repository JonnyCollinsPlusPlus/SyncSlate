#pragma once
#include "../shared/State/Whiteboard.h"
class Canvas{
private:
    bool window_active;
    Whiteboard* board;
protected:
public:
    void draw();
};