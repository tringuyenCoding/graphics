// Name: Nguyen Dinh Ngoc Tri
// Student ID: 21125065
// Assignment: Lab 1 - Computer Graphics
// Date: 2021-09-20

#include "otherFunctions.h"

using namespace std;

vector<vector<int>> coor;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(3.0f);
	glPointSize(3.0f);

	for (int i = 0; i < coor.size();i++) {
		vector<int> row = coor[i];
		switch (row[0])
		{
		case 0:
			LineDDA(row);
			LineOpenGL(row);
			break;
		case 1:
			LineBresenham(row);
			LineOpenGL(row);
			break;
		case 2:
			CircleMidPoint(row);
			CircleOpenGL(row);
			break;
		case 3:
			EllipseMidPoint(row);
			EllipseOpenGL(row);
			break;
		case 4:
			ParabolaMidPoint(row);
			ParabolaOpenGL(row);
			break;
		case 5:
			HyperbolaAssym(row);
			HyperbolaMidPoint(row);
			HyperbolaOpenGL(row);
			break;
		}
	}

	glFlush();
}

int main(int argc, char* argv[]) {
	//generateDataRandom(10);
	coor = readInput("data.txt");
	
	glutInit(&argc, argv);
	
	glutInitWindowSize(800, 600);
	glutCreateWindow("Computer Graphics");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);

	glutDisplayFunc(display);

	SetupRC();

	glutMainLoop();
	cout << endl;
}
