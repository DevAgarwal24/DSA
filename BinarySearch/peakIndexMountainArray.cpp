#include <iostream>
#include <vector>

using namespace std;

int peakIndexMountainArray(vector<int>& v) {
    int low = 0;
    int high = v.size() - 1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        // if (v[mid-1] < v[mid] && v[mid] > v[mid+1]) {
        //     return mid;
        // }
        
        // if (v[mid-1] > v[mid] && v[mid] > v[mid+1]) {    // decreasing function, on the right of peak
        //     high = mid - 1;
        // } else if (v[mid-1] < v[mid] && v[mid] < v[mid+1]) {    // increasing function, on the left of peak
        //     low = mid + 1;
        // } // The case where both left and right elements are greater than mid should not occur. That's a minima.

        // Both the solution works
        // Actually we need not check if the previous element is also less or greater than the current element
        // We can either be on the increasing line or the decreasing line
        if (v[mid-1] < v[mid] && v[mid] > v[mid+1]) {
            return mid;
        }

        if (v[mid] < v[mid+1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> v = {0, 10, 7, 6, 5, 4, 3, 2, 1};

    cout << peakIndexMountainArray(v) << std::endl;     // 1

    v.clear();
    v = {0, 1, 2, 3, 4, 5, 6, 10, 2};
    cout << peakIndexMountainArray(v) << std::endl;     // 7

    v.clear();
    v = {0, 1, 0};
    cout << peakIndexMountainArray(v) << std::endl;     // 1

    v.clear();
    v = {0, 1, 2, 7, 6, 5, 4, 3, 2, 1, 0};
    cout << peakIndexMountainArray(v) << std::endl;     // 3
}