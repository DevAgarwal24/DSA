// https://www.codingninjas.com/studio/problems/k-th-element-of-2-sorted-array_1164159?leftPanelTab=1

#include <iostream>
#include <vector>

using namespace std;

int kthElementOfSortedArrays(vector<int>& v1, vector<int>& v2, int k) {
    if (v1.size() > v2.size()) {
        return kthElementOfSortedArrays(v2, v1, k);
    }

    if (v1.size() == 0) {
        return v2[k-1];
    }

    int n = v1.size();
    int m = v2.size();

    int low = max(0, k-m);
    int high = min(k, n);

    while (low <= high) {
        int cut1 = low + (high - low)/2;
        int cut2 = k - cut1;

        int l1 = cut1 == 0 ? INT32_MIN : v1[cut1 - 1];
        int l2 = cut2 == 0 ? INT32_MIN : v2[cut2 - 1];

        int r1 = cut1 == n ? INT32_MAX : v1[cut1];
        int r2 = cut2 == m ? INT32_MAX : v2[cut2];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > r2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return 1;
}

int main()
{
    vector<int> v1 = {1, 3, 4, 7, 10, 12};
    vector<int> v2 = {2, 3, 6, 15};

    cout << kthElementOfSortedArrays(v1, v2, 3) << std::endl;      // 3
    cout << kthElementOfSortedArrays(v2, v1, 3) << std::endl;      // 3

    cout << std::endl;

    v1.clear(); v2.clear();
    v1 = {7, 12, 14, 15};
    v2 = {1, 2, 3, 4, 9, 11};

    cout << kthElementOfSortedArrays(v1, v2, 8) << std::endl;      // 12
    cout << kthElementOfSortedArrays(v2, v1, 8) << std::endl;      // 12

    cout << std::endl;

    v1.push_back(16);

    cout << kthElementOfSortedArrays(v1, v2, 5) << std::endl;      // 7
    cout << kthElementOfSortedArrays(v2, v1, 5) << std::endl;      // 7

}