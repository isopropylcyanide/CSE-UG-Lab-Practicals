#include <bits/stdc++.h>
using namespace std;

// Construct Z Array for a given String
// When looking for a pattern in a text, build Z array for
// pattern + $ + text . In Z array, if Z value at any point is equal to pattern length, then pattern is present at that point.

ostream & operator<<(ostream &c, vector<int>a){
    for (auto ab : a)
        c <<" "<<ab;
    c << endl;
    return c;
}
vector<int> constructZArray(string &s){
    int L = 0, R = 0, k, n = s.size();
    vector<int> Z(n);
    // [L,R] make a window which matches prefix of S

    for(int i = 1; i < n; i++){
        if (i > R){//Naive
            L = R = i;
            while (R < n && s[R - L] == s[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else{//Smart
            k = i - L;
            if (Z[k] < R - i +1)
                Z[i] = Z[k];
            else{
                L = i;
                while (R < n && s[R -L] == s[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
    return Z;
}

void search(string &pattern, string &text){
    string concat = pattern + "$" + text;
    int n = concat.size();
    int l = pattern.size();

    vector<int> Z = constructZArray(concat);
    cout <<"\nZ Array for concat: "<<Z;

    for(int i = 0; i < n; i++)
        if (Z[i] == l)
            cout <<"\nPattern from : "<<i -l -1<<"-"<<i -1;
    cout << endl;
}


int main(){
    string text, pattern;
    cout <<"\nEnter text: "; cin >> text;
    cout <<"\nEnter pattern: "; cin >> pattern;

    cout << "\nZ Array for text: "<< constructZArray(text);
    cout << "\nZ Array for pattern: "<< constructZArray(pattern);

    search(pattern, text);
    return 0;
}











//
