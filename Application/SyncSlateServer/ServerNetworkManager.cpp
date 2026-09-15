#include "ServerNetworkManager.h"


void ServerNetworkManager::Init(){
	wrapper = std::make_unique<SyncSlateWrapper>(55522, 100, true, this);
	wrapper->Initialize();
	wrapper->StartServer();
}
void ServerNetworkManager::Update(float deltaTime){
	wrapper->Update(deltaTime);
}
void ServerNetworkManager::Shutdown(){

}
std::string ServerNetworkManager::GetDebugInfo(){
	return wrapper->GetDebugInfo();
}


Stroke* ServerNetworkManager::GiveStroke(){
	std::cout << "Stroke received!" << std::endl;
	return nullptr;
}