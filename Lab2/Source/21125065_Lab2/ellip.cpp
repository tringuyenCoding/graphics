#include "ellip.h"

Ellip::Ellip() {
	this->center = Point(0, 0);
	this->a = 0;
	this->b = 0;
};

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

void Ellip::setAttributes(Point center, int a, int b) {
	this->center = center;
	this->a = a;
	this->b = b;
};

bool Ellip::IsInside(Point p) {
	return (pow(p.getX() - center.getX(), 2) / pow(a, 2) + pow(p.getY() - center.getY(), 2) / pow(b, 2) <= 1);
};
