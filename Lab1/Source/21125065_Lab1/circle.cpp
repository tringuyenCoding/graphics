#include "circle.h"

Circle::Circle(Point center, int radius) {
	this->center = center;
	this->radius = radius;
};

// Draw circle using  Open GL function
void Circle::draw() {
	glBegin(GL_POINTS);
	for (int i = 0; i < 360; i++) {
		float radian = i * (GL_PI / 180);
		glVertex2i(center.getX() + radius * cos(radian), center.getY() + radius * sin(radian));
	}
	glEnd();
	glFlush();
};

// Draw circle using Midpoint algorithm
void Circle::drawCirMidPoint() {
	int x = 0;
	int y = radius;
	int p = 5 / 4 - radius;
	glBegin(GL_POINTS);
	while (x <= y) {
		glVertex2i(center.getX() + x, center.getY() + y);
		glVertex2i(center.getX() + x, center.getY() - y);
		glVertex2i(center.getX() - x, center.getY() + y);
		glVertex2i(center.getX() - x, center.getY() - y);
		glVertex2i(center.getX() + y, center.getY() + x);
		glVertex2i(center.getX() + y, center.getY() - x);
		glVertex2i(center.getX() - y, center.getY() + x);
		glVertex2i(center.getX() - y, center.getY() - x);
		if (p < 0) {
			p += 2 * x + 3;
		}
		else {
			p += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}
	glEnd();
	glFlush();
};