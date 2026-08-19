#pragma once
#include <SDL3/SDL.h>
#include "Canvas.h"
class SyncSlateClient{
private:
    bool active;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Canvas* canvas;
protected:
public:
    bool init();
    void run();
    void shutdown();
};
