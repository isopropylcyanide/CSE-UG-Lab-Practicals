#include <bits/stdc++.h>
using namespace std;

int numRails;
string userStr;
vector<char> rail;

void display(vector<char> &rail){
    cout <<"\n Rail: ";
    for (auto a : rail)
        cout << a << " ";
    cout << endl;
}

void encrypt(){
    rail.resize(0);
    int starter, gap;
    cout <<"\n********ENCRYPTION**********\n";

    for (int railNum = 0; railNum < numRails; railNum++){
        if (railNum == 0 || railNum == numRails -1){
            starter = railNum;
            gap = 2 * (numRails -1);
            rail.push_back(userStr[starter]);

            starter += gap;
            while (starter < userStr.size()){
                rail.push_back(userStr[starter]);
                starter += gap;
            }
        }

        else{
            bool isOdd = true;
            starter = railNum;
            int railBelow, railAbove;
            while (starter < userStr.size()){
                rail.push_back(userStr[starter]);

                if (isOdd){    //do odd first
                    isOdd = false;
                    railBelow = numRails - railNum -1;
                    gap = 2 * railBelow;
                }
                else{
                    railAbove = railNum;
                    gap = 2 * railAbove;
                    isOdd = true;
                }
                starter += gap;
            }
        }
        display(rail);
    }
}

void decrypt(){
    vector<char> deRail(rail.size(),'-');
    int i = 0, starter, gap, j;
    cout <<"\n********DECRYPTION**********\n";

    for (int iter = 0; iter < numRails; iter++){
        if (iter == 0 || iter == numRails -1){
            starter = iter;
            deRail[starter] = rail[i ++];
            gap = 2 * (numRails -1);
            starter += gap;

            while(starter < rail.size()){
                deRail[starter] = rail[i ++];
                starter += gap;
            }
        }
        else{
            bool isOdd = true;
            starter = iter;

            while (starter < deRail.size()){
                if (isOdd){
                    gap = 2 * (numRails - iter -1);
                    deRail[starter] = rail[i++];
                    isOdd = false;
                    starter += gap;
                }
                else{
                    isOdd = true;
                    deRail[starter] = rail[i++];
                    gap = 2 * iter;
                    starter += gap;
                }
            }
        }
        display(deRail);
    }

}


int main(){

    cout <<" Enter String: ";
    cin >> userStr;
    cout <<" Enter number of rails: ";
    cin >> numRails;

    encrypt();
    decrypt();

    return 0;
}
