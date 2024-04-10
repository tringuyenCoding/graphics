#pragma once
#include "shape.h"
#include "point.h"

#define GL_PI 3.1415f

class Circle : public Shape {
private:
	Point center = NULL;
	int radius;

public:
	Circle();
	Circle(Point center, int radius);

	void draw();

	void setAttributes(Point center, int radius);

	int c_getX() {
		return center.getX();
	}
	int c_getY() {
		return center.getY();
	}

	int c_getRadius() {
		return radius;
	}

	bool IsInside(Point p);
};

