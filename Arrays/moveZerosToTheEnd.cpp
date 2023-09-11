//
//

#include <iostream>
#include <vector>

using namespace std;

// Brute Force
// Iterate over the array and store all the non-zero elements in another array
// Fill the numbers from temporary to array starting from the 0th index and then fill the rest of the array with 0s
// T.C = O(N) + O(N) = O(2N) = O(N)
// S.C = O(N)

// Optimal Solution
// Find the 1st 0 element and put a pointer j there. This pointer will always be pointing to a 0 element
// Take another pointer and put it right next to the j. This is the i pointer
// If i is at a non-zero, swap the elements, and if i is at 0, move it till you find a non-zero element
// T.C = O(N)
// S.C = O(1)

void moveZerosToTheEnd(vector<int> &arr) {
    int n = arr.size();

    int i = 0; int j = 0;
    while (j < n && arr[j] != 0) {
        j++;
    }

    i = j+1;

    while (i < n) {
        while(i < n && arr[i] == 0) {
            i++;
        }

        if (i == n) break;

        swap(arr[j], arr[i]);
        i++;
        j++;
    }
}

void printArray(vector<int> &arr) {
    for (int i : arr) {
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    moveZerosToTheEnd(v);
    printArray(v);

    v.clear();
    v  = {1, 2, 3, 4, 5};
    moveZerosToTheEnd(v);
    printArray(v);

    v.clear();
    v = {0, 1, 2, 3, 0, 5};
    moveZerosToTheEnd(v);
    printArray(v);

    v.clear();
    v = {1, 2, 3, 0, 0, 0, 0};
    moveZerosToTheEnd(v);
    printArray(v);

    v.clear();
    v = {0, 0, 0, 0, 1, 2, 3, 4};
    moveZerosToTheEnd(v);
    printArray(v);
}