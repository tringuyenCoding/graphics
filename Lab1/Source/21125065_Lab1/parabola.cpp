#include "parabola.h"

Parabola::Parabola(Point focus, int p) {
	this->focus = focus;
	this->p = p;
};

void Parabola::draw() {
	glBegin(GL_POINTS);
	int h = focus.getX();
	int k = focus.getY();
	float x, y;
	for (x = h - 200; x <= h + 200; x += 0.01) {
		y = (-0.25 / p) * ((x - h) * (x - h)) + k;
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
};

//draw Parabola using midPoint algorithm on opengl
void Parabola::drawParaMidPoint() {
	int x = 0;
	int y = focus.getY();
	int p = 1 - 2 * this->p;

	glBegin(GL_POINTS);
	while (x <= y && x<=200) {
		glVertex2i(x + focus.getX(), y);
		glVertex2i(-x + focus.getX(), y);
		if (p < 0) {
			p += 2 * (x + 1) + 1;
		}
		else {
			p += 2 * (x + 1) - 2 * (y - 1) + 1;
			y--;
		}
		x++;
	}
	glEnd();
	glFlush();
};