// https://practice.geeksforgeeks.org/problems/peak-element/1 -> This problem can have repeated elements
// https://leetcode.com/problems/find-peak-element/			  -> This expects no repetion of consecutive elements

#include <iostream>
#include <vector>

using namespace std;

int peakIterative(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			if ( v[i] > v[i+1]) {
				return i;
			}
		} else if (i == v.size() - 1) {
			if (v[i] > v[i-1]) {
				return i;
			}
        } else {
			if (v[i] > v[i-1] && v[i] > v[i+1]) {
				return i;
			}
		}
    }

#if 0
	for (int i = 0; i < v.size(); i++) {
		if (((i == 0) || (v[i] > v[i-1]) &&
             (i == v.size() - 1) || (v[i] > v[i+1]))) {
			return i;
        }
    }
#endif

	return -1;
}

int peakIndexMountainArray(vector<int>& v) {
    int low = 0;
    int high = v.size() - 1;

    if (v.size() == 1) return 0;
    if (v[low] > v[low+1]) return low;
	if (v[high] > v[high-1]) return high;

    low++;
	high--;

    while (low <= high) {
        int mid = low + (high - low)/2;

        // if (v[mid-1] < v[mid] && v[mid] > v[mid+1]) {
        //     return mid;
        // }
        
        // if (v[mid-1] > v[mid] && v[mid] > v[mid+1]) {    // decreasing function, on the right of peak
        //     high = mid - 1;
        // } else if (v[mid-1] < v[mid] && v[mid] < v[mid+1]) {    // increasing function, on the left of peak
        //     low = mid + 1;
        // } // The case where both left and right elements are greater than mid should not occur. That's a minima. [This occurs]
        // else {
        //     Go anywhere
        //     high = mid - 1;  
        // }

        // Both the solution works
        // Actually we need not check if the previous element is also less or greater than the current element
        // We can either be on the increasing line or the decreasing line
        if (v[mid-1] < v[mid] && v[mid] > v[mid+1]) {
            return mid;
        }

        if (v[mid] < v[mid+1]) {
            low = mid + 1;
        } else {				// As we're not checking v[mid] > v[mid+1], the code doesn't fail for the trough case
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> v = {0, 10, 7, 6, 5, 4, 3, 2, 1};

    cout << peakIndexMountainArray(v) << std::endl;     // 1
    cout << peakIterative(v) << std::endl;				// 1
    cout << std::endl;

    v.clear();
    v = {0, 1, 2, 3, 4, 5, 6, 10, 2};
    cout << peakIndexMountainArray(v) << std::endl;     // 7
    cout << peakIterative(v) << std::endl;				// 7
    cout << std::endl;


    v.clear();
    v = {0, 1, 0};
    cout << peakIndexMountainArray(v) << std::endl;     // 1
    cout << peakIterative(v) << std::endl;				// 1
    cout << std::endl;


    v.clear();
    v = {0, 1, 2, 7, 6, 5, 4, 3, 2, 1, 0};
    cout << peakIndexMountainArray(v) << std::endl;     // 3
    cout << peakIterative(v) << std::endl;				// 3
    cout << std::endl;


    v.clear();
    v = {0, 1, 2, 3, 4, 5, 6};
    cout << peakIndexMountainArray(v) << std::endl;		// 6
    cout << peakIterative(v) << std::endl;				// 6
    cout << std::endl;

    v.clear();
    v = {7};
    cout << peakIndexMountainArray(v) << std::endl;		// 1
    cout << peakIterative(v) << std::endl;				// 1
    cout << std::endl;

	// Answers in this case can be different based on the size of the array
    v.clear();
    v = {1, 2, 1, 2, 1, 2, 1, 2, 0};
    cout << peakIndexMountainArray(v) << std::endl;
    cout << peakIterative(v) << std::endl;
    cout << std::endl;

    // This is a special case where our code will fail when there are multiple peaks
    // In this case we land in a trough and both left and right element are
    // greater than the mid
    // Modifications are needed to handle this case for our commented code
    // But in the current uncommented code, as we always do a modification
    // without checking the other side, if the if condition fails, we're good.
    v.clear();
    v = {1, 5, 1, 2, 1};
    cout << peakIndexMountainArray(v) << std::endl;
    cout << peakIterative(v) << std::endl;
    cout << std::endl;

	// This is a wrong test case
    // Consecutive numbers can never be equal    
	v.clear();
    v = {1, 1, 1, 1, 1, 1};
    cout << peakIndexMountainArray(v) << std::endl;		// -1
    cout << peakIterative(v) << std::endl;				// -1
    cout << std::endl;

    // This is also a wrong test case
    // but iterative still gives an answer
    v.clear();
    v = {1, 2, 3, 4, 4, 4, 5, 1, 2, 0};
    cout << peakIndexMountainArray(v) << std::endl;		// 6
    cout << peakIterative(v) << std::endl;				// 6
    cout << std::endl;
}
