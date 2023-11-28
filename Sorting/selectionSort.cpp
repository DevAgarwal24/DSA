#include <iostream>
#include <vector>

using namespace std;

void selectionSortIncreasing(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        int minIdx = i;
        for (int j = i+1; j < arr.size(); j++) {
            if (arr[minIdx] > arr[j]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap (arr[i], arr[minIdx]);
        }
    }
}

void selectionSortDecreasing(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        int maxIdx = i;
        for (int j = i+1; j < arr.size(); j++) {
            if (arr[maxIdx] < arr[j]) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            swap(arr[i], arr[maxIdx]);
        }
    }
}

void selectionSort(vector<int> &arr, bool inc) {
    if (inc) {
        selectionSortIncreasing(arr);
    } else {
        selectionSortDecreasing(arr);
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
    
    selectionSort(v, true);
    printArray(v);
    
    v = {12, 45, 8, 5, 16};
    selectionSort(v, false);
    printArray(v);
    
    return 0;
}
