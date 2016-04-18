#include <bits/stdc++.h>
#define seed rand()
typedef long long unsigned ll;
using  namespace std;

ll nextSeed = 1;

int myRand() {
    //generates a random number with the given seed using linear congruential generator
    nextSeed = nextSeed * 1103515245 + 12345;
    return ((nextSeed/65536) % 65536);
}

ll gcd(ll a, ll b){
    // Given two numbers, finds GCD using Euclidean Method
    if (a < b)
        gcd (b, a);
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

tuple<ll, ll> extendedGCDUtil(ll a, ll b, ll s1, ll s2, ll t1, ll t2){
    // Util method to find two solutions s1, t1
    if (b == 0)
        return make_tuple(s1, t1);
    return extendedGCDUtil(b, a % b, s2, s1 - (a / b) * s2, t2, t1 - (a / b) * t2);
}

tuple<ll, ll> extendedGCD(ll a, ll b){
    // Returns a pair of llegers r and s such that a *r + b *s = 1
    // Solutions exist only when gcd(a, b) == 1
    // Let tie (r, s) = extendedGCD(divs[i], mods[i]); then (r + mods[i]) % mods[i] is the mod inv
    if (gcd (a, b) != 1)
        return make_tuple(0,0);
    return extendedGCDUtil(a, b, 1, 0, 0, 1);
}

ll fastExp(ll a, ll b, ll mod){
    //fast modular exponentiation of a ^ b % mod
    if (b == 1)
        return a % mod;
    else{
        if (b % 2 == 0)
            return fastExp((a * a) % mod, b/2, mod) % mod;
        else
            return (a % mod * (fastExp(a, b -1, mod) % mod)) % mod;
    }
}

bool primalityTest(ll n){
    //Given a number n, tests whether it is prime or not
    if (n < 3)
    return n == 2;
    else if (n % 2 == 0)
    return false;

    for (ll i = 3; i * i <= n; i++){
        if (n % i == 0)
        return false;
    }
    return true;
}


void rsaSolver(ll n1, ll n2){
    //Rsa algorithm given two large prime numbers
    ll msg;
    cout << "\n Enter number to encode: ";
    cin >> msg;

    ll n = n1 * n2, phyN = (n1 - 1) * (n2 - 1);
    ll e;
    for (e = 2; e< phyN; e++)
        if (gcd(e, phyN) == 1)
            break;

    ll d, s;
    tie (d, s) = extendedGCD(e, phyN);
    d = (d + phyN) % phyN;

    cout << "\n N: " << n;
    cout << "\n phyN: " << phyN;
    cout << "\n e: " << e;
    cout << "\n d: " << d << endl;

    ll enc = fastExp(msg, e, n);
    cout << "\n The crypted message is: " << enc << endl;

    ll origMsg = fastExp(enc, d, n);
    cout << "\n The decrypted message is: " << origMsg << endl;
}



int main(){
    ll n1 = 0, n2 = 0;
    nextSeed =  time(NULL);

    while(true){
        n1 = myRand();
        if (primalityTest(n1))
            break;
    }

    nextSeed = time(NULL);
    while(true){
        n2 = myRand();
        if (primalityTest(n2) and n2 != n1)
            break;
    }

    assert (gcd(n1, n2) == 1 && primalityTest(n1) && primalityTest(n2));

    cout << "\n Generated Prime Random n1:  " << n1 << endl;
    cout << "\n Generated Prime Random n2:  " << n2 << endl;
    rsaSolver(n1, n2);

    return 0;
}
