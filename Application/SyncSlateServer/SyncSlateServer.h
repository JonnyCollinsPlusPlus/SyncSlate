#pragma once
#include "ServerNetworkManager.h"
#include <SDL3/SDL.h>
class SyncSlateServer{
private:
    bool debug;
    SDL_Window* window;
    SDL_Renderer* renderer;
	std::unique_ptr<ServerNetworkManager> networkManager;
protected:
public:
bool Init();
void Update(float deltaTime);
void Shutdown();
};
