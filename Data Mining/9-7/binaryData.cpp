#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi inp, out;

void prepareDissimMatrix(){
    /* Prepares dissimilarity matrix for nominal data
     P : number of attributes
     M : number of matches
     Formula :  (P - M)/ P
    */
    int n = inp.size();
    out.resize(n, vi(n, 0));

    for (int j = 0; j < n; j++){
            out[inp[0][j]][inp[1][j]] += 1;
        cout << endl;
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
    string str;
    int key;
    vi row;

    while (inf){
        getline(inf, str);
        stringstream ss(str);
        while (ss){
            ss >> key;
            row.push_back(key);
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
    ifstream inf("binaryInp");

    takeInput(inf);
    prepareDissimMatrix();

    cout << endl;

    return 0;
}
