#include "library.h"
#include "point.h"
#include "rgbcolor.h"
#include "line.h"
#include "polygon.h"
using namespace std;

#define h 700
#define w 1200
RGBColor borderColor(0, 0, 0);  // Black color

Point seedPoint(-1, -1);
Poly po;
vector<Point> ver;
bool transformationsApplied = false;

float translationX = 0.0f;
float translationY = 0.0f;
float rotationAngle = 0.0f;
float scale = 1.0f;


int mouseX, mouseY;
int cMouse = 0;
int idn = -1;
bool cdraw = false;
bool cbor = false;

Point getCenterPoint(int x1, int y1, int x2, int y2) {
    int centerX = (int)(x1 + x2) / 2;
    int centerY = (int)(y1 + y2) / 2;
    return Point(centerX, centerY);
}

Point getTriangleCenter(Point p1, Point p2, Point p3) {
    int centerX = (p1.getX() + p2.getX() + p3.getX()) / 3.0;
    int centerY = (p1.getY() + p2.getY() + p3.getY()) / 3.0;
    return Point(centerX, centerY);
}

Point getPolyCenter(vector<Point> vertices) {
	int centerX = 0;
	int centerY = 0;
    for (int i = 0; i < vertices.size(); i++) {
		centerX += vertices[i].getX();
		centerY += vertices[i].getY();
	}
	centerX /= vertices.size();
	centerY /= vertices.size();
	return Point(centerX, centerY);
}

void handleKeys(unsigned char key, int x, int y) {
    switch (key) {
    case 'l':
        cout << "l" << endl;
        po.rotate(-1.0f);
        transformationsApplied = true;
        break;
    case 'r':
        cout << "r" << endl;
        po.rotate(1.0f);
        transformationsApplied = true;
        break;
    case '+':
        cout << "+" << endl;
        po.scale(1.1f);
        transformationsApplied = true;
        break;
    case '-':
        cout << "-" << endl;
        po.scale(0.9f);
        transformationsApplied = true;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        cout<< "UP" << endl;
        po.translate(0.0f, 1.0f);
        transformationsApplied = true;
        break;
    case GLUT_KEY_DOWN:
        cout << "DOWN" << endl;
        po.translate(0.0f, -1.0f);
        transformationsApplied = true;
        break;
    case GLUT_KEY_LEFT:
        cout << "LEFT" << endl;
        po.translate(-1.0f, 0.0f);
        transformationsApplied = true;
        break;
    case GLUT_KEY_RIGHT:
        cout << "RIGHT" << endl;
        po.translate(1.0f, 0.0f);
        transformationsApplied = true;
        break;
    default:
        break;
    }
    glutPostRedisplay();
    
}

void PutPixel(int x, int y, const RGBColor& color) {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void SetupRC() {
    glClearColor(0.8f, 1.0f, 0.8f, 1.0f);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    glLineWidth(3.0f);
    glPointSize(3.0f);

    if (transformationsApplied) {
        po.draw();  
        transformationsApplied = false;
    }
    else {
        po.draw();
    }

    glFlush();
}



void context_menu(int id) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    

    if (id == 1) {
        cout<<"Line"<<endl;
        ver = { Point(mouseX, mouseY), Point(mouseX + 100, mouseY + 100) };
        po.setVertices(ver);
        po.draw(); 
        cMouse = 0;
        idn = -1;
        cdraw = false;
    }
    

    glFlush();
}

void tria_menu(int id) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    switch (id)
    {
    case 2:
    {
        cout << "Isosceles triangle" << endl;
        ver = { Point(mouseX, mouseY), Point(mouseX+100, mouseY+100), Point(mouseX +200, mouseY) };
        po.setVertices(ver);
        po.draw();
        ver.clear();
        cdraw = true;

        break;
    }
    case 3:
    {
        cout << "Right angled triangle" << endl;
        ver = { Point(mouseX, mouseY), Point(mouseX, mouseY+100), Point(mouseX+100, mouseY) };
        po.setVertices(ver);
        po.draw();
        ver.clear();
        cdraw = true;

        break;
    }
    case 4:
    {
        cout << "Equilateral triangle" << endl;
        ver = { Point(mouseX, mouseY), Point(mouseX+100, mouseY), Point(mouseX+50, mouseY+100) };
        po.setVertices(ver);
        po.draw();
        ver.clear();
        cdraw = true;

        break;
    }
    default:
        break;
    }
    glFlush();
}

