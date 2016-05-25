// Demonstrate basic points
#include <graphics.h>
#include <stdio.h>


int main(){

    int graphDriver = DETECT,graphMode;
    initgraph(&graphDriver, &graphMode, NULL);
    setbkcolor(WHITE);
    setcolor(BLACK);

    fprintf(stdout,"MAX : (%d, %d)\n",getmaxx(), getmaxy() );

    // Creating a rectangular loop around the borders of concentric width 20
    for (int i = 1; i < 10; i++)
        rectangle(10*i, getmaxy() - 10*i, getmaxx() - 10*i, 10*i);

    delay(100000);
    closegraph();
    return 0;
}
