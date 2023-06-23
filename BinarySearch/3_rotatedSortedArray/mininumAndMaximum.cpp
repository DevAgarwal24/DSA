#include <iostream>
#include <vector>

using namespace std;

// This minimum code is same as the pivot
int minimumSortedRotatedArrayPivot(vector<int>& v)
{
    int low = 0;
    int high = v.size() - 1;

    if (v[low] <= v[high]) { // corner case where the array is not rotated
        return v[low];
    }

    while (low < high) {

        int mid = low + (high - low)/2;

        if (v[mid] >= v[0]) { // left half sorted
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return v[low];
}

int mininumSortedRotatedArray(vector<int>& v)
{
    int low = 0;
    int high = v.size() - 1;

    int lmin = INT32_MAX;

    while (low <= high) {
        int mid = low + (high - low)/2;

        // This is an optimization and the code works fine without this as well
        // If the search space is already sorted, then value at low will always be
        // less that value at high
        if (v[low] < v[high]) {
            lmin = min(lmin, v[low]);
            break;
        }

        if (v[mid] >= v[low]) { // left half sorted, but may contain the mininum
            lmin = min(lmin, v[low]);
            low = mid + 1;
        } else {
            lmin = min(lmin, v[mid]);
            high = mid - 1;
        }
    }

    return lmin;
}

int maximumSortedRotatedArray(vector<int>& v)
{
    return 0;
}

int main()
{
    vector<int> v = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    cout << minimumSortedRotatedArrayPivot(v) << std::endl;
    cout << mininumSortedRotatedArray(v) << std::endl;
    cout << std::endl;

    v.clear();
    v = {7, 8, 9, 0, 3, 4, 5, 6};
    cout << minimumSortedRotatedArrayPivot(v) << std::endl;
    cout << mininumSortedRotatedArray(v) << std::endl;
    cout << std::endl;

    v.clear();
    v = {8, 9, 10, 2, 3, 4, 5, 6, 7};
    cout << minimumSortedRotatedArrayPivot(v) << std::endl;
    cout << mininumSortedRotatedArray(v) << std::endl;
    cout << std::endl;

    v.clear();
    v = {3, 4, 5, 6, 7, 8, 9, 10};
    cout << minimumSortedRotatedArrayPivot(v) << std::endl;
    cout << mininumSortedRotatedArray(v) << std::endl;
    cout << std::endl;

    cout << std::endl;

    cout << maximumSortedRotatedArray(v) << std::endl;

    return 0;
}