// https://practice.geeksforgeeks.org/problems/rotation4723/1

#include <iostream>
#include <vector>

using namespace std;

// Same as finding the minimum.
// Here we will store the index as well and return it.
int numberOfRotations(vector<int>& v)
{
    int low = 0;
    int high = v.size() - 1;

    int lmin = INT32_MAX;
    int index = -1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (v[low] <= v[high]) {
            if (v[low] < lmin) {
                lmin = v[low];
                index = low;
            }
            break;
        }

        if (v[low] <= v[mid]) { // left half sorted
            if (v[low] < lmin) {
                lmin = v[low];
                index = low;
            }
            low = mid + 1;
        } else {
            if (v[mid] < lmin) {
                lmin = v[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}

int numberOfRotationsUsingPivot(vector<int>& v)
{
    int low = 0;
    int high = v.size() - 1;

    if (v[low] <= v[high]) {
        return low;
    }

    while (low < high) {
        int mid = low + (high - low)/2;

        if (v[mid] >= v[0]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6}; // 0 rotations
    cout << numberOfRotations(v) << " " << numberOfRotationsUsingPivot(v) << std::endl;

    v.clear();
    v = {1};    // 0 rotations
    cout << numberOfRotations(v) << " " << numberOfRotationsUsingPivot(v) << std::endl;

    v.clear();
    v = {4, 5, 6, 1, 2, 3}; // 3 rotations
    cout << numberOfRotations(v) << " " << numberOfRotationsUsingPivot(v) << std::endl;

    v.clear();
    v = {6, 1, 2, 3, 4, 5}; // 1 rotations
    cout << numberOfRotations(v) << " " << numberOfRotationsUsingPivot(v) << std::endl;

    v.clear();
    v = {2, 3, 4, 5, 6, 1}; // 5 rotations
    cout << numberOfRotations(v) << " " << numberOfRotationsUsingPivot(v) << std::endl;

    return 0;
}
