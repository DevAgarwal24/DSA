#include <iostream>
#include <vector>

using namespace std;

void heapifyIncreasing(vector<int> &arr, int N, int root) {
    int largest = root;
    
    int l = 2*largest + 1;
    int r = 2*largest + 2;
    
    if (l < N && arr[largest] < arr[l]) largest = l;
    if (r < N && arr[largest] < arr[r]) largest = r;
    
    if (largest != root) {
        swap(arr[largest], arr[root]);
        heapifyIncreasing(arr, N, largest);
    }
}

void heapSortIncreasing(vector<int> &arr, int N) {
    for (int i = N/2 - 1; i >=0; i--) {
        heapifyIncreasing(arr, N, i);
    }
    
    for (int i = N-1; i >= 0; i--) {
        swap(arr[i], arr[0]);
        
        heapifyIncreasing(arr, i, 0);
    }
}

void heapifyDecreasing(vector<int> &arr, int N, int root) {
    int smallest = root;
    
    int l = 2*smallest + 1;
    int r = 2*smallest + 2;
    
    if (l < N && arr[smallest] > arr[l]) smallest = l;
    if (r < N && arr[smallest] > arr[r]) smallest = r;
    
    if (smallest != root) {
        swap(arr[smallest], arr[root]);
        heapifyIncreasing(arr, N, smallest);
    }
}

void heapSortDecreasing(vector<int> &arr, int N) {
    for (int i = N/2 - 1; i >=0; i--) {
        heapifyDecreasing(arr, N, i);
    }
    
    for (int i = N-1; i >= 0; i--) {
        swap(arr[i], arr[0]);
        
        heapifyDecreasing(arr, i, 0);
    }
}

void heapSort(vector<int> &arr, bool inc) {
    if (inc) {
        heapSortIncreasing(arr, arr.size());
    } else {
        heapSortDecreasing(arr, arr.size());
    }
}

void printArray(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v = {2, 10, 0, 43, 12};
    
    heapSort(v, true);
    printArray(v);
    
    v = {12, 45, 8, 5, 16};
    heapSort(v, false);
    printArray(v);
    
    return 0;
}
