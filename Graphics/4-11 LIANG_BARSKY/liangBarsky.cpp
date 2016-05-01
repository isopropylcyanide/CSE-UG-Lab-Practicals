#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

/* Algorithm for line clipping using Liang-Barsky algorithm.  Clip a line l given a boundary b*/

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
}Line;

float max(float a, float b){
    return a > b ?  a : b;
}
float min(float a, float b){
    return a < b ? a : b;
}

void liangBarsky_clipping(Boundary &b, Line &l){
    //Perform liang Barsky clipping for the given line and boundary
    rectangle(b.x_min, b.y_max, b.x_max, b.x_min);
    line(l.A.x, l.A.y, l.B.x, l.B.y);
    sleep(2);
    /*
    A) Parametric line equation for (x1, x2) and (y1, y2) as f(t)
        x(t) = x1 + t(x2 - x1) and y(t) = y1 + t(y2 - y1)
        b.xmin <= x <= b.xmax  and  b.ymin <= y <= b.ymax
        b.xmin <= x1 + t(dx) <= b.xmax
        b.ymin <= y1 + t(dy) <= b.ymax
            OR
        -t(dx) <= x1 - b.xmin
        t(dx)  <= b.xmax - x1
        -t(dy) <= y1 - b.ymin
        t(dy)  <= b.ymax - y1

        t(p(k)) <= q(k) where k = 1, 2, 3, 4.. Rearranging,
        p1 = -dx, q1 = x1 - b.xmin
        p2 = dx , q2 = b.xmax - x1
        p3 = -dy, q3 = y1 - b.ymin
        p4 = dy,  q4 = b.ymax - y1

    B) Assign t1 = 0, t2 = 1
        if p(k) (i.e dx or dy) == 0: then line is || to boundary
        if q(k) < 0, discard line as it is outside
        if p(k) != 0:
            if p(k) < 0: partially in. Find st1rting point t1 = max(0, q(k)/p(k))
            else: Find t2 (ending point) = min(1, q(k)/p(k))
        if t1 > t2: reject
        else: find new set of (x, y)
            x = x1 + t(dx) and y = y1 + t(dy)
    */
    int dx = l.B.x - l.A.x, dy = l.B.y - l.A.y;
    vector<int> P {-dx, dx, -dy, dy};
    vector<int> Q {l.A.x - b.x_min, b.x_max - l.A.x, l.A.y - b.y_min, b.y_max - l.A.y};

    for (int i = 0; i < P.size(); i++)
        cout << "\n P["<<i<<"] : " << P[i] << " and Q["<<i<<"] : " << Q[i] << " Q/P: " << (Q[i] * 1.0)/P[i];
    cout << endl;

    float t1 = 0.0, t2 = 1.0;
    for (int k = 0; k < P.size(); k++){
        if (P[k] == 0 && Q[k] < 0){
            cout << "\n Line is outside of clipping window. Rejecting Line\n";
            return;
        }
        if (P[k] < 0)
            t1 = max(t1, (Q[k] * 1.0)/P[k]);
        else
            t2 = min(t2, (Q[k] * 1.0)/P[k]);
    }
    cout << "\n t1: " << t1 << endl;
    cout << "\n t2: " << t2 << endl;

    if (t1 > t2){ //reject line
        cout << "\n Line is completely outside the window. Rejecting line";
        return;
    }

    Point newA(l.A.x + t1 * dx, l.A.y + t1 * dy);
    Point newB(l.A.x + t2 * dx, l.A.y + t2 * dy);
    Line clippedLine = {newA, newB};

    fprintf(stdout, "\n New x1: (%d, %d)", newA.x, newA.y);
    fprintf(stdout, "\n New x2: (%d, %d)", newB.x, newB.y);
    fprintf(stdout, "\n Clipped line: %s" ,clippedLine.lineStatus().c_str());

    cleardevice();
    rectangle(b.x_min, b.y_max, b.x_max, b.x_min);
    line(clippedLine.A.x, clippedLine.A.y, clippedLine.B.x, clippedLine.B.y);
    cout << "\n CLIPPING FINISHED";
}

int main(){
    Boundary b = {100, 250, 100, 300};
    Line l = {Point(50, 200), Point(350, 300)};

    /*Graph initialisations*/
    int graphMode, graphDriver = DETECT;
    initgraph(&graphDriver, &graphMode, NULL);
    setbkcolor(WHITE);
    setcolor(BLACK);
    setfontcolor(BLACK);
    /**/

    liangBarsky_clipping(b, l);

    delay(100000);
    closegraph();

    return 0;
}
