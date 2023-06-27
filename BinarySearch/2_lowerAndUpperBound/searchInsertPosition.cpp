// https://practice.geeksforgeeks.org/problems/search-insert-position-of-k-in-a-sorted-array/1
// https://leetcode.com/problems/search-insert-position/

#include <iostream>
#include <vector>

using namespace std;

//
// This is same as lowerbound
//
int searchInsertPosition(vector<int>& v, int number) {
    int pos = v.size();

    int low = 0;
    int high = v.size() - 1;

    while(low <= high) {
        int mid = low + (high - low)/2;

        if (v[mid] >= number) {
            pos = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return pos;
}

int main()
{
    vector<int> v = {1, 2, 4, 7};

    cout << searchInsertPosition(v, 6) << std::endl;

    return 0;
}
