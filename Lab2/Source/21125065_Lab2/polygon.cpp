#include "polygon.h"

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