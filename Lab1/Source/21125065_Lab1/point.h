#pragma once
#include "shape.h"
#include "library.h"

class Point {
private:
	int x, y;

public:
	Point(int x = 0, int y = 0);

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);
};

