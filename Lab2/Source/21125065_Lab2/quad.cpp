#include "quad.h"

Quad::Quad(Point p1, Point p2, Point p3, Point p4) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
};

void Quad::draw() {
	glBegin(GL_LINE_LOOP);
	glVertex2i(p1.getX(), p1.getY());
	glVertex2i(p2.getX(), p2.getY());
	glVertex2i(p3.getX(), p3.getY());
	glVertex2i(p4.getX(), p4.getY());
	glEnd();
};