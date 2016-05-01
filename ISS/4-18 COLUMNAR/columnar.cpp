#include <bits/stdc++.h>
using namespace std;

static int key;
static string input;
static vector<string> rail;

// A program to implement columnar cipher.

string encrypt(){
    //Encrypt the rails. i.e Read column by column
    string output;

    for (int col = 0; col < key; col ++){
        for (auto a : rail)
            output.push_back(a[col]);
    }


    return output;
}

int main(){

    cout << "\n Enter key: ";
    cin >> key;

    cout << "\n Enter input string: ";
    cin.ignore();
    getline(cin, input);

    if (input.size() % key != 0)
        input += string(key - input.size() % key, 'z');


    string temp = "";
    for (int i = 0; i < input.size(); i++){
        temp += input[i];
        if ((i + 1) % key == 0){
            rail.push_back(temp);
            temp.clear();
        }
    }

    cout << "\n Rails: \n";
    for (auto a : rail){
        cout << "\t";
        for (auto b : a)
            cout << b << " ";
        cout << endl;
    }

    cout << endl << endl;
    string output = encrypt();
    cout << "\n Encrypted: ";
    cout << output <<  endl << endl;

    return 0;
}
