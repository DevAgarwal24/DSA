// https://leetcode.com/problems/median-of-two-sorted-arrays/
// https://www.codingninjas.com/studio/problems/median-of-two-sorted-arrays_985294

#include <iostream>
#include <vector>

using namespace std;

double medianOfSortedArrays(vector<int>& v1, vector<int>& v2) {
    if (v1.size() > v2.size()) {
        return medianOfSortedArrays(v2, v1);
    }

    int n1 = v1.size();
    int n2 = v2.size();

    if (n1 == 0) {
        if (n2 % 2 == 0) {
            return (double)v2[(n2-1)/2] + (double)v2[n2/2];
        } else {
            return (double)v2[n2/2];
        }
    }

    int start = 0;      // Represents the minimum number of elements we can take from the smaller array
    int end = n1;       // Represents the maximum number of elements we can take from the smaller array

    int total = (n1 + n2 + 1) / 2;      // + 1 to take care of both even and odd cases

    while (start <= end) {
        int mid = start + (end - start)/2;

        int cut1 = mid;
        int cut2 = total - cut1;

        int l1 = cut1 == 0 ? INT32_MIN : v1[cut1-1];
        int l2 = cut2 == 0 ? INT32_MIN : v2[cut2-1];

        int r1 = cut1 == n1 ? INT32_MAX : v1[cut1];
        int r2 = cut2 == n2 ? INT32_MAX : v2[cut2];

        if (l1 <= r2 && l2 <= r1) {
            if ((n1 + n2) % 2 == 0) {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else {
                return (double)max(l1, l2);
            }
        } else if (l1 > r2) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return 0.0;
}

int main()
{
    vector<int> v1 = {1, 3, 4, 7, 10, 12};
    vector<int> v2 = {2, 3, 6, 15};

    cout << medianOfSortedArrays(v1, v2) << std::endl;      // 5
    cout << medianOfSortedArrays(v2, v1) << std::endl;      // 5

    cout << std::endl;

    v1.clear(); v2.clear();
    v1 = {7, 12, 14, 15};
    v2 = {1, 2, 3, 4, 9, 11};

    cout << medianOfSortedArrays(v1, v2) << std::endl;      // 8
    cout << medianOfSortedArrays(v2, v1) << std::endl;      // 8

    cout << std::endl;

    v1.push_back(16);

    cout << medianOfSortedArrays(v1, v2) << std::endl;      // 9
    cout << medianOfSortedArrays(v2, v1) << std::endl;      // 9

}