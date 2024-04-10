#pragma once
#include "shape.h"
#include "point.h"

class Parabola : public Shape {
private:
	Point focus;
	int p;
public:
	Parabola(Point focus, int p);
	void draw();
	void drawParaMidPoint();


};

