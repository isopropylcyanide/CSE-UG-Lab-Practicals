#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

/* A program to perform 2d transformations on a figure from a file
Line 1: Coordinations of the given figure
Line 2: Translation of figure in three direction x, y, z
Line 3: Rotation of triangle in three directions x, y, x
Line 4: Scaling of triangle in x and y directions;
*/
typedef struct point{
    int x, y;
    point(){};
    point(int a, int b){
        x = a;
        y = b;
    }
}point;

typedef struct translation{
    int x, y;
    translation(){}
}translation;

typedef struct rotation{
    int angle, fixedX, fixedY;
}rotation;


typedef struct scale{
    float x, y;
    int fixedX, fixedY;
}scale;

typedef struct shear{
    float val;
    int shX, shY, axis;
}shear;


void plotTriangle(point a, point b, point c){
    //Given three coordinates plot the triangle resulting from them
    line(a.x, a.y, b.x, b.y);
    line(a.x, a.y, c.x, c.y);
    line(b.x, b.y, c.x, c.y);
}

point translatePoint(point a, translation t){
    return point(a.x + t.x, a.y + t.y);
}

point scalePoint(point a, scale s){
    return point(a.x * s.x + s.fixedY * (1 - s.x), a.y * s.y + s.fixedX*(1 - s.y));
}

point rotatePoint(point a, rotation r){
    r.angle = (M_PI * r.angle)/180;
    double x = r.fixedX + (a.x - r.fixedX)* cos(r.angle) - (a.y - r.fixedY) * sin(r.angle);
    double y = r.fixedY + (a.y - r.fixedY)* sin(r.angle) - (a.y - r.fixedY) * cos(r.angle);
    return point(x + a.x, y + a.y);
}

point applyShear(point a, shear h){
    if (h.axis == 1)
        return point(a.x + h.val * (a.y - h.shY), a.y);
    else
        return point(a.x, a.y + h.val * (a.x - h.shX));
}

int main(){
    int graphMode, graphDriver = DETECT;

    point a, b, c;
    translation t;
    rotation r;
    scale s;
    shear h;

    cout << "\n Enter coordinates of triangle: ";
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    cout << "\n Enter translation in x and y axis: ";
    cin >> t.x >> t.y;

    cout << "\n Enter angle of rotation as well as point: ";
    cin >> r.angle >> r.fixedX >> r.fixedY;

    cout << "\n Enter scaling factor in x and y and a point: ";
    cin >> s.x >> s.y >> s.fixedX >> s.fixedY ;

    cout << "\n Enter shear value, point and axis (x = 1 | y = 0): ";
    cin >> h.val >> h.shX >> h.shY >> h.axis;

    initgraph(&graphDriver, &graphMode, NULL);

    // Plot initial triangle
    plotTriangle(a, b, c);

    // Translate the triangle
    point transA = translatePoint(a, t);
    point transB = translatePoint(b, t);
    point transC = translatePoint(c, t);

    system("sleep 1");
    printf("\n\n\tTRANSLATED TRIANGLE\n");
    plotTriangle(transA, transB, transC);

    //Rotate the triangle
    point rotA = rotatePoint(a, r);
    point rotB = rotatePoint(b, r);
    point rotC = rotatePoint(c, r);

    system("sleep 1");
    cleardevice();
    printf("\n\n\tROTATED TRIANGLE\n");
    plotTriangle(a, b, c);
    plotTriangle(rotA, rotB, rotC);

    //Scale the triangle
    point scaleA = scalePoint(a, s);
    point scaleB = scalePoint(b, s);
    point scaleC = scalePoint(c, s);

    system("sleep 1");
    cleardevice();
    printf("\n\n\tSCALED TRIANGLE\n");
    plotTriangle(a, b, c);
    plotTriangle(scaleA, scaleB, scaleC);

    //Shear the triangle
    point shearA = applyShear(a, h);
    point shearB = applyShear(b, h);
    point shearC = applyShear(c, h);

    system("sleep 1");
    cleardevice();
    printf("\n\n\tSHEARED TRIANGLE\n");
    plotTriangle(a, b, c);
    plotTriangle(shearA, shearB, shearC);

    delay(10000);
    closegraph();
    return 0;
}
