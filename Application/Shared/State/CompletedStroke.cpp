#include "CompletedStroke.h"

CompletedStroke::CompletedStroke(int x1, int y1, int x2, int y2){
	StrokePoint* s1 = new StrokePoint(1, 1, x1, y1);
	StrokePoint* s2 = new StrokePoint(1, 2, x2, y2);
	points.push_back(s1);
	points.push_back(s2);
}
void CompletedStroke::draw(ImDrawList* draw_list){
	for (int i = 0; i < (points.size() - 1); i++){
		int x1 = points[i]->x;
		int y1 = points[i]->y;
		int x2 = points[i+1]->x;
		int y2 = points[i+1]->y;
		draw_list->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImColor(255, 0, 0, 255));
	}
}