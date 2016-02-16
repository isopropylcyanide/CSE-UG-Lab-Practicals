#include <bits/stdc++.h>
using namespace std;

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

int search(const string &pattern, const string &text){
    if (pattern.size() == 0 || text.size() == 0)
        return -1;

    string concat = pattern + "$" + text;
    int n = concat.size();
    int l = pattern.size();
    int firstOccur = -1;

    vector<int> Z = constructZArray(concat);
    for(int i = 0; i < n; i++)
        if (Z[i] == l){
            firstOccur = i -l -1;
            break;
        }

    return firstOccur;
}


int strStr(const string &haystack, const string &needle) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    // Construct Z Array for haystack + $ + needle
    // Find pattern

    return search(haystack, needle)<<endl;
}

int main(){
    cout << search("baba",  "b");
}
