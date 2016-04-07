#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<int> &A){
    int n = A.size();
    int minm = (*min_element(A.begin(), A.end()) / 10) * 10;
    int maxm = (*max_element(A.begin(), A.end()) / 10) * 10 + 10;
    int rangeM = (maxm - minm)/10;
    vector<vector<int> > buckets(rangeM);

    cout <<"\nTotal Buckets are: "<<rangeM<<endl;

    for(int i = 0; i < n; i++){
        int c = (A[i] / 10);
        cout <<"\n"<<A[i]<<" goes into bucket: "<<c<<endl;
        buckets[c].push_back(A[i]);
    }

    for (int i = 0; i < buckets.size(); i++)
        sort(buckets[i].begin(), buckets[i].end());

    int index = 0;
    for (int i = 0; i < buckets.size(); i++){
        for(int j = 0; j < buckets[i].size(); j++)
            A[index++] = buckets[i][j];
    }


}

int main(){

    vector<int> A {6, 5, -1, 3, 7, 10, 12, 2};
    bucketSort(A);

    for(auto a : A)
        cout << a << " ";
    cout << endl;

    return 0;
}
