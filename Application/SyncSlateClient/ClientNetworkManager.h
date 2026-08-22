#pragma once
#include <SDL3/SDL.h>
#include "../Shared/Networking/Endpoints/Client.h"
#include "../Shared/SyncSlateWrapper.h"
#include <string>
#include <iostream>
class ClientNetworkManager{
private:
	std::unique_ptr<SyncSlateWrapper> wrapper;
protected:
public:
	void Init();
	void Update(float deltaTime);
	void Shutdown();
	std::string GetDebugInfo();
};