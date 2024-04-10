#pragma once
#include "shape.h"
#include "point.h"
class Triangle: public Shape
{
	private:
		Point p1 = NULL;
		Point p2 = NULL;
		Point p3 = NULL;
	public:
		Triangle(Point p1, Point p2, Point p3);
		void draw();
};

