#pragma once
#include <SDL3/SDL.h>
#include "Canvas.h"
#include "ClientNetworkManager.h"
#include "InputManager.h"
#include <memory>
class SyncSlateClient{
private:
    bool active;
    bool debug;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::unique_ptr<Canvas> canvas;
    std::unique_ptr<ClientNetworkManager> networkManager;
    std::unique_ptr<InputManager> inputManager;
protected:
public:
    bool Init();
    void Run();
    void Shutdown();
    void Update(float deltaTime);
    InputManager& GetInputManager() { return *inputManager; }};
