#pragma once
#include "shape.h"
#include "point.h"

#define GL_PI 3.1415f

class Ellip : public Shape {
private:
	Point center;
	int a, b;

public:
	Ellip();
	Ellip(Point c, int a, int b);
	
	void draw();
	void setAttributes(Point c, int a, int b);

	int e_getX() {
		return center.getX();
	}

	int e_getY() {
		return center.getY();
	}

	bool IsInside(Point p);

};

