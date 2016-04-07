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
    void shiftXCenterFWD(int r){
        if (x + r < getmaxx())
            x += r;
        else x = r;
    }
}point;

typedef vector< pair<point, int> > circles;
// Below are used to shift the colors of the circles
vector<int> colors{BLUE, GREEN, RED, YELLOW, WHITE, MAGENTA, CYAN, BROWN};
static int colorShift = 0;


void circlePlotPoints(point center, point start, int r){
    int h = center.x, k = center.y;
    int x = start.x, y = start.y;
    putpixel(h + x, getmaxy() - (k + y), colors[(colorShift + 0) % colors.size()]);
    putpixel(h + x, getmaxy() - (k - y), colors[(colorShift + 1) % colors.size()]);
    putpixel(h - x, getmaxy() - (k + y), colors[(colorShift + 2) % colors.size()]);
    putpixel(h - x, getmaxy() - (k - y), colors[(colorShift + 3) % colors.size()]);
    putpixel(h + y, getmaxy() - (k + x), colors[(colorShift + 4) % colors.size()]);
    putpixel(h + y, getmaxy() - (k - x), colors[(colorShift + 5) % colors.size()]);
    putpixel(h - y, getmaxy() - (k + x), colors[(colorShift + 6) % colors.size()]);
    putpixel(h - y, getmaxy() - (k - x), colors[(colorShift + 7) % colors.size()]);
}

void circleMidPoint(point center, int r){
    point start(0, r);
    int p = 1 - r;
    putpixel(center.x, getmaxy() - center.y, LIGHTMAGENTA);

    while (start.x < start.y){
        // cout <<"Plotting point: "<<start << " and P: "<< p << endl;
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

    // read coordinates from a file
    ifstream inf ("coordinates");
    circles newCircles;

    while (!inf.eof()){
        inf >> x >> y >> r;
        newCircles.push_back(make_pair(point(x, y), r ) );
    }
    inf.close();
    circles :: iterator it;

    int maxRadius = INT_MIN;
    for(auto a : newCircles){
        if (a.second > maxRadius)
            maxRadius = a.second;
    }

    for(int i = 0; i < 50; i++){
        cleardevice();
        for (it = newCircles.begin(); it != newCircles.end(); it++){
            cout <<"\nPlotting circle "<<it -> first<<" with radius -> "<<it -> second<<"\n\n";
            it -> first.shiftXCenterFWD(maxRadius);
            circleMidPoint(it -> first, it -> second);
        }
        colorShift += 1;
        system("sleep 0.1");
    }

    delay(100000);
    closegraph();

    return 0;
}
