// The array will be sorted and each element will always be present twice, except one.
// We need to find the element that is not repeated in the array.
// There is a gurantee that the single element will be present in the array and all other
// elements will be available only twice

#include <iostream>
#include <vector>

using namespace std;

int singleElementInSortedArray(vector<int>& v)
{
    int n = v.size();

    // Edge cases
    if (v.size() == 1) { return v[0]; }
    if (v[0] != v[1]) { return v[0]; }
    if (v[n-1] != v[n-2]) { return v[n-1]; }

    // We will use the value of low and high such that the conditionals are reduced in the code
    int low = 1;
    int high = n-2;

    while (low <= high) {
        int mid = low + (high - low)/2;

        // Check if mid is the non-repeated element or not
        if (v[mid] != v[mid-1] && v[mid] != v[mid+1]) {
            return v[mid];
        }

        // mid is not the non-repeated element. try eliminating the halves
        if (mid%2 == 0) { // even index
            if (v[mid] == v[mid+1]) {   // We are at the left of the element. Eliminate this half
                low = mid + 1;
            } else {    // On right side of the element
                high = mid - 1;
            }
        } else {    // odd index
            if (v[mid] == v[mid-1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> v = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6,};

    cout << singleElementInSortedArray(v) << std::endl;

    v.clear();
    v = {1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6};
    cout << singleElementInSortedArray(v) << std::endl;

    v.clear();
    v = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6};
    cout << singleElementInSortedArray(v) << std::endl;

    return 0;
}