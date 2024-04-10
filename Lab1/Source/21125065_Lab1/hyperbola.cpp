#include "hyperbola.h"

Hyperbola::Hyperbola(Point center, int a, int b) {
	this->center = center;
	this->a = a;
	this->b = b;
};



// draw hyperbola using Open GL function
void Hyperbola::draw() {
	glBegin(GL_POINTS);
	for (float i = -10.0; i <= 10.0; i+=0.01) {
		float x = center.getX() + a / cos(i);
		float y = center.getY() + b * tan(i);
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
};

void Hyperbola::drawHyperAsym() {
	int x = 0;
	int y = 0;
	int p = 0.25 * b * b - a * a * b * b - a * a;
	int twoA2 = 2 * a * a;
	int twoB2 = 2 * b * b;
	glBegin(GL_POINTS);
	while (y < 500) {
		glVertex2i(center.getX() + x, center.getY() + y);
		glVertex2i(center.getX() + x, center.getY() - y);
		glVertex2i(center.getX() - x, center.getY() + y);
		glVertex2i(center.getX() - x, center.getY() - y);
		if (p > 0) {
			p += -twoA2 * (y + 1) - a * a;
		}
		else {
			p += twoB2 * (x + 1) - twoA2 * (y + 1) - a * a;
			x++;
		}
		y++;
	}
	glEnd();
	glFlush();
}

void Hyperbola::drawHyperMidPoint() {
	int x = 0;
	int y = b;
	int p = b * b - a * a * b + 0.25 * a * a;
	//int p = b*b -a*a*b*b-a*a*b + 0.25*a*a;
	int twoA2 = 2 * a * a;
	int twoB2 = 2 * b * b;
	glBegin(GL_POINTS);
	while (b * b * (x + 1) < a * a * (y - 0.5)) {
		glVertex2i(center.getX() + x - 2 * a, center.getY() + y);
		glVertex2i(center.getX() + x - 2 * a, center.getY() - y);
		glVertex2i(center.getX() - x + 2 * a, center.getY() + y);
		glVertex2i(center.getX() - x + 2 * a, center.getY() - y);
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
		glVertex2i(center.getX() + x - 2 * a, center.getY() + y);
		glVertex2i(center.getX() + x - 2 * a, center.getY() - y);
		glVertex2i(center.getX() - x + 2 * a, center.getY() + y);
		glVertex2i(center.getX() - x + 2 * a, center.getY() - y);
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