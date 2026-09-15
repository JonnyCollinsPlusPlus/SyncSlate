#pragma once
#include "../Shared/Networking/Endpoints/Server.h"
#include "../Shared/NetworkManager.h"
#include "../Shared/SyncSlateWrapper.h"
#include <string>
class ServerNetworkManager : public NetworkManager {
private:
	std::unique_ptr<SyncSlateWrapper> wrapper;
protected:
public:
	void Init();
	void Update(float deltaTime);
	void Shutdown();
	std::string GetDebugInfo();
    virtual Stroke* GiveStroke() override;

};