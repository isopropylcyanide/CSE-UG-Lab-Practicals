#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &A, int low, int high){
    int pivot = A[high];
    int pivotIndex = low;

    for (int i = low; i < high; i++){
        if (A[i] <= pivot){
            swap(A[i], A[pivotIndex]);
            pivotIndex ++;
        }
    }
    swap(A[high], A[pivotIndex]);
    for (auto a : A)
    cout << a <<" ";
    cout << endl <<endl;
    return pivotIndex;
}


void quickSort(vector<int> &A, int low, int high){
    if (low < high){
        printf("quick (%d, %d)\n",low, high);
        int pivotIndex = partition(A, low, high);
        quickSort(A, low, pivotIndex -1);
        quickSort(A, pivotIndex +1, high);
    }
}


int main(){

    vector<int> A {6, 5, 3, -1, 7, 10, 12, 2};

    cout << endl;
    quickSort(A, 0, A.size() -1);
    for (auto a : A)
    cout << a <<" ";
    cout << endl;

    return 0;
}











//
