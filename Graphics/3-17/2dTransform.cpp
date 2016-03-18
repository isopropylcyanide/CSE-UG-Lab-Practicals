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
    translation(int a, int b){
        x = a;
        y = b;
    }
}translation;

typedef struct rotation{
    int angle;
    rotation(){}
    rotation(int a, int b){
        angle = a;
    }
}rotation;

typedef struct scale{
    float x, y;
    scale(){}
    scale(float a, float b){
        x = a;
        y = b;
    }
}scale;

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
    return point(a.x * s.x, a.y * s.y);
}

point rotatePoint(point a, rotation r){
    double x = abs(a.x * cos(r.angle) - a.y * sin(r.angle));
    double y = abs(a.x * sin(r.angle) + a.y * cos(r.angle));
    return point(x, y);
}

int main(){
    int graphMode, graphDriver = DETECT;

    point a, b, c;
    translation t;
    rotation r;
    scale s;

    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    cin >> t.x >> t.y;
    cin >> r.angle;
    cin >> s.x >> s.y ;

    initgraph(&graphDriver, &graphMode, NULL);

    // Plot initial triangle
    plotTriangle(a, b, c);

    // Translate the triangle
    point transA = translatePoint(a, t);
    point transB = translatePoint(b, t);
    point transC = translatePoint(c, t);

    system("sleep 2");
    plotTriangle(transA, transB, transC);

    //Rotate the triangle
    point rotA = rotatePoint(a, r);
    point rotB = rotatePoint(b, r);
    point rotC = rotatePoint(c, r);

    system("sleep 2");
    plotTriangle(rotA, rotB, rotC);

    //Scale the triangle
    point scaleA = scalePoint(a, s);
    point scaleB = scalePoint(b, s);
    point scaleC = scalePoint(c, s);

    system("sleep 2");
    plotTriangle(scaleA, scaleB, scaleC);

    delay(10000);
    closegraph();
    return 0;
}
