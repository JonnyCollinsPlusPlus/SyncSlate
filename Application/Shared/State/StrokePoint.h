#pragma once
struct StrokePoint{
private:
protected:
public:
	StrokePoint(int pStrokeId, int pPointId, int pX, int pY);
	int strokeId; //The ID of the relevant stroke
	int pointId;  //The ID of this point within that stroke (in order from start of stroke to end)
	int x;
	int y;
};