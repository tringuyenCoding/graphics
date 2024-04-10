#pragma once
#include "library.h"
#include "shape.h"
#include "point.h"
#include "line.h"
#include "circle.h"
#include "ellip.h"
#include "parabola.h"
#include "hyperbola.h"
using namespace std;

vector<vector<int>> readInput(string filename) {
	string line;
	vector<vector<int>> data;
	ifstream file(filename);

	if (!file.is_open()) {
		cout << "File not found" << endl;
		return data;
	}

	while (getline(file, line)) {
		vector<int> row;
		istringstream iss(line);
		int value;
		while (iss >> value) {
			row.push_back(value);
		}
		data.push_back(row);
	}
	file.close();
	return data;
}

void SetupRC() {
	glClearColor(0.8f, 1.0f, 0.8f, 1.0f);
}

int measureTime(function<void()> function) {
	auto start = std::chrono::high_resolution_clock::now();
	function(); // Execute the function
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> duration = end - start;
	return duration.count(); // Return the execution time in microseconds
}

// Self-implemented function

void LineDDA(vector<int> row) {

	Point p1(row[1], row[2]);
	Point p2(row[3], row[4]);
	Line l1(p1, p2);
	int time = measureTime([&]() {
		l1.drawDDA();
		});
	cout << "Drawing line by DDA tooks: " << time << " microseconds" << endl;
}

void LineBresenham(vector<int> row) {
	Point p1(row[1], row[2]);
	Point p2(row[3], row[4]);
	Line l1(p1, p2);
	int time = measureTime([&]() {
		l1.drawBresenham();
		});
	cout << "Drawing line by Bresenham tooks: " << time << " microseconds" << endl;
}

void CircleMidPoint(vector<int> row) {
	Point center(row[1], row[2]);
	Circle c1(center, row[3]);
	int time = measureTime([&]() {
		c1.drawCirMidPoint();
		});
	cout << "Drawing circle by Midpoint tooks: " << time << " microseconds" << endl;
}

void EllipseMidPoint(vector<int> row) {
	Point cen(row[1], row[2]);
	Ellip e(cen, row[3], row[4]);
	int time = measureTime([&]() {
		e.drawEllipMidPoint();
		});
	cout << "Drawing ellipse by Midpoint tooks: " << time << " microseconds" << endl;
}

void ParabolaMidPoint(vector<int> row) {
	Point f(row[1], row[2]);
	Parabola p(f, row[3]);
	int time = measureTime([&]() {
		p.drawParaMidPoint();
		});
	cout << "Drawing parabola by Midpoint tooks: " << time << " microseconds" << endl;
}

void HyperbolaAssym(vector<int> row) {
	Point cen(row[1], row[2]);
	Hyperbola h(cen, row[3], row[4]);
	h.drawHyperAsym();
}

void HyperbolaMidPoint(vector<int> row) {
	Point cen(row[1], row[2]);
	Hyperbola h(cen, row[3], row[4]);
	int time = measureTime([&]() {
		h.drawHyperMidPoint();
		});
	cout << "Drawing hyperbola by Midpoint tooks: " << time << " microseconds" << endl;
}

// Open GL function
void LineOpenGL(vector<int> row) {

	Point p1(row[1], row[2]);
	Point p2(row[3], row[4]);
	Line l1(p1, p2);
	int time = measureTime([&]() {
		l1.draw();
		});
	cout << "Drawing line by Open GL function tooks: " << time << " microseconds" << endl;
}

void CircleOpenGL(vector<int> row) {
	Point center(row[1], row[2]);
	Circle c1(center, row[3]);
	int time = measureTime([&]() {
		c1.draw();
		});
	cout << "Drawing circle by Open GL function tooks: " << time << " microseconds" << endl;
}

void EllipseOpenGL(vector<int> row) {
	Point cen(row[1], row[2]);
	Ellip e(cen, row[3], row[4]);
	int time = measureTime([&]() {
		e.draw();
		});
	cout << "Drawing ellipse by Open GL function tooks: " << time << " microseconds" << endl;
}

void ParabolaOpenGL(vector<int> row) {
	Point f(row[1], row[2]);
	Parabola p(f, row[3]);
	int time = measureTime([&]() {
		p.draw();
		});
	cout << "Drawing parabola by Open GL function tooks: " << time << " microseconds" << endl;
}

void HyperbolaOpenGL(vector<int> row) {
	Point cen(row[1], row[2]);
	Hyperbola h(cen, row[3], row[4]);
	int time = measureTime([&]() {
		h.draw();
		});
	cout << "Drawing hyperbola by Open GL function tooks: " << time << " microseconds" << endl;
}

void generateDataRandom(int n) {
	ofstream file;
	file.open("data.txt");


	for (int i = 0; i < n; i++) {
		// random from 0 to 5
		int type = rand() % 6;
		switch (type)
		{
		case 0:
		case 1:
		{
			int x1 = rand() % 600;
			int y1 = rand() % 600;
			int x2 = rand() % 600;
			int y2 = rand() % 600;
			file << type << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
			break;
		}
		case 2:
		{
			int x = rand() % 600;
			int y = rand() % 600;
			int r = rand() % 100;
			file << type << " " << x << " " << y << " " << r << endl;
			break;
		}
		case 3:
		{
			int x = rand() % 600;
			int y = rand() % 600;
			int a = rand() % 100;
			int b = rand() % 100;
			file << type << " " << x << " " << y << " " << a << " " << b << endl;
			break;
		}
		case 4:
		{
			int x = rand() % 600;
			int y = rand() % 600;
			int p = rand() % 100;
			file << type << " " << x << " " << y << " " << p << endl;
			break;
		}
		case 5:
		{
			int x = rand() % 600;
			int y = rand() % 600;
			int a = rand() % 100;
			int b = rand() % 100;
			file << type << " " << x << " " << y << " " << a << " " << b << endl;
			break;
		}
		}
	}
	file.close();
}