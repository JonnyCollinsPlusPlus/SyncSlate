#pragma once
#include <SDL3/SDL.h>
#include "Canvas.h"
#include "ClientNetworkManager.h"
#include <memory>
class SyncSlateClient{
private:
    bool active;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::unique_ptr<Canvas> canvas;
    std::unique_ptr<ClientNetworkManager> networkManager;
protected:
public:
    bool Init();
    void Run();
    void Shutdown();
    void Update(float deltaTime);
};
