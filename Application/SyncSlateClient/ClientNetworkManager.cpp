#include "ClientNetworkManager.h"

void ClientNetworkManager::Init(){
	wrapper = std::make_unique<SyncSlateWrapper>(55511, 100, true, this);
	wrapper->Initialize();
	wrapper->StartClient();
}
void ClientNetworkManager::Update(float deltaTime){
	wrapper->Update(deltaTime);
}
void ClientNetworkManager::Shutdown(){
}

void ClientNetworkManager::NewStroke(Stroke *s)
{
	std::cout << "new networked object being initialized!" << std::endl;
	wrapper->RegisterObject(s);
}

std::string ClientNetworkManager::GetDebugInfo(){
	return wrapper->GetDebugInfo();
}

Stroke* ClientNetworkManager::GiveStroke(){
	std::cout << "Stroke received!" << std::endl;
	return nullptr;
}