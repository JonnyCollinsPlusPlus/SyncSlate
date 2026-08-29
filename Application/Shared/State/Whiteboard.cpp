#include "Whiteboard.h"
Whiteboard::Whiteboard(){
	CompletedStroke* s = new CompletedStroke(10, 10, 50, 50);
	committedStrokes.push_back(*s);
	CompletedStroke* s2 = new CompletedStroke(60, 60, 100, 100);
	committedStrokes.push_back(*s2);

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