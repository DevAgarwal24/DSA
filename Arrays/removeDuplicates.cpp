//
// https://www.codingninjas.com/studio/problems/remove-duplicates-from-sorted-array_1102307

#include <iostream>
#include <vector>

using namespace std;

// Brute Force
// We can create an object for the set ds and insert elements to it by iterating the array
// Fetch the elements from the set object and add it in the first n locations in the array
// set takes O(logN) to add elements and we are trying to add N elements. After that we iterate the set and
// modify the array
// T.C = O(NlogN) + O(N) = O(NlogN)
// S.C = O(N)

// Optimal Solution
// Two pointer approach
// Take another pointr j which will always point to the next unique element
// Add the unique element to the ith index and increement the ith index
// T.C = O(N)
// S.C = O(1)

int removeDuplicates(vector<int> &arr) {
    int n = arr.size();
    int i = 0;
    
    for (int j = 1; j < n; j++) {
        while (arr[j] == arr[i]) {
            j++;
        }

        if (j == n) {
            break;
        }

        arr[i+1] = arr[j];
        i++;
    }

    return i+1;
}

int main()
{
    vector<int> v = {1, 2, 2, 3, 3, 3, 4, 4, 5, 5};
    cout << removeDuplicates(v) << endl;

    v.clear();
    v = {1, 1, 1, 1, 1, 2, 2, 2, 4, 4};
    cout << removeDuplicates(v) << endl;

    return 0;
}