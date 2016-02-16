#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    // Given two numbers, finds GCD using Euclidean Method
    if (a < b)
        gcd (b, a);
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

ostream & operator<<(ostream &c, vector<int> v){
    // Utility overloaded method to print the vector for display
    for (auto a : v)
        c  << " " << a;
    c << endl;
    return c;
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
    if (gcd (a, b) != 1)
        return make_tuple(0,0);
    return extendedGCDUtil(a, b, 1, 0, 0, 1);
}

int main(){
    int numEq, a, b, M = 1,r, s;
    vector<int> nums, mods, inverses, divs;
    // Ask user for n equations of the form X = a mod m1, X = b mod m2

    cout <<"\n Enter n (number of equations): \t";
    cin >> numEq;

    for (int i = 0; i < numEq; i ++){
        cout <<"\n Enter (a, b) such that X = a mod b\t ";
        cin >> a >> b;
        nums.push_back(a);
        mods.push_back(b);
        M *= b;
    }
    // Preliminary display
    cout <<"\n Big M: " << M << endl << endl;
    cout <<" Nums: "<< nums << endl;
    cout <<" Mods: "<< mods << endl;

    // Check if all smaller mods are coPrime
    int modGCD = mods[0];
    for (int i = 1; i < mods.size(); i++)
        modGCD = gcd(modGCD, mods[i]);

    if (modGCD != 1){
        cout <<"\n Given modulii are not coprime to each other";
        cout <<"\n No solution exists\n";
        return -1;
    }
    // After storing M = m1 * m2 * m3 and so on
    // Find divs such that M1 = M/M1 , M2 = M/M2 and so on..
    for (auto m : mods)
        divs.push_back(M / m);
    cout <<" Divs: "<< divs << endl;

    // For each entry in divs, find the corresponding inverses mod M
    for (int i = 0; i < numEq; i++){
        tie (r, s) = extendedGCD(divs[i], mods[i]);
        inverses.push_back((r + mods[i]) % mods[i]);
    }
    cout <<" Invs: "<< inverses << endl;

    // Now, final step is to find X = a * m1 * m1^(-1) + b * m2 * m2^(-1)...
    int ans = 0;
    for (int i = 0; i < numEq; i++)
        ans = (ans + nums[i] * divs[i] * inverses[i]) % M;

    cout << " Solution to these equations : "<< ans << endl;
    cout <<" \n Verification: \n";
    for (auto a : mods)
        cout << " " << ans <<" % " << a <<" : " << ans % a << endl;

    cout << endl;
    return 0;
}




















//
