#pragma once
#include "shape.h"
#include "point.h"

#define GL_PI 3.1415f

class Circle : public Shape {
private:
	Point center = NULL;
	int radius;

public:
	Circle(Point center, int radius);
	void draw();
	void drawCirMidPoint();

};

