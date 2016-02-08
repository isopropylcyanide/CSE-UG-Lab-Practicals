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
    return pivotIndex;
}

int quickSelSmall(vector<int> &A, int low, int high, int n){
    if (low == high)
        return A[low];
    int pivotIndex = partition(A, low, high);
    if (n == pivotIndex)
        return A[n];
    else if (n < pivotIndex)
        return quickSelSmall(A, low, pivotIndex -1, n);
    else
        return quickSelSmall(A, pivotIndex +1, high, n);
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
    vector<int> B(A);
    // find nth largest / smallest element
    for (int i = 0; i < B.size(); i++){
        cout <<i +1<<"th smallest elem: ";
        cout << quickSelSmall(B, 0, B.size(), i)<<"\n";
        B = A;
    }
    cout << endl;
    quickSort(A, 0, A.size() -1);
    for (auto a : A)
    cout << a <<" ";
    cout << endl;

    return 0;
}











//
