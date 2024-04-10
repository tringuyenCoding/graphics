#pragma once
#include "shape.h"
#include "point.h"

class Line : public Shape {
private:
	Point p1 = NULL;
	Point p2 = NULL;
public:
	Line(Point p1, Point p2);
	void draw();
	void drawDDA();
	void drawBresenham();

};

