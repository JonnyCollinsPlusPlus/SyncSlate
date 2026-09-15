#include "SyncSlateWrapper.h"
#include "Networking/Wrapper/IEngineObject.h"
#include "Networking/Endpoints/Client.h"
#include "Networking/Endpoints/Server.h"
#include "Networking/CustomStreaming/INetworkedValue.h"
#include "./State/StrokeStream.h"
SyncSlateWrapper::SyncSlateWrapper(int port, int lerpDelay, bool lerpEnabled, NetworkManager* pManager)
{
	plannedPort = port;
	server = nullptr;
	registeredCallbacks = new std::vector<Callback*>();
	settings = new LibSettings();
	settings->lerpDelay = lerpDelay;
	settings->lerpEnabled = lerpEnabled;
	manager = pManager;
}

void SyncSlateWrapper::Update(float deltaTime)
{
	client->Update(deltaTime);
	if (server != nullptr) {
		server->Update(deltaTime);
	}
}

void SyncSlateWrapper::Initialize()
{
	client = new Client(plannedPort, this, settings);
}

void SyncSlateWrapper::RegisterObject(IEngineObject* object)
{
	client->RegisterObject(object);
}

void SyncSlateWrapper::UnregisterObject(int ID)
{
	//TODO implement
}

void SyncSlateWrapper::RegisterCallback(int ID)
{
	//TODO implement
	//registeredCallbacks->push_back(new DemoCallback(ID));
}

void SyncSlateWrapper::StartClient()
{
	client->ConnectToServer("127.0.0.1");
}

void SyncSlateWrapper::StartServer()
{
	server = new Server("127.0.0.1", 55533, this, settings);
}

void SyncSlateWrapper::ApplySettings()
{
}

void SyncSlateWrapper::InvokeRegisteredCallback(int callbackID, std::string optionalExtraData)
{
	//TODO implement
	/*
	std::cout << "callback being called with ID: " << callbackID << std::endl;
	for (Callback* cb : *registeredCallbacks) {
		if (cb->matchesID(callbackID)) {
			cb->Invoke(optionalExtraData);
		}
	}
	*/
}
//TODO clean up object initialization pipeline (right now - int object type -> NewNetworkedObject -> Find object type again -> initialize values)
IEngineObject* SyncSlateWrapper::NewNetworkedObject(int objectType, bool belongsToClient)
{
	switch (objectType){
		case 0:
			return manager->GiveStroke();
	}
}

INetworkedValue* SyncSlateWrapper::NewNetworkedValue(int valueID, int valueType)
{
	return new StrokeStream(valueID);
}

std::string SyncSlateWrapper::NetworkedValueMetadata(INetworkedValue* value)
{
	if (!value) return "";

	return NetworkUtilities::AsBinaryString(value->GetID(), 2) + value->GetMetadata();
}

int SyncSlateWrapper::EngineObjectMetadata(IEngineObject* obj)
{
	return 0;
}

std::vector<INetworkedValue*>* SyncSlateWrapper::ObjectInitialValues(IEngineObject* obj)
{
	int objectType = EngineObjectMetadata(obj);
	std::vector<INetworkedValue*>* values = new std::vector<INetworkedValue*>();
	switch (objectType) {
	case 0:
		values->push_back(new StrokeStream(0));
		break;
	}
	return values;
}


void SyncSlateWrapper::CallbackTest()
{
	client->SendServerMessage(UserImportant, NetworkUtilities::AsBinaryString(500, 3) + "1010");
}

int SyncSlateWrapper::GetClientTime()
{
	return client->GetTime();;
}
std::string SyncSlateWrapper::GetDebugInfo(){
	std::string out = "";
	out.append("Is Server: ");
	out.append(std::to_string(server != nullptr));
	out.append("\nClient time: ");
	out.append(std::to_string(client->GetTime()));
	out.append("\nClient connected: ");
	out.append(std::to_string(client->IsConnected()));
	if (server!= nullptr){
		out.append("\nServer connected: ");
		out.append(std::to_string(server->GetConnectedClientCount()));
	}
	return out;
}