#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

/*A program to implement cubic Bezier curves.
  degree = 3. So number of control points : 4
  Input : Four Control Points
  Output: Bezier curves
*/
typedef struct Point{
    int x, y;
    Point(){}
    Point(int a, int b) : x(a), y(b){}
    friend ostream & operator << (ostream &c, Point &a){
        c << " Point : (" << a.x << ", " << a.y << ")";
        return c;
    }
    void operator =(Point c){
        x = c.x, y = c.y;
    }
}Point;


class Cubic_Bezier{
    //A class that represents a cubic bezier curve
    // f(t) = (1 - t)^3 * a + 3(1 - t)^2 * t * b + 3*(1 - t)*t*t*c + t^3 * d
    Point a, b, c, d;
    int graphMode, graphDriver = DETECT;

    Point func(double t){
        //Given a parametric t, find the new coordinates from the equation

        double x = pow(1 - t, 3) * a.x + 3 * pow(1 - t, 2) * t * b.x +
                    3 * (1 - t) * t * t * c.x + pow(t, 3) * d.x;
        double y = pow(1 - t, 3) * a.y + 3 * pow(1 - t, 2) * t * b.y +
                    3 * (1 - t) * t * t * c.y + pow(t, 3) * d.y;
        return Point(x, y);
    }

    public:
        Cubic_Bezier(Point &pA, Point &pB, Point &pC, Point &pD){
            //Initialize the graphic utilities annd control points
            a = pA, b = pB, c = pC, d = pD;
            initgraph(&graphDriver, &graphMode, NULL);
            setcolor(RED);
            setbkcolor(LIGHTGRAY);
        }

        ~Cubic_Bezier(){
            delay(10000);
            closegraph();
        }

        void draw_Curve(){
            //Draws the Bezier curve
            // Plot Control points in red (filled preferably):
            circle(a.x, a.y, 4); floodfill(a.x, a.y, RED);
            circle(b.x, b.y, 4); floodfill(b.x, b.y, RED);
            circle(c.x, c.y, 4); floodfill(c.x, c.y, RED);
            circle(d.x, d.y, 4); floodfill(d.x, d.y, RED);

            int iter = 0;
            for (double t = 0.0; t <= 1; iter++, t += 0.00005){
                Point newP = func(t);
                if (iter % 2000 == 0) //view any 10 iterations
                    cout << "\n f(" << t << "): " << newP;
                putpixel(newP.x, newP.y, BLACK);
            }
        }
};

int main(){
    Point A, B, C, D;
    cout << "\n CUBIC BEZIER CURVES (4 CONTROL POINTS)\n";
    cout << "\n ENTER FOUR X VALUES: \t";
    cin >> A.x >> B.x >> C.x >> D.x;
    cout << "\n ENTER FOUR Y VALUES: \t";
    cin >> A.y >> B.y >> C.y >> D.y;
    // Point A(220, 230);
    // Point B(200, 350);
    // Point C(110, 220);
    // Point D(320, 210);

    Cubic_Bezier cb(A, B, C, D);
    cb.draw_Curve();

    return 0;
}
