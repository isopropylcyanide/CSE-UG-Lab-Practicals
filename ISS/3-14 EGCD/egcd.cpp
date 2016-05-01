#include <bits/stdc++.h>
using namespace std;

//A program to compute the extended GCD of two numbers by Euclidean division
// To find a, b such that ax + by = gcd(a, b)


int gcd(int a, int b){
    // Given two numbers, finds GCD using Euclidean Method
    if (a < b)
        gcd (b, a);
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

tuple<int, int> extendedGCDUtil(int a, int b, int s1, int s2, int t1, int t2){
    // Util method to find two solutions s1, t1
    if (b == 0)
        return make_tuple(s1, t1);
    return extendedGCDUtil(b, a % b, s2, s1 - (a / b) * s2, t2, t1 - (a / b) * t2);
}

tuple<int, int> extendedGCD(int a, int b){
    // Returns a pair of integers r and s such that a *r + b *s = 1
    // Solutions exist only when gcd(a, b) == 1
    // Let tie (r, s) = extendedGCD(divs[i], mods[i]); then (r + mods[i]) % mods[i] is the mod inv
    if (gcd (a, b) != 1)
        return make_tuple(0,0);
    return extendedGCDUtil(a, b, 1, 0, 0, 1);
}

int main(){
    int numA, numB, a, b, gcdVal;

    while (true){
        cout << "\n Enter two space separated numbers: ";
        cin >> numA >> numB;
        gcdVal = gcd(numA, numB);
        cout << "\n GCD: \t" << gcdVal << endl;

        if (gcdVal != 1 )
            printf("\t%d and %d are not coprime. No such a and b exist\n", numA, numB );
        else{
            tie(a, b) = extendedGCD(numA, numB);
            printf("\ta: %d, b: %d => satisfy %d(%d) + %d(%d) = 1\n",a, b, a, numA, b, numB );
        }
    }
    return 0;
}
