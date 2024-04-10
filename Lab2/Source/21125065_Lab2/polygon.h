#pragma once
#include <cmath>
#include <vector>
#include "point.h"
class Poly : public Shape
{
	private:
		std::vector<Point> vertices;
	public:
		Poly();
		Poly(std::vector<Point> vertices);
		void draw();
		bool isInside(Point p);
		void setVertices(std::vector<Point> vertices);
};

