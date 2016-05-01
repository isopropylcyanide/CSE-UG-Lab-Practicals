#include <bits/stdc++.h>
using namespace std;

//A program to compute GCD of two numbers by Euclidean division
static int a, b;

int gcd(int a, int b){
    // Given two numbers, finds GCD using Euclidean Method
    if (a < b)
        gcd (b, a);
    if (b == 0)
        return a;
    return gcd(b, a%b);
}


int main(){

    while (true){
        cout << "\n Enter two space separated numbers: ";
        cin >> a >> b;
        cout << "\n GCD: \t" <<  gcd(a, b) << endl;
    }
    return 0;
}
