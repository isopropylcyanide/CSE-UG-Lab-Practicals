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
        if ((x == b.x && y < b.y) || (y == b.y && x < b.x) )
            return true;
        if (x < b.x && y < b.y)
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

    if (b < a){
        start = point(b.x, b.y);
        end = point(a.x, a.y);
        cout <<"Point b is small. Start with small\n";
    }

    int p = 2 * dy - dx ;
    int k = 0;
    int yk = start.y;

    cout <<"K\tPk\t(x, y):\n";

    while (start.x <= end.x){
        cout <<k <<"\t" << p <<"\t" << start << endl;
        if (start == end) break;

        if (m == INFINITY){
            cout <<"Up line\n";
            start.y += 1;
            putpixel(start.x, getmaxy() - start.y, GREEN);
            continue;
        }
        start.x += 1;

        start.y = (p > 0) ? start.y + 1: start.y;

        putpixel(start.x, getmaxy() - start.y, GREEN);
        p +=  2 *(end.y - start.y) + 2 *(end.x - start.x) *(yk - start.y);
        k ++;
        yk = start.y;
    }
}

int main(){
    // Initialise graphic drivers and graphModes;
    int graphMode, graphDriver = DETECT;
    int x1, x2, y1, y2;
    initgraph(&graphDriver, &graphMode, NULL);

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