void quad_menu(int id) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    switch (id)
    {
        case 5:
        {
            cout << "Square" << endl;
            ver = { Point(mouseX, mouseY), Point(mouseX+100, mouseY), Point(mouseX + 100, mouseY+100), Point(mouseX, mouseY+100) };
            po.setVertices(ver);
            po.draw();
            ver.clear();
            cdraw = true;

            break;
        }
        case 6:
        {
            cout << "Rectangle" << endl;
            ver = { Point(mouseX, mouseY), Point(mouseX+50, mouseY), Point(mouseX+50, mouseY+100), Point(mouseX, mouseY+100) };
            po.setVertices(ver);
            po.draw();
            ver.clear();
            cdraw = true;

            break;
        }
        default:
                break;
    }
    glFlush();
}

void poly_menu(int id) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    switch (id)
    {
    case 9:
    {
        cout << "Pentagon" << endl;
        ver= {Point(mouseX, mouseY), Point(mouseX+100, mouseY), Point(mouseX+150, mouseY+100), Point(mouseX+50, mouseY+200), Point(mouseX-50, mouseY+100)};
        po.setVertices(ver);
        po.draw();
        ver.clear();
        cdraw = true;

        break;
    }
    case 10:
    {
        cout << "Hexagon" << endl;
        ver = {Point(mouseX, mouseY), Point(mouseX+100, mouseY), Point(mouseX+150, mouseY+100), Point(mouseX+100, mouseY+200), Point(mouseX, mouseY+200), Point(mouseX-50, mouseY+100)};
        po.setVertices(ver);
        po.draw();
        ver.clear();
        cdraw = true;

        break;
    }
    default:
		break;
	}
    glFlush();
}

void othshap_menu(int id) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    switch (id)
    {
    case 11:
    {
        cout << "Star" << endl;
        ver = { Point(mouseX, mouseY), Point(mouseX - 40, mouseY - 100), Point(mouseX - 160, mouseY - 100), Point(mouseX - 60, mouseY - 150), Point(mouseX - 100, mouseY - 250), Point(mouseX, mouseY - 200), Point(mouseX + 80, mouseY - 250), Point(mouseX + 60, mouseY - 150), Point(mouseX + 140, mouseY - 100), Point(mouseX + 40, mouseY - 100)};
        po.setVertices(ver);
        po.draw();
        ver.clear();
        cdraw = true;

        break;
    }   
    case 12:
    {
        cout << "Arrow" << endl;
        ver = {Point(mouseX, mouseY), Point(mouseX, mouseY+50), Point(mouseX+200, mouseY+50), Point(mouseX+200,mouseY+70) ,Point(mouseX + 400, mouseY+25), Point(mouseX + 200, mouseY-20), Point(mouseX + 200,mouseY)};
        po.setVertices(ver);
        po.draw();
        ver.clear();
        cdraw = true;

        break;
    }default:
        break;
    }
    glFlush();
}

void oper_menu(int id) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    switch (id)
    {
    case 13:
    {
        cout << "Plus" << endl;
        ver = { Point(mouseX, mouseY), Point(mouseX, mouseY+50), Point(mouseX+50, mouseY + 50), Point(mouseX+50,mouseY + 100) ,Point(mouseX+100, mouseY + 100), Point(mouseX+100, mouseY + 50), Point(mouseX + 150,mouseY + 50), Point(mouseX + 150,mouseY), Point(mouseX + 100,mouseY), Point(mouseX + 100,mouseY - 50), Point(mouseX + 50,mouseY - 50), Point(mouseX+50,mouseY) };
        po.setVertices(ver);
        po.draw();
        ver.clear();
        cdraw = true;

        break;
    }
    case 14:
    {
        cout << "Minus" << endl;
        ver = { Point(mouseX, mouseY), Point(mouseX, mouseY+50), Point(mouseX+200, mouseY+50), Point(mouseX+200,mouseY)};
        po.setVertices(ver);
        po.draw();
        ver.clear();
        cdraw = true;

        break;
    }
    case 15:
    {
        cout << "Multiply" << endl;
        ver = { Point(mouseX, mouseY), Point(mouseX-50, mouseY+50), Point(mouseX+50, mouseY+150), Point(mouseX-50,mouseY+250) ,Point(mouseX, mouseY+300), Point(mouseX+100, mouseY +200 ), Point(mouseX+200,mouseY+300), Point(mouseX+250,mouseY+250), Point(mouseX+150,mouseY+150), Point(mouseX+250,mouseY+50), Point(mouseX+200,mouseY), Point(mouseX+100,mouseY+100) };
        po.setVertices(ver);
        po.draw();
        ver.clear();
        cdraw = true;

        break;
    }
    case 16:
    {
        cout << "Divide" << endl;
        ver = { Point(mouseX, mouseY), Point(mouseX-25, mouseY+25), Point(mouseX+50, mouseY+100), Point(mouseX+75,mouseY+75) };
        po.setVertices(ver);
        po.draw();
        ver.clear();
        cdraw = true;

        break;
    }
    default:
        break;
    }
    glFlush();
}

