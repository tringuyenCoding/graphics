#include "line.h"

Line::Line(Point p1, Point p2) {
	this->p1 = p1;
	this->p2 = p2;
};

void Line::draw() {
	glBegin(GL_LINES);
	glVertex2i(p1.getX(), p1.getY());
	glVertex2i(p2.getX(), p2.getY());
	glEnd();
};