#pragma once
#include "../NetworkUtilities.h"
#include "../Senders/MessageSender.h"
#include "../UDPNetworkingAPI.h"
class IWrapper; //forward declaration
class UDPNETWORKING_API SocketHolder {
private:
	int timerOffset = 0;
protected:
	IWrapper* wrapper;
	NET_DatagramSocket* socket;
	void PollSocket();
	virtual void ProcessMessage(NetworkMessage* msg) = 0;
	virtual MessageSender* GetSender() = 0;
	void StartTimer(int serverTime);
	bool TimerStarted();
public:
	int GetTime();
};