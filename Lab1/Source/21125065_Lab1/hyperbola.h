#pragma once

#include "shape.h"
#include "point.h"


class Hyperbola : public Shape {
private:
	Point center;
	int a, b;
public:
	Hyperbola(Point center, int a, int b);
	void draw();
	void drawHyperAsym();
	void drawHyperMidPoint();

};

