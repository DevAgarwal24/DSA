// 
// https://www.codingninjas.com/studio/problems/next-greater-permutation_6929564

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Brute Force
// Arrange the given array in increasing order
// Find all the permutations for the array (using recursion)
// Do a linear search for the initial array
// Return the next permutation
// T.C = O(N*N!) + O(N!)
// S.C = O()
// In the interviews, we don't need to code the brute force. Just tell the approach
// and try to optimise it.

// Better Solution
// For C++, there is a function called next_permutation() which will return the
// next permutation
// This is not available in other languages
#if 0
vector<int> nextPermutation(vector<int> &v) {
    next_permutation(v.begin(), v.end());
    return v;
}
#endif

// Optimal Solution
// Implement something similar to next_permutaion in c++ stl
// Intuition and Approach
// When we have an array of elements, and we want to find the next permutation
// we know that the next permutation will be something that will be the next bigger
// value if all the elements of the array are taken together
// The given array and the next permutation will have longer prefix match
// Starting from the back, we need to find the an index that breaks the increasing
// nature of the values from the back. We try to find this breakpoint because if
// all the numbers are increasing, then we will already have the biggest possible value
// Only if there is a break in between, means that we can modify our array
// After finding element at the breakpoint, next we need to find the next bigger element
// starting at the breakpoint, till the end of the array. We find the next bigger because
// we need to find the next permutation and not any other permutation
// Finally we need to rearrange the rest of the elements in increasing order

// Find the breakpoint where the increasing nature of the array from the back, breaks
// Find the next biggest element
// Rearrange all the elements starting from breakpoint + 1, to find the next permutation
// T.C = O()
// S.C = O(1)
vector<int> nextPermutation(vector<int> &v) {
    int n = v.size();
    int bkpt = -1;

    // Find the breakpoint that is the index at which we'll
    // have a break in the increasing nature of the values
    // from the back
    for (int i = n-1; i > 0; i--) {
        if (v[i-1] < v[i]) {
            bkpt = i-1;
            break;
        }
    }

    // Couldn't find any break, which means the array has
    // the largest possible value.
    // Reverse the array and return the answer
    if (bkpt == -1) {
        reverse(v.begin(), v.end());
        return v;
    }

    // Find the next big element in the array between the bkpt and
    // the end of the array from the back and swap the elements
    // The bkpt indicates a break in the increasing nature from the back
    for (int i = n-1; i > bkpt; i--) {
        if (v[i] > v[bkpt]) {
            // Swap the element at bkpt and i
            // After swapping, the increasing order of the remaining array
            // from the back still remains
            swap(v[i], v[bkpt]);
            break;
        }
    }

    // Reverse the rest of the elements
    reverse(v.begin()+bkpt+1, v.end());

    return v;
}


void printArray(vector<int> &arr) {
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextPermutation(v);
    printArray(ans);

    v.clear();
    ans.clear();
    v = {2, 1, 3, 5, 2, 7};
    ans = nextPermutation(v);
    printArray(ans);

    return 0;
}