#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> & arr, int low, int mid, int high){
    int i = low, j = mid +1, k = low;
    vector<int> c(100);

    while (i <= mid && j <= high){
        if (arr[i] < arr[j]){
            c[k] = arr[i];
            k ++;i ++;
        }
        else{
            c[k] = arr[j];
            k ++, j ++;
        }
    }
    while (i <= mid){
        c[k] = arr[i];
        k ++;i ++;
    }
    while (j <= high){
        c[k] = arr[j];
        k++, j ++;
    }
    for(i = low; i < k; i++)
        arr[i] = c[i];

    std::cout <<  endl;
    for(auto a: arr)
        cout << a <<" ";
    cout << endl;
}

void mergeSort(vector<int> &arr, int low, int high){
    if (low < high){
        int mid = (low +high) /2;
        printf("low: %d high: %d mid: %d\n",low, high, mid );
        mergeSort(arr, low, mid);
        mergeSort(arr, mid +1, high);
        merge(arr, low, mid, high);
    }
    return;
}


int main(){

    vector<int> arr {6, 5, 3, -1, 7, 10, 12, 2};
    mergeSort(arr, 0, arr.size() -1);

    return 0;
}
