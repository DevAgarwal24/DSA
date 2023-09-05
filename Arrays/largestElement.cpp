// https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279

#include <iostream>
#include <vector>

using namespace std;

// I initially thought that iterating on the array and finding the largest element will
// be the brute force solution, but it's actually the optimized one.
// Sorting and array and then getting the last element of the array for the maximum will take O(nlogn) and
// iterating and finding the maximum element will take O(n) time

int largestElement(vector<int> &v) {
    int n = v.size();
    
    int maxElem = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > maxElem) {
            maxElem = v[i];
        }
    }

    return maxElem;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << largestElement(v) << endl;

    v.clear();
    v = {3, 82, 9, 34, 29, 78, 12};
    cout << largestElement(v) << endl;

    return 0;
}

