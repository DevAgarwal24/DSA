#include <iostream>
#include <vector>

using namespace std;

int partitionIncreasing(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    
    int i = low - 1;
    
    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    
    return i+1;
}

void quickSortIncreasing(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partitionIncreasing(arr, low, high);
        
        quickSortIncreasing(arr, low, pi-1);
        quickSortIncreasing(arr, pi+1, high);
    }
}

int partitionDecreasing(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    
    int i = low - 1;
    
    for (int j = low; j <= high; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    
    return i+1;
}

void quickSortDecreasing(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partitionDecreasing(arr, low, high);
        
        quickSortDecreasing(arr, low, pi-1);
        quickSortDecreasing(arr, pi+1, high);
    }
}

void quickSort(vector<int> &arr, bool inc) {
    if (inc) {
        quickSortIncreasing(arr, 0, arr.size()-1);
    } else {
        quickSortDecreasing(arr, 0, arr.size()-1);
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
    
    quickSort(v, true);
    printArray(v);
    
    v = {12, 45, 8, 5, 16};
    quickSort(v, false);
    printArray(v);
    
    return 0;
}
