#pragma once
#include <vector>
#include <SDL3/SDL.h>
#include "../Networking/CustomStreaming/NetworkedValue.h"
class Stroke{
private:
    std::vector<SDL_Point> points;
};

class StrokeStream : public NetworkedValue<Stroke*>{
    std::vector<SDL_Point> points;

	StrokeStream(int valueID);
	//Checks if an incoming stream data segment is relevant to this networked value
	// and, if so, processes it and returns true, otherwise returns false
	// @param streamData - the  64 bits of data containing both the ID and value data
	// should be a 64 character string containing only 1s and 0s
	virtual bool StreamReceived(std::string streamData, int time) override;
	//Returns the number of bits included in each value payload
	virtual int GetPacketPayloadLength() override;
	virtual Stroke* Deserialize(std::string data) override;
	//Returns the relevant data about this value ready for streaming as 64 bits formatted as
	// a string of payload length + 8 characters containing only 1s and 0s
	virtual std::string Serialize(Stroke* stroke) override;
	virtual std::string Debug() override;
	virtual Stroke* GetCurrentValue(int currentTime, LibSettings* settings) override;
    virtual std::string GetMetadata() override;
};