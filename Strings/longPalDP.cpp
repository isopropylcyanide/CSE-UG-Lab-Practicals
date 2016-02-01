#include<bits/stdc++.h>
using namespace std;

tuple<int, vector< vector<int> > > longestPalDP(string &s){
    int n = s.size();
    vector< vector<int> > L(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++)
        L[i][i] = 1;

    for(int sub = 2; sub <= n; sub++){
        for(int i = 0; i < n - sub + 1; i++){
            int j = i + sub -1;
            if (s[i] == s[j] && sub == 2)
                L[i][j] = 2;

            else if (s[i] == s[j])
                L[i][j] = L[i +1][j -1] + 2;

            else L[i][j] = max(L[i +1][j], L[i][j -1]);
        }
    }
    return make_tuple(L[0][n -1], L);
}


int main(){
    ios :: sync_with_stdio(false);
    string a, b;
    vector< vector<int> > A, B;
    int N, T, palLenA, palLenB;
    cin >> T;

    while (T--){
        cin >> a;
        cin >> b;

        tie(palLenA, A) = longestPalDP(a);
        tie(palLenB, B) = longestPalDP(b);

        if (palLenA % 2 == 0 || palLenB % 2 == 0)
            cout << palLenA + palLenB << endl;

        else{
            // both lengths are odd eg 3, 5
            // look for a middle character
            // if found: then max, else max - 1
            bool matchMiddle = false;
            vector<bool> hashA (26, false);
            vector<bool> hashB (26, false);

            for(int i = 0; i < a.size(); i++)
                if (A[i][i] == palLenA){
                    hashA[a[i] - 'a'] = true;
                }

            for(int i = 0; i < b.size(); i++)
                if (B[i][i] == palLenB)
                    hashB[b[i] - 'a'] = true;

            for(int i = 0; i < 26; i++){
                if (hashA[i] == hashB[i]){
                    cout << palLenA + palLenB << endl;
                    matchMiddle = true;
                    break;
                }
            }
            if (!matchMiddle)
                cout << palLenA + palLenB - 1<< endl;
        }

    }
    return 0;
}
