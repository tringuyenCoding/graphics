#include "circle.h"


Circle::Circle() {
	this->center = Point(0, 0);
	this->radius = 0;
};

Circle::Circle(Point center, int radius) {
	this->center = center;
	this->radius = radius;
};

// Set attributes for the circle
void Circle::setAttributes(Point center, int radius) {
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

// Check if point is inside the circle
bool Circle::IsInside(Point p) {
	return (pow(p.getX() - center.getX(), 2) + pow(p.getY() - center.getY(), 2) <= pow(radius, 2));
};