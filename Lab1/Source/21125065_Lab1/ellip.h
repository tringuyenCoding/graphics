#pragma once
#include "shape.h"
#include "point.h"

#define GL_PI 3.1415f

class Ellip : public Shape {
private:
	Point center;
	int a, b;

public:
	Ellip(Point c, int a, int b);
	void draw();
	void drawEllipMidPoint();

};

