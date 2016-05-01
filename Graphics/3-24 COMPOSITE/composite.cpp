#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
const double pi = 3.1415;

vector< vector<double> > mul(vector< vector<double> >& a, vector< vector<double> >& b){
    vector< vector<double> > ans;
    int n  = a[0].size();
    int p = b.size();
    int q = b[0].size();
    assert(n==p);
    for(int i = 0; i<n; i++)
    {
        vector<double> r;
        for(int j =0; j<q; j++)
        {
            double num = 0;
            for(int k = 0; k<p; k++)
            num += a[i][k]*b[k][j];
            r.push_back(num);
        }
        ans.push_back(r);
    }
    return ans;
}
vector< vector<double> > make_P(int x, int y)
{
    vector<double> p,q,r;
    vector< vector<double> > ans;
    p.push_back(x);
    q.push_back(y);
    r.push_back(1);
    ans.push_back(p);
    ans.push_back(q);
    ans.push_back(r);
    return ans;
}
vector< vector<double> > make_T()
{
    vector< vector<double> > T(3);
    T[0].resize(3);
    T[1].resize(3);
    T[2].resize(3);
    for(int i = 0; i<3; i++)
        for(int j = 0; j<3; j++)
        T[i][j] = 0;
    T[0][0] = 1;
    T[1][1] = 1;
    T[2][2] = 1;
    return T;
}
vector< vector<double> > rotateComposite(int x, int y, double xr, double yr, double theta)
{
    vector< vector<double> > P = make_P(x,y);
    vector< vector<double> > T = make_T();
    double c = cos(theta*pi/180.0);
    double s = sin(theta*pi/180.0);
    T[0][0] = c;
    T[0][1] = -s;
    T[0][2] = xr*(1-c) + yr*s;
    T[1][0] = s;
    T[1][1] = c;
    T[1][2] = yr*(1-c)  - xr*s;
    return mul(T,P);
}
vector< vector<double> > scaleComposite(int x, int y, double xr, double yr,double sx, double sy)
{
    vector< vector<double> > P = make_P(x,y);
    vector< vector<double> > T = make_T();
    T[0][0] = sx;
    T[0][2] = xr*(1-sx);
    T[1][1] = sy;
    T[1][2] = yr*(1-sy);
    return mul(T,P);
}
vector< vector<double> > shear(int x, int y, double xr, double yr,double hx,double hy)
{
    vector< vector<double> > P = make_P(x,y);
    vector< vector<double> > T = make_T();
    T[0][0] = 1;
    T[0][1] = hx;
    T[0][2] = -hx*yr;
    T[1][0] = hy;
    T[1][1] = 1;
    T[1][2] = -hy*xr;
    return mul(T,P);
}

