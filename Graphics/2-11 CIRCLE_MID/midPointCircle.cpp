#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

typedef struct point{
    int x, y, origX, origY;
    point(){}
    point(int x1, int y1){
        origX = x = x1;
        origY = y = y1;
    }
    friend ostream & operator<<(ostream &c, point &a){
        c << "(" << a.x <<"," << a.y <<") ";
        return c;
    }
}point;

typedef vector< pair<point, int> > circles;

void circlePlotPoints(point center, point start, int r){
    int h = center.x, k = center.y;
    int x = start.x, y = start.y;
    putpixel(h + x, getmaxy() - (k + y), BLACK);
    putpixel(h + x, getmaxy() - (k - y), BLACK);
    putpixel(h - x, getmaxy() - (k + y), BLACK);
    putpixel(h - x, getmaxy() - (k - y), BLACK);
    putpixel(h + y, getmaxy() - (k + x), BLACK);
    putpixel(h + y, getmaxy() - (k - x), BLACK);
    putpixel(h - y, getmaxy() - (k + x), BLACK);
    putpixel(h - y, getmaxy() - (k - x), BLACK);
}

void circleMidPoint(point center, int r){
    point start(0, r);
    int p = 1 - r;
    putpixel(center.x, getmaxy() - center.y, LIGHTMAGENTA);

    while (start.x < start.y){
        cout <<"Plotting point: "<<start << " and P: "<< p << endl;
        circlePlotPoints(center, start, r);
        start.x += 1;
        if (p < 0)
            p += 2 * start.x + 1;
        else{
            start.y -= 1;
            p += 2  * (start.x - start.y) + 1;
        }
    }
}

int main(){
    // Initialise graphic drivers and graphModes;
    int graphMode, graphDriver = DETECT;
    int x, y , r;
    initgraph(&graphDriver, &graphMode, NULL);
    setbkcolor(WHITE);
    setcolor(BLACK);

    // read coordinates from a file
    ifstream inf ("coordinates");
    circles newCircles;

    while (!inf.eof()){
        inf >> x >> y >> r;
        newCircles.push_back(make_pair(point(x, y), r ) );
    }
    inf.close();
    circles :: iterator it;

    for (it = newCircles.begin(); it != newCircles.end(); it++){
        cout <<"\nPlotting circle "<<it -> first<<" with radius -> "<<it -> second<<"\n\n";
        circleMidPoint(it -> first, it -> second);
    }

    delay(100000);
    closegraph();

    return 0;
}
