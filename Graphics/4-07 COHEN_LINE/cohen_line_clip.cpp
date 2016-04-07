#include <bits/stdc++.h>
#include <graphics.h>
#define bitCode int
using namespace std;

/* Algorithm for line clipping using cohen sutherland algorithm.  Clip a line l given a boundary b*/

//Set Positions to mark a point as inside or outside
#define INSIDE 0    //0000
#define LEFT 1      //0001
#define RIGHT 2     //0010
#define BOTTOM 4    //0100
#define TOP 8       //1000

typedef struct Boundary{
    int x_min, x_max, y_min, y_max;
}Boundary;

typedef struct Point{
    int x, y;
    Point (){}
    Point(int a, int b) : x(a), y(b){}
}Point;

typedef struct Line{
    Point A, B;
    string lineStatus(){
        return "(" + to_string(A.x)  + "," + to_string(A.y) + ") to (" + to_string(B.x) + "," + to_string(B.y) + ")\n";
    }
    friend ostream & operator <<(ostream &c, Line &l){
        cout << "(" << l.A.x <<"," << l.A.y <<") to (" << l.B.x << "," << l.B.y << ")\n";
        return c;
    }
}Line;


int getBitCode(Point p, Boundary &b){
    //Compute bitcodes for the given point depending on where the point lies wrt boundary
    int curBit = INSIDE;

    if (p.x < b.x_min)
        curBit |= LEFT;
    if (p.x > b.x_max)
        curBit |= RIGHT;
    if (p.y < b.y_min)
        curBit |= BOTTOM;
    if (p.y > b.y_max)
        curBit |= TOP;

    return curBit;
}

void showClipping_Line(Line &l, Boundary &b, string &message){
    rectangle(b.x_min, b.y_max, b.x_max, b.x_min);
    line(l.A.x, l.A.y, l.B.x, l.B.y);
    printf("\t %s ", message.c_str());
    sleep(2);
    cleardevice();
}

void cohenSuther_clipping(Boundary &b, Line &l){
    //Compute bitcodes of two points of the given line and take decisions accordigly
    cout << "\n Initial line : " << l;

    string message = " INITIAL LINE " + l.lineStatus();
    showClipping_Line(l, b, message);

    bitCode bitA = getBitCode(l.A, b);
    bitCode bitB = getBitCode(l.B, b);
    cout << "\n BitA: " << bitA;
    cout << "\n BitB: " << bitB;

    bool accept = false;
    while (true){
        cout << "\n\n Current Line : " << l;
        if (!(bitA | bitB)){ //line is completely inside
            message = " Line is completely inside ";
            accept = true;
            break;
        }

        if (bitA & bitB){   //line lies outside the boundary
            message = " Line is completely outside ";
            accept = false;
            break;
        }

        //Now line has some intersection with the boundary. Either one or both points
        //maybe outside. Clip the line from outside to the intersection
        message = " Some part of line is inside ";

        Point intersection;
        double slope = (l.B.y - l.A.y * 1.0)/( l.B.x - l.A.x);
        bitCode anyOuterPoint = bitA ? bitA : bitB; //Any point which is outside

        if (anyOuterPoint & TOP){ //then point is above boundary
            intersection.y = b.y_max;
            intersection.x = l.A.x + (intersection.y - l.A.y)/slope;
        }

        else if (anyOuterPoint & BOTTOM){ //point is below boundary
            intersection.y = b.y_min;
            intersection.x = l.A.x + (intersection.y - l.A.y)/slope;
        }

        else if (anyOuterPoint & LEFT){ //point is left to the boundary
            intersection.x = b.x_min;
            intersection.y = l.A.y + slope*(intersection.x - l.A.x);
        }

        else if (anyOuterPoint & RIGHT){ //point is right to the boundary
            intersection.x = b.x_max;
            intersection.y = l.A.y + slope*(intersection.x - l.A.x);
        }

        // Now we move outside point to intersection point to clip
		// and get ready for next pass.
        if (anyOuterPoint == bitA){
            l.A.x = intersection.x;
            l.A.y = intersection.y;
            bitA = getBitCode(l.A, b);
        }
        else{
            l.B.x = intersection.x;
            l.B.y = intersection.y;
            bitB = getBitCode(l.B, b);
        }
        cout << " New line: " << l;
        message.append(l.lineStatus());
        showClipping_Line(l, b, message);
    }

    if (accept){
        cout << "\n The line is accepted";
        message.append(" Final Clipping " + l.lineStatus());
        showClipping_Line(l, b, message);
    }
}

int main(){
    Boundary b = {100, 300, 100, 400};
    Line l = {Point(50, 200), Point(450, 100)};

    /*Graph initialisations*/
    int graphMode, graphDriver = DETECT;
    initgraph(&graphDriver, &graphMode, NULL);
    setbkcolor(WHITE);
    setcolor(BLACK);
    setfontcolor(BLACK);
    /**/

    cohenSuther_clipping(b, l);

    delay(100000);
    closegraph();

    return 0;
}
