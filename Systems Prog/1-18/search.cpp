#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void linearSearch(vector<int> & input, const int & key){
    // Given a key and an array, it linearly  searches for the input key
    vector<int> :: iterator it = find(input.begin(), input.end(), key);
    if (it == input.end())  //we have reached end of the iterator
        cout << " Linear search couldn't locate the key: "<< key << endl;
    else
        cout << " Linear search located the key: "<< key <<" at: "<<int(it - input.begin())<<endl;
}


void binarySearch(const vector<int> & input, const int & key){
    // Given a key and a sorted array, it searches for the input key by dividing into intervals
    vector<int> newInput (input);
    sort(newInput.begin(), newInput.end());

    int l = 0, r = newInput.size() - 1, mid;
    bool foundState = false;

    while (l <= r){
        mid = (l + r)/2 ;

        if (newInput[mid] == key){
            foundState = true;
            break;
        }
        else if (newInput [mid] > key) //Key < [mid]. So, move to left interval
            r = mid - 1;
        else                //Key > [mid]. So, move to right interval
            l = mid + 1;
    }

    if (foundState == true)
        cout << " Binary search located the key: "<< key << endl;
    else
        cout << " Binary search couldn't locate the key: "<< key << endl;
}

int main(){

    // Read test data
    ifstream inf("testFile");
    if (!inf){
        fprintf(stderr,"\nError opening test file\n");
        return -1;
    }

    vector<int> input;
    int searchKey;
    char c;

    while( (c = inf.get()) != EOF)
		input.push_back(int(c));

    inf.close();

    for (auto elem : input)
        cout << elem <<" ";

    while (true){
        cout <<"\n Enter search key: (-10 to quit) ";
        cin >> searchKey;
        if (searchKey == -10) break;

        linearSearch(input, searchKey);
        binarySearch(input, searchKey);
    }

    return 0;
}
