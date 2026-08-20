#include "SyncSlateServer.h"


void SyncSlateServer::Init(){
	NET_Init();
	networkManager = std::make_unique<ServerNetworkManager>();
	networkManager->Init();
}
void SyncSlateServer::Update(float deltaTime){
	networkManager->Update(deltaTime);
}
void SyncSlateServer::Shutdown(){
}
int main(int argc, char* argv[]) {
	SyncSlateServer* server = new SyncSlateServer();
	server->Init();
	while(true){
		server->Update(1);
	}
	server->Shutdown();
	delete server;
	server = nullptr;
	return 0;
}