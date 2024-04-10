#include "polygon.h"
# define M_PI           3.14159265358979323846

Poly::Poly()
{
}

Poly::Poly(std::vector<Point> vertices)
{
	this->vertices = vertices;
}

void Poly::draw()
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < vertices.size(); i++)
	{
		glVertex2i(vertices[i].getX(), vertices[i].getY());
	}
	glEnd();
    glFlush();
}

void Poly::setVertices(std::vector<Point> vertices)
{
	this->vertices = vertices;
}

bool Poly::isInside(Point p) {
    int n = vertices.size();
    if (n < 3) return false; // Not a valid polygon

    // Ray casting algorithm to check if point is inside the polygon
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((vertices[i].getY() > p.getY()) != (vertices[j].getY() > p.getY())) &&
            (p.getX() < (vertices[j].getX() - vertices[i].getX()) * (p.getY() - vertices[i].getY()) / (vertices[j].getY() - vertices[i].getY()) + vertices[i].getX())) {
            inside = !inside;
        }
    }
    return inside;
}

void Poly::translate(float dx, float dy) {
    for (auto& vertex : vertices) {
        int newx = (int) ( (float) vertex.getX() + dx);
        int newy = (int) ( (float) vertex.getY() + dy);
        vertex.setX(newx);
        vertex.setY(newy);
    }
}

void Poly::rotate(float angleDegrees) {
    float angleRadians = angleDegrees * M_PI / 180.0f;
    float cosTheta = cos(angleRadians);
    float sinTheta = sin(angleRadians);

    for (auto& vertex : vertices) {
        float newX = (float) vertex.getX() * cosTheta - (float) vertex.getY() * sinTheta;
        float newY = (float) vertex.getX() * sinTheta + (float) vertex.getY() * cosTheta;
        vertex.setX((int) newX);
        vertex.setY((int) newY);
    }
}

void Poly::scale(float scaleFactor) {
    for (auto& vertex : vertices) {
        float newX = (float) vertex.getX() * scaleFactor;
        float newY = (float) vertex.getY() * scaleFactor;
        vertex.setX((int) newX);
        vertex.setY((int) newY);
    }
}