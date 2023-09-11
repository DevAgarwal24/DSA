// https://www.codingninjas.com/studio/problems/sorted-array_6613259

#include <iostream>
#include <vector>

using namespace std;

// Brute Force
// Iterate over both the arrays
// Use a set data structure to store the unique elements from both the arrays
// T.C = O(nlogn + mlogm) + O(n+m)
// S.C = O(m+n)

// Optimal Solution
// Something similar to merge sort, but we check for duplicates
// T.C = O(m+n)
// S.C = O(1)
vector<int> unionOfSortedArray(vector<int> &a, vector<int> &b) {
    if (a[0] > b[0]) {
        return unionOfSortedArray(b, a);
    }

    vector<int> ans;
    ans.push_back(a[0]);

    int i = 1;
    int j = 0;

    while (i < a.size() && j < b.size()) {
        while (i < a.size() && a[i] <= ans.back()) i++;
        while (j < b.size() && b[j] <= ans.back()) j++;

        if (i == a.size() || j == b.size()) break;

        if (a[i] < b[j]) {
            ans.push_back(a[i]);
            i++;
        } else {
            ans.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size()) {
        while (i < a.size() && a[i] <= ans.back()) i++;
        if (i == a.size()) break;

        ans.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        while (j < b.size() && b[j] <= ans.back()) j++;
        if (j == b.size()) break;

        ans.push_back(b[j]);
        j++;
    }

    return ans;
}

void printArray(vector<int> &arr) {
    for (int i : arr) {
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v1 = {1, 1, 2, 3, 4, 5, 7, 7, 9, 9};
    vector<int> v2 = {0, 0, 2, 3, 3, 4, 5, 6};

    vector<int> v3 = unionOfSortedArray(v1, v2);
    printArray(v3);

    return 0;
}