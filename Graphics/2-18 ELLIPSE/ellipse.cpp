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

typedef vector< pair<point, point> > ellipses;
// First pair represents the origin and next gives a, b

void drawEllipse(point center, point start){
    int h = center.x, k = center.y;
    int x = start.x, y = start.y;
    putpixel(h + x, getmaxy() - (k + y), BLACK);
    putpixel(h + x, getmaxy() - (k - y), BLACK);
    putpixel(h - x, getmaxy() - (k + y), BLACK);
    putpixel(h - x, getmaxy() - (k - y), BLACK);
}

void ellipseBresen(point origin, point para){
    int a = para.x, b = para.y;
    // int xA = origin.x, yA = origin.y;
    // ellipse(xA, yA, 0, 360, b, a);
    int a2 = a *a, b2 = b *b;
    int x = 0, y = b;
    float d = b2 - (a2 * b) + a2/4.;

    // REGION I
    while (b2*x <= a2*y){
        point zy = point(x, y);
        cout << "\nREG I: "<< zy << "\td: " << d;
        drawEllipse(origin, zy);
        x ++;
        if (d > 0){
            y--;
            d += 2.0 * b2 * x + b2 - 2.0 * a2 * y;
        }
        else d += b2 + 2.0 * b2 * x;
    }

    // REGION II
    x = a, y = 0;
    d = a2 + 2.0 * b2 * a + b2/4.;

    while (a2*y <= b2*x){
        point zy = point(x, y);
        cout << "\nREG II: "<< zy << "\td: " << d;
        drawEllipse(origin, zy);
        y++;
        if (d > 0)
            d += a2 - 2.0 * a2 *y;

        else{
            x--;
            d += 2.0 * b2 *x - 2.0 *a2 *y +a2;
        }
    }
}


int main(){
    // Initialise graphic drivers and graphModes;
    int graphMode, graphDriver = DETECT;
    int x, y , a, b;
    initgraph(&graphDriver, &graphMode, NULL);

    // read coordinates from a file
    ifstream inf ("coordinates");
    ellipses newEllipse;
    setbkcolor(WHITE);

    while (!inf.eof()){
        inf >> x >> y >> a >> b;
        newEllipse.push_back(make_pair(point(x, y), point(a, b) ) );
    }
    inf.close();
    ellipses :: iterator it;

    for (it = newEllipse.begin(); it != newEllipse.end(); it++){
        cout <<"\nPlotting ellipse "<<it -> first<<" with a, b-> "<<it -> second<<"\n\n";
        ellipseBresen(it -> first, it -> second);
    }

    delay(100000);
    closegraph();

    return 0;
}
