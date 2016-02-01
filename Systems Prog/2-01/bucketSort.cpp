#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<int> &arr){
    int n = arr.size();
    int minm = (*min_element(arr.begin(), arr.end()) / 10) * 10;
    int maxm = (*max_element(arr.begin(), arr.end()) / 10) * 10 + 10;
    int rangeM = (maxm - minm)/10;
    vector<vector<int> > buckets(rangeM);

    for(int i = 0; i < n; i++){
        int c = (arr[i] / 10);
        buckets[c].push_back(arr[i]);
    }

    for (int i = 0; i < buckets.size(); i++)
        sort(buckets[i].begin(), buckets[i].end());

    int index = 0;
    for (int i = 0; i < buckets.size(); i++){
        for(int j = 0; j < buckets[i].size(); j++)
            arr[index++] = buckets[i][j];
    }


}

int main(){

    vector<int> arr {6, 5, -1, 3, 7, 10, 12, 2};
    bucketSort(arr);

    for(auto a : arr)
        cout << a << " ";
    cout << endl;

    return 0;
}
