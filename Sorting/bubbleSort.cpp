#include <iostream>
#include <vector>

using namespace std;

void bubbleSortIncreasing(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void bubbleSortDecreasing(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] < arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void bubbleSort(vector<int> &arr, bool inc) {
    if (inc) {
        bubbleSortIncreasing(arr);
    } else {
        bubbleSortDecreasing(arr);
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
    
    bubbleSort(v, true);
    printArray(v);
    
    v = {12, 45, 8, 5, 16};
    bubbleSort(v, false);
    printArray(v);
    
    return 0;
}
