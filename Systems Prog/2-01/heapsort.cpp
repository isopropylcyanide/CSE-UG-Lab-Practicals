#include <bits/stdc++.h>
using namespace std;

int temp;

int left(int i){
    // get left child 2i + 1
     return 2*i +1;
}

int right(int i){
    // get right child 2*i +2
     return 2*i + 2;
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(vector<int> & arr, int i, int & heapSize){
    cout <<"\n Max heapify called for index: "<<i<<" and HS: "<<heapSize<<endl;
    for (auto a : arr)
        cout << a << " " ;
    cout << endl;

    int l = left(i), r = right(i);

    int largest = i;

    if (l < heapSize && arr[l] > arr[i])
        largest = l;
    if (r < heapSize && arr[r] > arr[largest])
        largest = r;
    if (largest == i)   //we are fine. no heapify needed
        return;

    // else swap arr[i] with arr[largest]
    swap(&arr[largest], &arr[i]);
    maxHeapify(arr, largest, heapSize);

}

void buildHeap(vector<int> & arr, int & heapSize){
    int mid = (arr.size() -1) /2;
    for (int i = mid; i >= 0; i --)
        maxHeapify(arr, i, heapSize );
    cout <<"\n BUILD HEAP COMPLETED\n";
}

void heapSort(vector<int> &arr){
    int heapSize = arr.size();
    buildHeap(arr, heapSize);

    for (int i = arr.size() -1; i >= 0; i--){
        swap(&arr[0], &arr[i]);
        heapSize -= 1;
        maxHeapify(arr, 0, heapSize);
    }
}


int main(){

    vector<int> arr {6, 5, -1, 3, 7, 10, 12, 2};
    heapSort(arr);

    return 0;
}
