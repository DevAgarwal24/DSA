// https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960

#include<iostream>
#include<vector>

using namespace std;

// Brute Force
// Sort the array and then find the second largest / smallest
// We cannot directly return arr[n-2] or arr[1] because there can be duplicates
// T.C = O(NlogN + N)

// Better Approach
// Do a first pass on the array and find the largest element
// Do another pass on the array and find the second largest
// T.C = O(2N) = O(N)

// Optimal Solution
// Start with largest = arr[0] and second largest = INT_MIN
// Iterate over the loop and find the values
// T.C = O(N)
void secondOrderElements(vector<int> &arr) {
    int n = arr.size();

    int largest = arr[0];
    int sLargest = INT32_MIN;

    int smallest = arr[0];
    int sSmallest = INT32_MAX;

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            sLargest = largest;
            largest = arr[i];
        } else if (arr[i] > sLargest) {     // don't really need to check arr[i] < largest
            sLargest = arr[i];
        }

        if (arr[i] < smallest) {
            sSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] != smallest && arr[i] < sSmallest) {  // arr[i] != smallest is checked for duplicates?
            sSmallest = arr[i];
        }
    }

    cout << sLargest << " " << sSmallest << endl;
}

int main()
{
    vector<int> v = {1, 1, 1, 1, 1, 1, 1, 2, 3};
    secondOrderElements(v);     // 2 2

    v.push_back(4);
    secondOrderElements(v);     // 3 2

    v.clear();
    v = {3, 82, 23, 78, 45, 63, 9, 47};
    secondOrderElements(v);     // 78 9
}