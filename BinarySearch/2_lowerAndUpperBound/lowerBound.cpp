// https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
// https://practice.geeksforgeeks.org/problems/ceil-the-floor2802/1

#include <iostream>
#include <vector>
using namespace std;

int lowerBoundIterative(vector<int>& v, int number)
{
    int idx = v.size();

    int low = 0;
    int high = v.size() - 1;

    while(low <= high) {
        int mid = low + (high - low)/2;

        if (v[mid] >= number) {
            idx = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return idx;
}

void lowerBoundRecursive(vector<int>& v, int number, int low, int high, int &lb)
{
    if (low > high) {
        return;
    }

    int mid = low + (high - low)/2;

    if (v[mid] >= number) {
        high = mid - 1;
        lb = mid;
        return lowerBoundRecursive(v, number, low, high, lb);
    } else {
        low = mid + 1;
        return lowerBoundRecursive(v, number, low, high, lb);
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};

    int lb = v.size();

    cout << lowerBoundIterative(v, 0) << " ";
    lowerBoundRecursive(v, 0, 0, v.size(), lb);
    cout << lb << std::endl;

    lb = v.size();
    cout << lowerBoundIterative(v, 9) << " ";
    lowerBoundRecursive(v, 9, 0, v.size(), lb);
    cout << lb << std::endl;

    lb = v.size();
    cout << lowerBoundIterative(v, 12) << " ";
    lowerBoundRecursive(v, 12, 0, v.size(), lb);
    cout << lb << std::endl;

    lb = v.size();
    cout << lowerBoundIterative(v, 8) << " ";
    lowerBoundRecursive(v, 8, 0, v.size(), lb);
    cout << lb << std::endl;

    return 0;
}
