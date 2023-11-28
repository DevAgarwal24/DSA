#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right) {
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;
    
    vector<int> leftArray(subArrayOne);
    vector<int> rightArray(subArrayTwo);
    
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
        
    for (int i = 0; i < subArrayTwo; i++)
        rightArray[i] = arr[mid + 1 + i];
    
    int subArrayOneIndex = 0, subArrayTwoIndex = 0;
    int mergeArrayIndex = left;
    while (subArrayOneIndex < subArrayOne && subArrayTwoIndex < subArrayTwo) {
        if (leftArray[subArrayOneIndex] <= rightArray[subArrayTwoIndex]) {
            arr[mergeArrayIndex] = leftArray[subArrayOneIndex];
            subArrayOneIndex++;
        } else {
            arr[mergeArrayIndex] = rightArray[subArrayTwoIndex];
            subArrayTwoIndex++;
        }
        
        mergeArrayIndex++;
    }
    
    while (subArrayOneIndex < subArrayOne) {
        arr[mergeArrayIndex] = leftArray[subArrayOneIndex];
        mergeArrayIndex++;
        subArrayOneIndex++;
    }
    
    while (subArrayTwoIndex < subArrayTwo) {
        arr[mergeArrayIndex] = rightArray[subArrayTwoIndex];
        mergeArrayIndex++;
        subArrayTwoIndex++;
    }
    
}

void mergeSort(vector<int> &arr, int begin, int end) {
    if (begin >= end) {
        return;
    }
    
    int mid = begin + (end - begin)/2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, begin, mid, end);
}

void printArray(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {2, 10, 0, 43, 12};
    mergeSort(v, 0, v.size()-1);
    printArray(v);
    
    vector<int> v1 = {12, 45, 8, 5, 16};
    mergeSort(v1, 0, v1.size()-1);
    printArray(v1);
    
    return 0;   
}
