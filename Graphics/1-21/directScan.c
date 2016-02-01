// Demonstrate basic points
#include <graphics.h>
#include <stdio.h>
#include <assert.h>
#define coordinateFile "coordinates"
FILE * fp;

void directDrawLine(int x1, int y1, int x2, int y2){
    int dx = x2 - x1, dy = y2 - y1;
    float m = (dy * 1.)/dx; //slope
    float c = y1 - m*x1;
    int x = x1, y = y1;
    if (x2 < x1) x = x2, y = y2;

    for( int i = 0; i < abs(dx); i++){
        fprintf(stdout, "Plotting points (%d, %d) m: %.2f\n",x, y, m);
        putpixel(x, getmaxy() - y, GREEN);
        if (m <= 1.0){
            x = x + 1;
            y = m*x + c;
        }
        else {
            y = y + 1;
            x = (y - c)/m;
        }
    }
}

int main(){
    int x1, x2, y1, y2;
    fp = fopen(coordinateFile, "r");
    assert(fp);

    int graphDriver = DETECT,graphMode;
    initgraph(&graphDriver, &graphMode, NULL);


    while (!feof(fp)){
        fscanf(fp, "%d %d %d %d", &x1, &y1, &x2, &y2);
        fprintf(stdout, "Read %d %d %d %d\n", x1, y1, x2, y2);
        directDrawLine(x1, y1, x2, y2);
        // line(x1, getmaxy() - y1, x2, getmaxy() - y2);
    }

    fclose(fp);
    fprintf(stdout,"MAX : (%d, %d)\n",getmaxx(), getmaxy() );
    delay(10000);
    closegraph();
    return 0;
}
