#include <bits/stdc++.h>
using namespace std;

// Program to print the mode of the numbers inputted from a file
// Create an exception if the mode doesn't exist or is not unique.

class Mode{
    vector<int> A;
    int num, temp;
    public:
        Mode(){}
        Mode(ifstream &inf){
            // Construct the vector using the input stream
            inf >> num;
            for (int i = 0; i < num; i++){
                inf >> temp;
                A.push_back(temp);
            }
            num = A.size();
            for (auto a : A)
                cout << a << " ";
            cout << endl;
        }

        tuple<int, int> findMode();
        tuple<int, int> findModeO_N();
};

tuple<int, int> Mode :: findMode(){
    // Finds the mode of the vector by sorting it
    sort(A.begin(), A.end());
    int maxCount = -1 , elemMax = A[0], curCount = 1;

    for (int i = 1; i < num; i++){
        if (A[i] == A[i -1]){
            curCount += 1;
            if (maxCount < curCount){
                maxCount = curCount;
                elemMax = A[i];
            }
        }
        else curCount = 1;
    }
    return make_tuple(elemMax, maxCount);
}

tuple<int, int> Mode :: findModeO_N(){
    // Works when there are n elements each lying from 1 to n
    A.push_back(0); //to take care of nth element
    num++;
    for (int i = 0; i < num; i++)
        A[A[i] % num] += num;

    int maxElem = A[0], maxCount = -1;
    for (int i = 1; i < num; i++){
        if (maxCount < A[i]){
            maxCount = A[i];
            maxElem = i;
        }
    }
    for (int i = 0; i < num; i++)
        A[i] %= num;
    maxCount /= num--;

    A.pop_back();
    return make_tuple(maxElem, maxCount);
}

int main(){
    ifstream inf("inputFile");
    int mode, count;

    Mode modeObj(inf);
    tie(mode, count) = modeObj.findMode();

    cout << "\n MODE: " << mode;
    cout << "\t COUNT: " << count << endl << endl;;
    tie(mode, count) = modeObj.findModeO_N();

    cout << "\n MODE: " << mode;
    cout << "\t COUNT: " << count << endl << endl;;

    return 0;
}
