//
//

#include <iostream>
#include <vector>

using namespace std;

// Brute Force
// Store the first d elements in a temporary vector/array
// Shift the array by iterating over it
// Add the last d elements from the temporary array
// T.C = O(d) + O(n-d) + O(d) = O(n+d) Not sure how?
// S.C = O(d)

// Optimal Solution
// Try to get rid of the extra space
// This approach is based on the simple observation
// Reverse the first d elements in the array, and then the remaining n-d elements
// Finally, reverse the whole array. There is a reverse function in c++ that one can use
// I have implemented my own reverse
// T.C = O(d) + O(n-d) + O(d) = O(2n) Really?

void reverse(vector<int> &arr, int start, int end) {
    int i = start;
    int j = end - 1;

    while (i < (start + (end-start)/2)) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;

        i++;
        j--;
    }
}

void leftRotate(vector<int> &arr, int d) {
    int n = arr.size();
    d = d % n;

    if (d == 0) return;

    reverse(arr, 0, d);
    reverse(arr, d, n);
    reverse(arr, 0, n);
}

void printArray(vector<int> &arr) {
    for (int i : arr) {
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    leftRotate(v, 3);
    printArray(v);

    v.clear();
    v = {5, 4, 3, 2, 1};
    leftRotate(v, 2);
    printArray(v);

    return 0;
}