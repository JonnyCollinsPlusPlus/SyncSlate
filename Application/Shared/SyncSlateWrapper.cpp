#include "SyncSlateWrapper.h"
#include "Networking/Wrapper/IEngineObject.h"
#include "Networking/Endpoints/Client.h"
#include "Networking/Endpoints/Server.h"
#include "Networking/CustomStreaming/INetworkedValue.h"
SyncSlateWrapper::SyncSlateWrapper(int port, int lerpDelay, bool lerpEnabled)
{
	plannedPort = port;
	server = nullptr;
	registeredCallbacks = new std::vector<Callback*>();
	settings = new LibSettings();
	settings->lerpDelay = lerpDelay;
	settings->lerpEnabled = lerpEnabled;
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
	//TODO implement
	/*
	IEngineObject* newObj = nullptr;
	switch (objectType) {
	case 0:
		newObj = new DemoPlayer(this);;
		if (!belongsToClient) {
			otherPlayers->push_back((DemoPlayer*)newObj);
		}
		break;
	case 1:
		newObj = new DemoColourSquare(this, 100);
		if (!belongsToClient) {
			otherSquares->push_back((DemoColourSquare*)newObj);
		}
		break;
	}
	return newObj;
	*/
return nullptr;
}

INetworkedValue* SyncSlateWrapper::NewNetworkedValue(int valueID, int valueType)
{
	//TODO implement
	/*
	std::cout << "new networked value with type id: " << valueType << std::endl;
	switch (valueType) {
	case 0:
		return new PositionLerp2D(valueID, 0 ,0);
	case 1:
		return new ColourValue(valueID, 0);
	default:
		return nullptr;
	}
	*/
return nullptr;
}

std::string SyncSlateWrapper::NetworkedValueMetadata(INetworkedValue* value)
{
	if (!value) return "";

	return NetworkUtilities::AsBinaryString(value->GetID(), 2) + value->GetMetadata();
}

int SyncSlateWrapper::EngineObjectMetadata(IEngineObject* obj)
{
	//TODO implement
	/*
	if (!obj) return 0;

	if (auto* player = dynamic_cast<DemoPlayer*>(obj)) {

		return 0;
	}
	else if (auto* colourSquare = dynamic_cast<DemoColourSquare*>(obj)) {

		return 1;
	}

	return 0;
	*/
	return 0;

}

std::vector<INetworkedValue*>* SyncSlateWrapper::ObjectInitialValues(IEngineObject* obj)
{
	//TODO implement
	/*
	int objectType = EngineObjectMetadata(obj);
	std::vector<INetworkedValue*>* values = new std::vector<INetworkedValue*>();
	switch (objectType) {
	case 0:
		values->push_back(new PositionLerp2D(0, 18, 18));
		break;
	case 1:
		values->push_back(new ColourValue(0, 0));
		break;
	}

	return values;
	*/
	return nullptr;

}

void SyncSlateWrapper::DrawOtherPlayers(SDL_Renderer* renderer)
{
	//TODO implement
	/*
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	for (DemoPlayer* dp : *otherPlayers) {
		const SDL_FRect rect = dp->GetRect();
		SDL_RenderRect(renderer, &rect);
	}
	for (DemoColourSquare* dcs : *otherSquares) {
		dcs->Render(renderer);
	}
	*/
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