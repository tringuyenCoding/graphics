#pragma once
#include "point.h"
#include "shape.h"
class Quad: public Shape
{
	private:
		Point p1 = NULL;
		Point p2 = NULL;
		Point p3 = NULL;
		Point p4 = NULL;
	public:
		Quad(Point p1, Point p2, Point p3, Point p4);
		void draw();
};