vector< vector<double> > reflectX(int x, int y, double yr)
{
    vector< vector<double> > P = make_P(x,y);
    vector< vector<double> > T = make_T();
    T[0][0] = 1;
    T[1][1] = -1;
    T[1][2] = 2*yr;
    return mul(T,P);
}
vector< vector<double> > reflectY(int x, int y, double xr)
{
    vector< vector<double> > P = make_P(x,y);
    vector< vector<double> > T = make_T();
    T[0][0] = -1;
    T[0][2] = 2*xr;
    return mul(T,P);
}
int main()
{
    int arr[3][3]=  {{1,2,3},{4,5,6},{7,8,9}};
    int g = DETECT;
    int d = 0;
    initgraph(&g,&d," ");

    int option;
    while(1)
    {
        cout << "1 for composite rotation\n2 for scaling\n3 for shear\n4 for x reflection\n5for y reflection";
        cin >> option;
        if(option==1)
        {
            cout << "Enter xmin,ymin,xmax,ymax for the rectangle";
            int x,y,x2,y2,x3,y3,x4,y4;
            cin >> x >> y>> x3 >> y3;
            x2 = x3;
            y2 = y;
            x4 = x;
            y4 = y3;
            cout << "Enter xr and yr and theta\n";
            double xr,yr,theta;
            cin >> xr >> yr >> theta;
            vector< vector<double> > P_dash = rotateComposite(x,y,xr,yr,theta);
            vector< vector<double> > P_dash2 = rotateComposite(x2,y2,xr,yr,theta);
            vector< vector<double> > P_dash3 = rotateComposite(x3,y3,xr,yr,theta);
            vector< vector<double> > P_dash4 = rotateComposite(x4,y4,xr,yr,theta);
            cout << "New points are: " << P_dash[0][0] << "," << P_dash[1][0] << "\n";
            cout << P_dash2[0][0] << "," << P_dash2[1][0]<< "\n";
            cout << P_dash3[0][0] << "," << P_dash3[1][0] << "\n";
            cout << P_dash4[0][0] << "," << P_dash4[1][0] << "\n";
            int arr[10] = {P_dash[0][0],P_dash[1][0],P_dash2[0][0],P_dash2[1][0],P_dash3[0][0],P_dash3[1][0],P_dash4[0][0],P_dash4[1][0],P_dash[0][0],P_dash[1][0]};
            rectangle(x,y,x3,y3);
            drawpoly(5,arr);
            delay(1000);
        }
        else if(option==2)
        {
            cout << "Enter xmin,ymin,xmax,ymax for the rectangle";
            int x,y,x2,y2,x3,y3,x4,y4;
            cin >> x >> y>> x3 >> y3;
            x2 = x3;
            y2 = y;
            x4 = x;
            y4 = y3;
            cout << "Enter xr and yr and sx and sy\n";
            double xr,yr,sx,sy;
            cin >> xr >> yr >> sx >> sy;
            vector< vector<double> > P_dash = scaleComposite(x,y,xr,yr,sx,sy);
            vector< vector<double> > P_dash2 = scaleComposite(x2,y2,xr,yr,sx,sy);
            vector< vector<double> > P_dash3 = scaleComposite(x3,y3,xr,yr,sx,sy);
            vector< vector<double> > P_dash4 = scaleComposite(x4,y4,xr,yr,sx,sy);
            cout << "New points are: " << P_dash[0][0] << "," << P_dash[1][0] << "\n";
            cout << P_dash2[0][0] << "," << P_dash2[1][0]<< "\n";
            cout << P_dash3[0][0] << "," << P_dash3[1][0] << "\n";
            cout << P_dash4[0][0] << "," << P_dash4[1][0] << "\n";
            int arr[10] = {P_dash[0][0],P_dash[1][0],P_dash2[0][0],P_dash2[1][0],P_dash3[0][0],P_dash3[1][0],P_dash4[0][0],P_dash4[1][0],P_dash[0][0],P_dash[1][0]};
            rectangle(x,y,x3,y3);
            drawpoly(5,arr);
            delay(1000);
        }
        else if(option==3)
        {
            cout << "Enter xmin,ymin,xmax,ymax for the rectangle";
            int x,y,x2,y2,x3,y3,x4,y4;
            cin >> x >> y>> x3 >> y3;
            x2 = x3;
            y2 = y;
            x4 = x;
            y4 = y3;
            cout << "Enter xr and yr and shx and shy\n";
            double xr,yr,sx,sy;
            cin >> xr >> yr >> sx >> sy;
            vector< vector<double> > P_dash =  shear(x,y,xr,yr,sx,sy);
            vector< vector<double> > P_dash2 = shear(x2,y2,xr,yr,sx,sy);
            vector< vector<double> > P_dash3 = shear(x3,y3,xr,yr,sx,sy);
            vector< vector<double> > P_dash4 = shear(x4,y4,xr,yr,sx,sy);
            cout << "New points are: " << P_dash[0][0] << "," << P_dash[1][0] << "\n";
            cout << P_dash2[0][0] << "," << P_dash2[1][0]<< "\n";
            cout << P_dash3[0][0] << "," << P_dash3[1][0] << "\n";
            cout << P_dash4[0][0] << "," << P_dash4[1][0] << "\n";
            int arr[10] = {P_dash[0][0],P_dash[1][0],P_dash2[0][0],P_dash2[1][0],P_dash3[0][0],P_dash3[1][0],P_dash4[0][0],P_dash4[1][0],P_dash[0][0],P_dash[1][0]};
            rectangle(x,y,x3,y3);
            drawpoly(5,arr);
            delay(1000);
        }
        else if(option==4)
        {
            cout << "Enter xmin,ymin,xmax,ymax for the rectangle";
            int x,y,x2,y2,x3,y3,x4,y4;
            cin >> x >> y>> x3 >> y3;
            x2 = x3;
            y2 = y;
            x4 = x;
            y4 = y3;
            double yr;
            cout << "Enter yr for reflection\n";
            cin >> yr;
            vector< vector<double> > P_dash  =  reflectX(x,y,yr);
            vector< vector<double> > P_dash2 = reflectX(x2,y2,yr);
            vector< vector<double> > P_dash3 = reflectX(x3,y3,yr);
            vector< vector<double> > P_dash4 = reflectX(x4,y4,yr);
            cout << "New points are: " << P_dash[0][0] << "," << P_dash[1][0] << "\n";
            cout << P_dash2[0][0] << "," << P_dash2[1][0]<< "\n";
            cout << P_dash3[0][0] << "," << P_dash3[1][0] << "\n";
            cout << P_dash4[0][0] << "," << P_dash4[1][0] << "\n";
            int arr[10] = {P_dash[0][0],P_dash[1][0],P_dash2[0][0],P_dash2[1][0],P_dash3[0][0],P_dash3[1][0],P_dash4[0][0],P_dash4[1][0],P_dash[0][0],P_dash[1][0]};
            rectangle(x,y,x3,y3);
            drawpoly(5,arr);
            delay(1000);
        }
        else if(option==5)
        {
            cout << "Enter xmin,ymin,xmax,ymax for the rectangle";
            int x,y,x2,y2,x3,y3,x4,y4;
            cin >> x >> y>> x3 >> y3;
            x2 = x3;
            y2 = y;
            x4 = x;
            y4 = y3;
            double xr;
            cout << "Enter xr for reflection\n";
            cin >> xr;
            vector< vector<double> > P_dash  =  reflectY(x,y,xr);
            vector< vector<double> > P_dash2 = reflectY(x2,y2,xr);
            vector< vector<double> > P_dash3 = reflectY(x3,y3,xr);
            vector< vector<double> > P_dash4 = reflectY(x4,y4,xr);
            cout << "New points are: " << P_dash[0][0] << "," << P_dash[1][0] << "\n";
            cout << P_dash2[0][0] << "," << P_dash2[1][0]<< "\n";
            cout << P_dash3[0][0] << "," << P_dash3[1][0] << "\n";
            cout << P_dash4[0][0] << "," << P_dash4[1][0] << "\n";
            int arr[10] = {P_dash[0][0],P_dash[1][0],P_dash2[0][0],P_dash2[1][0],P_dash3[0][0],P_dash3[1][0],P_dash4[0][0],P_dash4[1][0],P_dash[0][0],P_dash[1][0]};
            rectangle(x,y,x3,y3);
            drawpoly(5,arr);
            delay(1000);
        }
    }
}
