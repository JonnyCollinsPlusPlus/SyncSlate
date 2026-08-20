#include "ClientNetworkManager.h"

void ClientNetworkManager::Init(){
	wrapper = std::make_unique<SyncSlateWrapper>(55511, 100, true);
	wrapper->Initialize();
	wrapper->StartClient();
}
void ClientNetworkManager::Update(float deltaTime){
	wrapper->Update(deltaTime);
}
void ClientNetworkManager::Shutdown(){
}