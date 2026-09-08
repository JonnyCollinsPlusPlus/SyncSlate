#include "Whiteboard.h"
Whiteboard::Whiteboard(){

	localWIPStroke = nullptr;
}
std::vector<Stroke*>* Whiteboard::getAllStrokes(){
	std::vector<Stroke*>* outStrokes = new std::vector<Stroke*>();
	if (localWIPStroke != nullptr){
		outStrokes->push_back(localWIPStroke);
	}
	for (ForeignWIPStroke& f : foreignWIPStrokes){
		outStrokes->push_back(&f);
	}
	for (CompletedStroke& c : committedStrokes){
		outStrokes->push_back(&c);
	}
	return outStrokes;
}
void Whiteboard::GiveStroke(CompletedStroke s){
	committedStrokes.push_back(s);
}