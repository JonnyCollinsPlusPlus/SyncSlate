#include "Stroke.h"
#include "../Networking/NetworkUtilities.h"

StrokeStream::StrokeStream(int initID) : NetworkedValue(initID){
	
}

bool StrokeStream::StreamReceived(std::string streamData, int time){

}

int StrokeStream::GetPacketPayloadLength(){
	return 648;
}

Stroke* StrokeStream::Deserialize(std::string data){

}

std::string StrokeStream::Serialize(Stroke* stroke){
	std::string streamData = "";
	for (int i = 0;i < 10; i++){
		if (i >= points.size()){
			std::string s(64, '0');
			streamData.append(s);
			continue;
		}
		SDL_Point p = points[i];
		streamData.append(NetworkUtilities::AsBinaryString(p.x, 8));
		streamData.append(NetworkUtilities::AsBinaryString(p.y, 8));
	}
}

std::string StrokeStream::Debug(){
	return "StrokeStream with " + std::to_string((int)points.size()) + ".";
}

Stroke* StrokeStream::GetCurrentValue(int currentTime, LibSettings* settings){


}
std::string StrokeStream::GetMetadata(){
	return "00000001";
}