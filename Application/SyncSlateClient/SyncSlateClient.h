#pragma once
#include <SDL3/SDL.h>
#include "Canvas.h"
#include <memory>
class SyncSlateClient{
private:
    bool active;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::unique_ptr<Canvas> canvas;
protected:
public:
    bool init();
    void run();
    void shutdown();
};
