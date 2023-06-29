// https://practice.geeksforgeeks.org/problems/search-in-rotated-array-2/1
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>

using namespace std;

// Here we have to check if the array has the number available
// or not, rather than finding the index
bool searchSortedRotatedArray(vector<int> &v, int number)
{
    int low = 0;
    int high = v.size() - 1;

    while(low <= high) {
        int mid = low + (high - low)/2;

        if (v[mid] == number) {
            return true;
        }

        if (v[low] == v[mid] && v[mid] == v[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }
        
        if (v[low] <= v[mid]) {  // sorted right half
            if (v[low] <= number && number <= v[mid]) { // number lies in this half
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {    // sorted left half
            if (v[mid] <= number && number <= v[high]) {  // number lies in this half
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return false;
}

int main()
{
    vector<int> v = {3, 3, 3, 1, 1, 2, 3, 3, 3, 3, 3, 3, 3};

    cout << std::boolalpha<< searchSortedRotatedArray(v, 1) << std::endl;
    cout << std::boolalpha<< searchSortedRotatedArray(v, 3) << std::endl;
    cout << std::boolalpha<< searchSortedRotatedArray(v, 2) << std::endl;
    cout << std::boolalpha<< searchSortedRotatedArray(v, 5) << std::endl;

    return 0;
}
