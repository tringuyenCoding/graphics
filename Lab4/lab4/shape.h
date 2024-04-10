#pragma once
class Point
{
	public:
		int x, y, z;
		Point() {};
		Point(int x, int y, int z) {
			this->x = x;
			this->y = y;
			this->z = z;
		};
		~Point() {};
};

class Shape
{
public:
	Shape() {};
	virtual void draw() = 0;

	~Shape() {};
};

class Cube : public Shape
{
public:
	Cube() {};
	void draw();
	~Cube() {};
};

class Sphere : public Shape
{
public:

	Sphere() {};
	void draw();
	~Sphere() {};
};

class Torus : public Shape
{
public:
	Torus() {};
	void draw();
	~Torus() {};
};

class Cone : public Shape
{
public:
	Cone() {};
	void draw();
	~Cone() {};

};

class Cylinder : public Shape
{
public:
	Cylinder() {};
	void draw();
	~Cylinder() {};
};

class Paraboloid : public Shape
{
public:
	Paraboloid() {};
	void draw();
	~Paraboloid() {};
};

class Hyperboloid : public Shape
{
public:
	Hyperboloid() {};
	void draw();
	~Hyperboloid() {};
};

class Triangle : public Shape
{
public:
	Triangle() {};
	void draw();
	~Triangle() {};
};