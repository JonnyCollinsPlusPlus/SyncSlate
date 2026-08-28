#include "ForeignWIPStroke.h"
#include <vector>
#include "StrokePoint.h"
void ForeignWIPStroke::draw(ImDrawList* draw_list){
	std::cout << "DRAWING FOREIGNSTROKE" << std::endl;
	std::vector<StrokePoint*> points = stream.getAllPoints();
	for (int i = 0; i < points.size() - 1; i++){
		int x1 = points[i]->x;
		int y1 = points[i]->y;
		int x2 = points[i+1]->x;
		int y2 = points[i+1]->y;
		draw_list->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImColor(255, 0, 0, 255));
	}
}