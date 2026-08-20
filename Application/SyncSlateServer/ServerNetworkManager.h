#pragma once
#include "../Shared/Networking/Endpoints/Server.h"
#include "../Shared/SyncSlateWrapper.h"
class ServerNetworkManager{
private:
	std::unique_ptr<SyncSlateWrapper> wrapper;
protected:
public:
	void Init();
	void Update(float deltaTime);
	void Shutdown();
};