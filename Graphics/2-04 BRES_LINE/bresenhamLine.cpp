#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

typedef struct point{
    int x, y;
    point(){}
    point(int x1, int y1){
        x = x1;
        y = y1;
    }
    friend ostream & operator<<(ostream &c, point &a){
        c << "(" << a.x <<"," << a.y <<") ";
        return c;
    }
    bool operator<(point b){
        if (x < b.x)
            return true;
        else return false;
    }
    bool operator==(point b){
        return (x == b.x && y == b.y)?true:false;
    }
}point;

typedef vector<pair<point , point> > lines;

void plotLine(point a, point b){
    // Given a pair of end points a and b, draw a line segment
    int dx = b.x - a.x, dy = b.y - a.y;
    float m;
    if (dx == 0)
        m = INFINITY;
    else m = (dy * 1.)/dx;     //slope

    point start(a.x, a.y);     // Start plotting from first point and repeat for dx times
    point end(b.x, b.y);

    int p = 2 * dy - dx ;
    int k = 0, yk;
    cout <<" \n M: "<<m;

    cout <<"K\tPk\t(x, y):\n";

    // M = infinity
    if (m == INFINITY){
        cout <<"\nm = INF\n";
        while(start.y != end.y){
            cout <<k <<"\t" << p <<"\t" << start << endl;
            start.y += 1;
            putpixel(start.x, getmaxy() - start.y, GREEN);
            continue;
        }
    }
    // For 0 < m < 1, normal algo
    if (m >= 0 && m <= 1){
        cout <<"\n0 <= m <= 1\n";
        if (b.x < a.x){
            start = point(b.x, b.y);
            end = point(a.x, a.y);
        }
        yk = start.y;

        while (start.x <= end.x){
            cout <<k <<"\t" << p <<"\t" << start << endl;
            if (start == end) break;
            start.x += 1;
            start.y = (p > 0) ? start.y + 1: start.y;

            putpixel(start.x, getmaxy() - start.y, BLACK);
            p +=  2 *(end.y - start.y) + 2 *(end.x - start.x) *(yk - start.y);
            k ++;
            yk = start.y;
        }
    }
    // For m > 1, interchange role of  x and y
    if (m > 1){
        cout <<"\nm > 1\n";
        if (b < a){
            start = point(b.x, b.y);
            end = point(a.x, a.y);
        }

        yk = start.x;
        while (start.y <= end.y){
            cout <<k <<"\t" << p <<"\t" << start << endl;

            if (start == end) break;
            start.y += 1;
            start.x = (p > 0) ? start.x + 1: start.x;

            putpixel(start.x, getmaxy() - start.y, BLACK);
            p +=  2 *(end.x - start.x) + 2 *(end.y - start.y) *(yk - start.x);
            k ++;
            yk = start.x;
        }

    }
}

int main(){
    // Initialise graphic drivers and graphModes;
    int graphMode, graphDriver = DETECT;
    int x1, x2, y1, y2;
    initgraph(&graphDriver, &graphMode, NULL);
    setbkcolor(WHITE);
    setcolor(BLACK);

    // read coordinates from a file
    ifstream inf ("coordinates");
    lines newLines;

    while (!inf.eof()){
        inf >> x1 >> y1 >> x2 >> y2 ;
        newLines.push_back(make_pair(point(x1, y1), point(x2, y2) ) );
    }
    inf.close();

    for (auto a : newLines){
        cout <<"\nPlotting line "<<a.first<<" -> "<<a.second<<endl;
        plotLine(a.first, a.second);
    }

    delay(100000);
    closegraph();

    return 0;
}
