// https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

int searchSortedRotatedArray(vector<int>& v, int number)
{
    int low = 0;
    int high = v.size() - 1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (v[mid] == number) {
            return mid;
        }

        // Left Side is sorted
        if (v[low] <= v[mid]) {
            // Number lies in the sorted side
            if (v[low] <= number && v[mid] >= number) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Right side is sorted
        // This if check can be made as an else check because when one side is sorted in a rotated array
        // the other side won't be sorted.
        // Is this if condition actually incorrect and should I be just doing an else?
        // Because in the previous condition, we modified the high or low and now how can we check with modified one?
        if (v[high] >= v[mid]) {
            // Number lies in the sorted side
            if (v[mid] <= number && v[high] >= number) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int findPivot(vector<int>& v)
{
    int low = 0;
    int high = v.size() - 1;

    // Here we don't check for the equal case
    while (low < high) {
        int mid = low + (high - low) / 2;

        // In the above function, we tried to check the mid with
        // both start and end values to find the side which was sorted.
        // Here we always check with the 0th index and eliminate the
        // range which is already sorted
        if (v[mid] >= v[0]) {   // All the values upto this point is sorted
            low = mid + 1;
        } else {
            high = mid;  // Not mid - 1
        }
    }

    return low;
}

int searchSortedRotatedArrayUsingPivot(vector<int>& v, int number)
{
    int pivot = findPivot(v);

    int low = 0;
    int high = v.size() - 1;

    if (v[pivot] <= number && number <= v[high]) {
        low = pivot;
    } else {
        high = pivot - 1;
    }

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (v[mid] == number) {
            return mid;
        } else if (v[mid] > number) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> v = {7, 8, 9, 1, 2, 3, 4, 5, 6};

    cout << searchSortedRotatedArray(v, 1) << std::endl;
    cout << searchSortedRotatedArray(v, 7) << std::endl;
    cout << searchSortedRotatedArray(v, 6) << std::endl;
    cout << searchSortedRotatedArray(v, 4) << std::endl;
    cout << searchSortedRotatedArray(v, 10) << std::endl;

    cout << std::endl;

    cout << searchSortedRotatedArrayUsingPivot(v, 1) << std::endl;
    cout << searchSortedRotatedArrayUsingPivot(v, 7) << std::endl;
    cout << searchSortedRotatedArrayUsingPivot(v, 6) << std::endl;
    cout << searchSortedRotatedArrayUsingPivot(v, 4) << std::endl;
    cout << searchSortedRotatedArrayUsingPivot(v, 10) << std::endl;

    return 0;
}
