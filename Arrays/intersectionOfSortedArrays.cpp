// 

#include <iostream>
#include <vector>

using namespace std;

// Brute Force
// Take element from one array and check if the same element is present in the other array
// While checking if the element is present, keep a track of whether the element is already taken or not
// Create a bool visiteArray for this
// T.C = O(n*m)
// S.C = O(n2)

// Optimal Solution
// Here repetition of elements are allowed
// Similar to merge sort, but add only when the elements are equal
// T.C = O(n+m)
// S.C = O(1)
vector<int> unionOfSortedArray(vector<int> &a, vector<int> &b) {
    vector<int> ans;

    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            i++;
        } else if (b[j] < a[i]) {
            j++;
        } else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
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
    vector<int> v1 = {1, 1, 2, 3, 3, 4, 5, 7, 7, 9, 9};
    vector<int> v2 = {0, 0, 2, 3, 3, 4, 5, 6};

    vector<int> v3 = unionOfSortedArray(v1, v2);
    printArray(v3);

    return 0;
}