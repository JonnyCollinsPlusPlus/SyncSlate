#include "StrokeStream.h"
#include "../Networking/NetworkUtilities.h"

StrokeStream::StrokeStream(int initID) : NetworkedValue(initID){
	
}

bool StrokeStream::StreamReceived(std::string streamData, int time){
	return true;
}

int StrokeStream::GetPacketPayloadLength(){
	return 96;
}

StrokePoint* StrokeStream::Deserialize(std::string data){
	std::string strokeIdString = data.substr(0, 16);
	std::string pointIdString = data.substr(16, 16);
	std::string xIdString = data.substr(32, 32);
	std::string yIdString = data.substr(64, 32);
	int strokeId = NetworkUtilities::IntFromBinaryString(strokeIdString, 4);
	int pointId = NetworkUtilities::IntFromBinaryString(pointIdString, 4);
	int x = NetworkUtilities::IntFromBinaryString(xIdString, 4);
	int y = NetworkUtilities::IntFromBinaryString(yIdString, 4);
	return new StrokePoint(strokeId, pointId, x, y);
}

std::string StrokeStream::Serialize(StrokePoint* stroke){
	std::string streamData = "";
	streamData.append(NetworkUtilities::AsBinaryString(stroke->strokeId, 4));
	streamData.append(NetworkUtilities::AsBinaryString(stroke->pointId, 4));
	streamData.append(NetworkUtilities::AsBinaryString(stroke->x, 8));
	streamData.append(NetworkUtilities::AsBinaryString(stroke->y, 8));
	return streamData;
}

std::string StrokeStream::Debug(){
	return "StrokeStream with " + std::to_string((int)points.size()) + ".";
}

StrokePoint* StrokeStream::GetCurrentValue(int currentTime, LibSettings* settings){
	if (points.size() == 0){
		return nullptr;
	}
	return points.back();
}
std::string StrokeStream::GetMetadata(){
	return "00000001";
}

std::vector<StrokePoint*> StrokeStream::getAllPoints(){
	return points;
}