#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

int graphMode, graphDriver = DETECT;
double coeffRestitution = 0.8;

// A Program to demonstrate simple animation
// Program demonstrates a ball falling from top of the screen to the base
// The bouncing ball falls in accordance with the gravity

void initialize(){
    initgraph(&graphDriver, &graphMode, NULL);
    setbkcolor(LIGHTGRAY);
    setcolor(RED);
}

void plotBall(int h, int k, int radius){
    circle(h, k, radius);
    floodfill(h, k, RED);
    delay(2);
    cleardevice();
}

int getNextHeight(int height){
    //find next height upto which the ball would bounce after falling from h
    return int(pow(coeffRestitution, 2) * height);
}

int main(){

    initialize();
    int x_c = getmaxx()/2 - 10;
    int radius = 15, maxy = getmaxy();
    int base = maxy - radius;

    int height = maxy - radius;
    while (maxy - height <= base - radius){
        fprintf(stdout, "\n Falling from height : %d to %d", height, getNextHeight(height));
        // for (int y_c = getmaxy() - height; y_c != base; y_c += 1)
        //     plotBall(x_c, y_c, radius);
        //
        height = getNextHeight(height);
        // for (int y_c = base; y_c != getmaxy() - height; y_c --)
        //     plotBall(x_c, y_c, radius);
    }

    delay(10000);
    closegraph();

    return 0;
}
