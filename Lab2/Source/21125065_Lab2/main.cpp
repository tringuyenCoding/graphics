#include "library.h"
#include "circle.h"
#include "point.h"
#include "rgbcolor.h"
#include "ellip.h"
#include "line.h"
#include "polygon.h"
using namespace std;

#define h 700
#define w 1200

RGBColor fillColor(255, 0, 255);  // Purble color
RGBColor borderColor(0, 0, 0);  // Black color

Point seedPoint(-1, -1);
Poly po;
Circle c;
Ellip e;



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

void PutPixel(int x, int y, const RGBColor& color) {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

RGBColor GetPixel(int x, int y) {
    unsigned char pixel[3];
    glReadPixels(x,y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pixel);

    RGBColor color(pixel[0], pixel[1], pixel[2]);
    return color;
}

bool IsSameColor(const RGBColor& current, const RGBColor& newColor) {
    return (current.r == newColor.r && current.g == newColor.g && current.b == newColor.b);
}

bool check(int x, int y) {
    if (x < 0 || x > w || y < 0 || y > h) {
		return false;
	}
	return true;
}

void BoundaryFill(int x, int y, const RGBColor& F_Color, const RGBColor& B_Color) {
    
    stack<Point> points;
    points.push(Point(x, y));
    while (!points.empty()) {
        Point currentPoint = points.top();
        points.pop();
        int x_p = currentPoint.getX();
        int y_p = currentPoint.getY();

        RGBColor currentColor = GetPixel(x_p, y_p);
        if (!IsSameColor(GetPixel(x_p, y_p), B_Color) && !IsSameColor(GetPixel(x_p, y_p), F_Color) &&
            !IsSameColor(GetPixel(x_p-1, y_p),B_Color) && !IsSameColor(GetPixel(x_p, y_p-1),B_Color) &&
            !IsSameColor(GetPixel(x_p+1, y_p),B_Color) && !IsSameColor(GetPixel(x_p, y_p+1),B_Color)) {
            PutPixel(x_p, y_p, F_Color);
            
            points.push(Point(x_p + 2, y_p));
            points.push(Point(x_p - 2, y_p));
            points.push(Point(x_p, y_p + 2));
            points.push(Point(x_p, y_p - 2));
        }
    
    }
}

void SetupRC() {
    glClearColor(0.8f, 1.0f, 0.8f, 1.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    glLineWidth(3.0f);
    glPointSize(3.0f);

    glFlush();
}

void context_menu(int id) {
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    

    if (id == 1) {
        cout<<"Line"<<endl;
        Line l(Point(mouseX, mouseY), Point(mouseX+100, mouseY+100));
        l.draw(); 
        cMouse = 0;
        idn = -1;
        cdraw = false;
    }
    

    glFlush();
}

void tria_menu(int id) {
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    switch (id)
    {
    case 2:
    {
        cout << "Isosceles triangle" << endl;
        vector<Point> ver1 = { Point(mouseX, mouseY), Point(mouseX+100, mouseY+100), Point(mouseX +200, mouseY) };
        po.setVertices(ver1);
        po.draw();
        cdraw = true;

        break;
    }
    case 3:
    {
        cout << "Right angled triangle" << endl;
        vector<Point> ver2 = { Point(mouseX, mouseY), Point(mouseX, mouseY+100), Point(mouseX+100, mouseY) };
        po.setVertices(ver2);
        po.draw();
        cdraw = true;

        break;
    }
    case 4:
    {
        cout << "Equilateral triangle" << endl;
        vector<Point> ver3 = { Point(mouseX, mouseY), Point(mouseX+100, mouseY), Point(mouseX+50, mouseY+100) };
        po.setVertices(ver3);
        po.draw();
        cdraw = true;

        break;
    }
    default:
        break;
    }
    glFlush();
}

void quad_menu(int id) {
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    switch (id)
    {
        case 5:
        {
            cout << "Square" << endl;
            vector<Point> verS = { Point(mouseX, mouseY), Point(mouseX+100, mouseY), Point(mouseX + 100, mouseY+100), Point(mouseX, mouseY+100) };
            po.setVertices(verS);
            po.draw();
            cdraw = true;

            break;
        }
        case 6:
        {
            cout << "Rectangle" << endl;
            vector<Point> verR = { Point(mouseX, mouseY), Point(mouseX+50, mouseY), Point(mouseX+50, mouseY+100), Point(mouseX, mouseY+100) };
            po.setVertices(verR);
            po.draw();
            cdraw = true;

            break;
        }
        default:
                break;
    }
    glFlush();
}

void oval_menu(int id) {
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    switch (id)
    {
        case 7:
        {
            cout << "Circle" << endl;
            c.setAttributes(Point(mouseX, mouseY), 100);
            c.draw();
            cdraw = true;

            break;
        }
        case 8:
        {
            cout << "Ellipse" << endl;
            e.setAttributes(Point(mouseX, mouseY), 100, 50);
            e.draw();
            cdraw = true;

            break;
        }
    default:
        break;
    }
    glFlush();
}

void poly_menu(int id) {
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    switch (id)
    {
    case 9:
    {
        cout << "Pentagon" << endl;
        vector<Point> vertices = {Point(mouseX, mouseY), Point(mouseX+100, mouseY), Point(mouseX+150, mouseY+100), Point(mouseX+50, mouseY+200), Point(mouseX-50, mouseY+100)};
        po.setVertices(vertices);
        po.draw();
        cdraw = true;

        break;
    }
    case 10:
    {
        cout << "Hexagon" << endl;
        vector<Point> vertices1 = {Point(mouseX, mouseY), Point(mouseX+100, mouseY), Point(mouseX+150, mouseY+100), Point(mouseX+100, mouseY+200), Point(mouseX, mouseY+200), Point(mouseX-50, mouseY+100)};
        po.setVertices(vertices1);
        po.draw();
        cdraw = true;

        break;
    }
    default:
		break;
	}
    glFlush();
}

void othshap_menu(int id) {
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    switch (id)
    {
    case 11:
    {
        cout << "Star" << endl;
        vector<Point> vertices2 = { Point(mouseX, mouseY), Point(mouseX - 40, mouseY - 100), Point(mouseX - 160, mouseY - 100), Point(mouseX - 60, mouseY - 150), Point(mouseX - 100, mouseY - 250), Point(mouseX, mouseY - 200), Point(mouseX + 80, mouseY - 250), Point(mouseX + 60, mouseY - 150), Point(mouseX + 140, mouseY - 100), Point(mouseX + 40, mouseY - 100)};
        //{Point(260, 450), Point(220, 350), Point(100, 350), Point(200, 300), Point(160, 200), Point(260, 250), Point(340, 200), Point(320, 300), Point(400, 350), Point(300, 350)};
        po.setVertices(vertices2);
        po.draw();
        cdraw = true;

        break;
    }   
    case 12:
    {
        cout << "Arrow" << endl;
        vector<Point> vertices3 = {Point(mouseX, mouseY), Point(mouseX, mouseY+50), Point(mouseX+200, mouseY+50), Point(mouseX+200,mouseY+70) ,Point(mouseX + 400, mouseY+25), Point(mouseX + 200, mouseY-20), Point(mouseX + 200,mouseY)};
        po.setVertices(vertices3);
        po.draw();
        cdraw = true;

        break;
    }default:
        break;
    }
    glFlush();
}

void oper_menu(int id) {
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(borderColor.r, borderColor.g, borderColor.b);
    switch (id)
    {
    case 13:
    {
        cout << "Plus" << endl;
        vector<Point> vertices4 = { Point(mouseX, mouseY), Point(mouseX, mouseY+50), Point(mouseX+50, mouseY + 50), Point(mouseX+50,mouseY + 100) ,Point(mouseX+100, mouseY + 100), Point(mouseX+100, mouseY + 50), Point(mouseX + 150,mouseY + 50), Point(mouseX + 150,mouseY), Point(mouseX + 100,mouseY), Point(mouseX + 100,mouseY - 50), Point(mouseX + 50,mouseY - 50), Point(mouseX+50,mouseY) };
        po.setVertices(vertices4);
        po.draw();
        cdraw = true;

        break;
    }
    case 14:
    {
        cout << "Minus" << endl;
        vector<Point> vertices5 = { Point(mouseX, mouseY), Point(mouseX, mouseY+50), Point(mouseX+200, mouseY+50), Point(mouseX+200,mouseY)};
        po.setVertices(vertices5);
        po.draw();
        cdraw = true;

        break;
    }
    case 15:
    {
        cout << "Multiply" << endl;
        vector<Point> vertices6 = { Point(mouseX, mouseY), Point(mouseX-50, mouseY+50), Point(mouseX+50, mouseY+150), Point(mouseX-50,mouseY+250) ,Point(mouseX, mouseY+300), Point(mouseX+100, mouseY +200 ), Point(mouseX+200,mouseY+300), Point(mouseX+250,mouseY+250), Point(mouseX+150,mouseY+150), Point(mouseX+250,mouseY+50), Point(mouseX+200,mouseY), Point(mouseX+100,mouseY+100) };
        po.setVertices(vertices6);
        po.draw();
        cdraw = true;

        break;
    }
    case 16:
    {
        cout << "Divide" << endl;
        vector<Point> vertices7 = { Point(mouseX, mouseY), Point(mouseX-25, mouseY+25), Point(mouseX+50, mouseY+100), Point(mouseX+75,mouseY+75) };
        po.setVertices(vertices7);
        po.draw();
        cdraw = true;

        break;
    }
    default:
        break;
    }
    glFlush();
}

void color_menu(int id) {
    switch (id)
    {
        case 17:
			cout<<"Green"<<endl;
            fillColor.SetColor(0, 255, 0);
			break;
        case 18:
			cout<<"Red"<<endl;
            fillColor.SetColor(255, 0, 0);
			break;
        case 19:
            cout<<"Yellow"<<endl;
            fillColor.SetColor(255, 255, 0);
            break;
    default:
        break;
    }
}

// coloring this shape using seed point selected by clicking inside the polygon
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        seedPoint.setX(x);
        seedPoint.setY(h-y);

        mouseX = x;
        mouseY = h-y;
        cMouse += 1;
        cout << cMouse;

        if (cbor) {
            context_menu(idn);
            tria_menu(idn);
            quad_menu(idn);
            oval_menu(idn);
            poly_menu(idn);
            othshap_menu(idn);
            oper_menu(idn);
            color_menu(idn);
           
        }
        

        if (!cbor) {
                BoundaryFill(seedPoint.getX(), seedPoint.getY(), fillColor, borderColor);
                
        }
        cbor = false;

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
void ovl(int id) {
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

void color(int id) {
	idn = id;
    cbor = true;
}

void display_menu() {
    int sub_triangle = glutCreateMenu(tria);
    glutAddMenuEntry("Isosceles triangle", 2);
    glutAddMenuEntry("Right angled triangle", 3);
    glutAddMenuEntry("Equilateral triangle", 4);
    
    int sub_quad = glutCreateMenu(quad);
    glutAddMenuEntry("Square", 5);
    glutAddMenuEntry("Rectangle", 6);

    int sub_oval = glutCreateMenu(ovl);
    glutAddMenuEntry("Circle", 7);
    glutAddMenuEntry("Ellipse", 8);

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

    int sub_color = glutCreateMenu(color);
    glutAddMenuEntry("Green", 17);
    glutAddMenuEntry("Red", 18);
    glutAddMenuEntry("Yellow", 19);

    glutCreateMenu(context);
    glutAddMenuEntry("Line", 1);
    glutAddSubMenu("Triangle", sub_triangle);
    glutAddSubMenu("Quadrilateral", sub_quad);
    glutAddSubMenu("Oval", sub_oval);
    glutAddSubMenu("Polygon", sub_poly);
    glutAddSubMenu("Other shape", sub_othshap);
    glutAddSubMenu("Operation", sub_oper);
    glutAddSubMenu("Color", sub_color);
    glutAddMenuEntry("Clear", 20);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(w, h);
    glutCreateWindow("Boundary Fill Circle");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    display_menu();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    SetupRC();

    glutMainLoop();

    return 0;
}