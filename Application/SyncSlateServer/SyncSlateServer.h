#pragma once
#include "ServerNetworkManager.h"
class SyncSlateServer{
private:
	std::unique_ptr<ServerNetworkManager> networkManager;
protected:
public:
void Init();
void Update(float deltaTime);
void Shutdown();
};