// coloring this shape using seed point selected by clicking inside the polygon
void mouse(int button, int state, int x, int y) {
    if (cbor) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            seedPoint.setX(x);
            seedPoint.setY(h-y);

            mouseX = x;
            mouseY = h-y;
            cMouse += 1;
            cout << cMouse;

            context_menu(idn);
            tria_menu(idn);
            quad_menu(idn);
            poly_menu(idn);
            othshap_menu(idn);
            oper_menu(idn);

            cbor = false;
	    }
    }
    else {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            cout<< x << " " << h - y << endl;
            PutPixel(x, h - y, borderColor);
            ver.push_back(Point(x, h - y));
        }else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        {   
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(borderColor.r, borderColor.g, borderColor.b);
            PutPixel(x, h - y, borderColor);
            ver.push_back(Point(x, h - y));
            cout << "Manually" << endl;
            for (int i = 0; i < ver.size(); i++)
            {
				cout << ver[i].getX() << " " << ver[i].getY() << endl;
			}
			po.setVertices(ver);
			po.draw();

            ver.clear();
            glFlush();
        }
    }
}
void context(int id) {
    idn = id;
    if (id == 20) {
        cout << "Clear" << endl;
        display();
        glFlush();
        cMouse = 0;
        cdraw = false;
        idn = -1;
    }
    cbor = true;

}

void tria(int id) {
    idn = id;
    cbor = true;
}

void quad(int id) {
	idn = id;
    cbor = true;

}
void poly(int id) {
	idn = id;
    cbor = true;

}

void othshap(int id) {
	idn = id;
    cbor = true;

}

void oper(int id) {
	idn = id;
    cbor = true;

}

void color_menu(int id) {
    switch (id)
    {
    case 17:
        cout << "Green" << endl;
        borderColor.SetColor(0, 255, 0);
        break;
    case 18:
        cout << "Red" << endl;
        borderColor.SetColor(255, 0, 0);
        break;
    case 19:
        cout << "Yellow" << endl;
        borderColor.SetColor(255, 255, 0);
        break;
    default:
        break;
    }
}

void display_menu() {
    int sub_triangle = glutCreateMenu(tria);
    glutAddMenuEntry("Isosceles triangle", 2);
    glutAddMenuEntry("Right angled triangle", 3);
    glutAddMenuEntry("Equilateral triangle", 4);
    
    int sub_quad = glutCreateMenu(quad);
    glutAddMenuEntry("Square", 5);
    glutAddMenuEntry("Rectangle", 6);

    int sub_poly = glutCreateMenu(poly);
    glutAddMenuEntry("Pentagon", 9);
    glutAddMenuEntry("Hexagon", 10);

    int sub_othshap = glutCreateMenu(othshap);
    glutAddMenuEntry("Star", 11);
    glutAddMenuEntry("Arrow", 12);

    int sub_oper = glutCreateMenu(oper);
    glutAddMenuEntry("Plus", 13);
    glutAddMenuEntry("Minus", 14);
    glutAddMenuEntry("Multiply", 15);
    glutAddMenuEntry("Divide", 16);

    int sub_color = glutCreateMenu(color_menu);
    glutAddMenuEntry("Green", 17);
    glutAddMenuEntry("Red", 18);
    glutAddMenuEntry("Yellow", 19);

    glutCreateMenu(context);
    glutAddMenuEntry("Line", 1);
    glutAddSubMenu("Triangle", sub_triangle);
    glutAddSubMenu("Quadrilateral", sub_quad);
    glutAddSubMenu("Polygon", sub_poly);
    glutAddSubMenu("Other shape", sub_othshap);
    glutAddSubMenu("Operation", sub_oper);
    glutAddSubMenu("color", sub_color);
    glutAddMenuEntry("Clear", 20);

    glutAttachMenu(GLUT_MIDDLE_BUTTON);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(w, h);
    glutCreateWindow("Transforms");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    display_menu();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(handleKeys);
    glutSpecialFunc(specialKeys);

    SetupRC();

    glutMainLoop();

    return 0;
}