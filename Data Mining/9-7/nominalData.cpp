#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<double> vd;
typedef vector<vd> vvd;

vvs inp;
vvd out;

void prepareDissimMatrix(){
    /* Prepares dissimilarity matrix for nominal data
     P : number of attributes
     M : number of matches
     Formula :  (P - M)/ P
    */
    int n = inp.size();
    int p = inp[0].size();

    out.resize(n, vd(p, 0.0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            // Find the number of matches
            int matches = 0;

            for (int k = 0; k < p; k++){
                if (inp[i][k] == inp[j][k])
                    matches ++;
            }
            double diss = (p - matches)*1.0/p;
            out[i][j] = diss;
            out[j][i] = diss;
        }
    }
    cout << "\n********DISSIMILARITY MATRIX***********\n";
    for (auto a : out){
        for (auto b : a)
            cout << fixed << setprecision(2) << b << " \t ";
        cout << endl;
    }
}

void takeInput(ifstream & inf){
    // Takes input from file and prepares the input matrix
    string str, k;
    vs row;

    while (inf){
        getline(inf, str);
        stringstream ss(str);
        while (ss){
            ss >> k;
            row.push_back(k);
        }
        row.pop_back();
        inp.push_back(row);
        row.clear();
    }
    inp.pop_back();

    cout << "\n********INPUT MATRIX***********\n";
    for (auto a : inp){
        for (auto b : a)
            cout << fixed << setw(4) << b << " \t ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    // Read data from nominal file into input vector
    ifstream inf("nominalInp");

    takeInput(inf);
    prepareDissimMatrix();

    cout << endl;

    return 0;
}
