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

void Line::drawDDA() {
	int dx = p2.getX() - p1.getX();
	int dy = p2.getY() - p1.getY();
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;
	float X = p1.getX();
	float Y = p1.getY();

	glBegin(GL_POINTS);

	for (int i = 0; i <= steps; i++) {
		glVertex2i(X, Y);
		X += Xinc;
		Y += Yinc;
	}
	glEnd();
	glFlush();
};

void Line::drawBresenham() {
	int dx = p2.getX() - p1.getX();
	int dy = p2.getY() - p1.getY();
	int p = 2 * dy - dx;
	int twoDy = 2 * dy;
	int twoDyMinusDx = 2 * (dy - dx);
	int x, y;
	if (p1.getX() > p2.getX()) {
		x = p2.getX();
		y = p2.getY();
		p2.setX(p1.getX());
	}
	else {
		x = p1.getX();
		y = p1.getY();
	}
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	while (x < p2.getX()) {
		x++;
		if (p < 0) {
			p += twoDy;
		}
		else {
			y++;
			p += twoDyMinusDx;
		}
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
	}
	glFlush();
};