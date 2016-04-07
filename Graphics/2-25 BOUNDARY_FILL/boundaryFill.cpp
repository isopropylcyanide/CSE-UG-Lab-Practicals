#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

void boundaryfill(int x, int y, int col, int boundCol){
    cout <<" At (" << x << ", " << y << ")\n";
    if(getpixel(x, y) == 7 && getpixel(x, y) != boundCol){
        putpixel(x, y, col);
        boundaryfill(x, y +1, col, boundCol);
        boundaryfill(x +1, y, col, boundCol);
        boundaryfill(x, y -1, col, boundCol);
        boundaryfill(x -1, y, col, boundCol);
    }
}


int main(){
    // Initialise graphic drivers and graphModes;
    int graphMode, graphDriver = DETECT;
    int x, y , a, b, col, boundCol;
    initgraph(&graphDriver, &graphMode, NULL);

    // read coordinates from a file
    ifstream inf ("coordinates");

    while (!inf.eof()){
        inf >> x >> y >> a >> b >> col >> boundCol;
        rectangle(x, y, a, b);
        setcolor(boundCol);
        boundaryfill(x, y, col, boundCol);
    }
    inf.close();

    delay(100000);
    closegraph();

    return 0;
}
