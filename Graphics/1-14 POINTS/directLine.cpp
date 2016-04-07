#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int main(){
	int x1, y1, x2, y2, n1, n2, i, x, y;
	float m, b, dx, dy;

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	cout<<"Enter values (x1, y1) and (x2, y2) respectively";
	cin >> x1 >> y1 >> x2 >> y2;

	n2 = y2 - y1 + 1;
	n1 = x2 - x1 + 1;
	int stx1[n1], sty1[n1], stx2[n2], sty2[n2];

	dx = x2 - x1;
	dy = y2 - y1;

	m = dy/dx;
	b = y1 - (m*x1);

	printf("\n\n");
	if(m  <= 1){
		x = x1;
		for(i = 0; i< n1; i++ ){
			y = floor((m*x) + b);
			stx1[i] = x;
			sty1[i] = y;
			x ++ ;
			cout << stx1[i] << " " << sty1[i] << "\n";
		}
		for(i = 0; i < n1 - 1; i++ )
			line(stx1[i], sty1[i], stx1[i + 1], sty1[i + 1]);
	}

	else{
		y = y1;
		for(i = 0; i<n2; i++){
			x = floor((y - b)/m);
			stx2[i] = x;
			sty2[i] = y;
			y ++ ;
			cout<<stx2[i]<<" "<<sty2[i]<<"\n";
		}
		for(i = 0; i<n2 - 1; i++)
			line(stx2[i], sty2[i], stx2[i + 1], sty2[i + 1]);
	}

    delay(100000);
    closegraph();
    return 0;
}
