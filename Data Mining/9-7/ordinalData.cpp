#include <bits/stdc++.h>
using namespace std;

typedef pair<string, double> psd;
typedef vector<psd> vpss;
typedef vector<double> vd;
typedef vector<vd> vvd;

vpss inp;
vvd out;

void prepareDissimMatrix(){
    /* Prepares dissimilarity matrix for nominal data
     P : number of attributes
     M : number of matches
     Formula :  (P - M)/ P
    */
    int n = inp.size();
    out.resize(n, vd(n, 0.0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            // Find the number of matches
            double diss = abs(inp[i].second - inp[j].second);
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
    string str, key;
    double value;
    double minm = INT_MAX, maxm = INT_MIN;

    while (inf){
        getline(inf, str);
        stringstream ss(str);
        while (ss){
            ss >> key;
            ss >> value;
            maxm = max(maxm, value);
            minm = min(minm, value);

            inp.push_back(make_pair(key, value));
        }
        inp.pop_back();
    }

    cout << "\n Max Value: " << maxm;
    cout << "\n Min Value: " << minm << endl;
    for (int i = 0; i < inp.size(); i++)
        inp[i].second = (inp[i].second - minm) * 1.0 / (maxm - minm);

    cout << "\n********INPUT MATRIX***********\n";
    for (auto a : inp){
            cout << fixed << setw(10) <<a.first << " -> " << a.second << " \t ";
        cout << endl;
    }
    cout << endl;
}

int main(){
    // Read data from nominal file into input vector
    ifstream inf("ordinalInp");

    takeInput(inf);
    prepareDissimMatrix();

    cout << endl;

    return 0;
}
