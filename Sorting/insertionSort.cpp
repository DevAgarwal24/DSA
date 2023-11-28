#include <iostream>
#include <vector>

using namespace std;

void insertionSortIncreasing(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

void insertionSortDecreasing(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] < key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

void insertionSort(vector<int> &arr, bool inc) {
    if (inc) {
        insertionSortIncreasing(arr);
    } else {
        insertionSortDecreasing(arr);
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
    
    insertionSort(v, true);
    printArray(v);
    
    v = {12, 45, 8, 5, 16};
    insertionSort(v, false);
    printArray(v);
    
    return 0;
}
