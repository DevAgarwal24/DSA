// https://leetcode.com/problems/sort-colors/description/
// https://www.codingninjas.com/studio/problems/sort-an-array-of-0s-1s-and-2s_892977

#include <iostream>
#include <vector>

using namespace std;

// Brute Force
// Sort the array using some general sorting algorithm
// Merge Sort
// T.C = O(NlogN)
// S.C = O(N)

// Better Solution
// Storing the count of the numbers on the first iteration and then modifying the array in the next iteration
// T.C = O(2N)
// S.C = O(1)

// Optimal Solution
// Three pointer approach
//
// Three pointers low, mid and high are used
// The pointers fulfill the following cases
// 0 to low - 1 will be pointing to 0s
// low to mid - 1 will be pointing to 1s
// There will be 0s, 1s, and 2s between mid to high which will be unsorted
// high+1 to n-1 will be pointing to 2s
// This approach is called "Dutch National Flag Algorithm"
// Go through the following code to understand how it will work

void sortArray(vector<int>& arr, int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else if (arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printArray(vector<int> &arr) {
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {0, 1, 0, 2, 2, 1, 0, 1, 1, 2, 2, 0};
    sortArray(v, v.size());

    printArray(v);
}
