#include "ellip.h"

Ellip::Ellip(Point center, int a, int b) {
	this->center = center;
	this->a = a;
	this->b = b;
};

void Ellip::draw() {
	glBegin(GL_POINTS);
	for (int i = 0; i < 360; i++) {
		float radian = i * (GL_PI / 180);
		glVertex2i(center.getX() + a * cos(radian), center.getY() + b * sin(radian));
	}
	glEnd();
	glFlush();
};

void Ellip::drawEllipMidPoint() {
	int x = 0;
	int y = b;
	int p = b * b - a * a * b + 0.25 * a * a;
	int twoA2 = 2 * a * a;
	int twoB2 = 2 * b * b;
	glBegin(GL_POINTS);
	while (b * b * (x + 1) < a * a * (y - 0.5)) {
		glVertex2i(center.getX() + x, center.getY() + y);
		glVertex2i(center.getX() + x, center.getY() - y);
		glVertex2i(center.getX() - x, center.getY() + y);
		glVertex2i(center.getX() - x, center.getY() - y);
		if (p < 0) {
			p += twoB2 * (x + 1) + b * b;
		}
		else {
			p += twoB2 * (x + 1) - twoA2 * (y - 1) + b * b;
			y--;
		}
		x++;
	}
	p = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
	while (y > 0) {
		glVertex2i(center.getX() + x, center.getY() + y);
		glVertex2i(center.getX() + x, center.getY() - y);
		glVertex2i(center.getX() - x, center.getY() + y);
		glVertex2i(center.getX() - x, center.getY() - y);
		if (p > 0) {
			p += -twoA2 * (y - 1) + a * a;
		}
		else {
			p += twoB2 * (x + 1) - twoA2 * (y - 1) + a * a;
			x++;
		}
		y--;
	}
	glEnd();
	glFlush();
};