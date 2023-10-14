// https://leetcode.com/problems/subarray-sum-equals-k/description/
// https://www.codingninjas.com/studio/problems/subarray-sums-i_1467103

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Brute Force
// This solution includes findind the sum of all the sub-arrays and incrementing
// The counter when the sum equals k
// T.C = O(N*N)
// S.C = O(1)
#if 0
int subararySum(vector<int> &v, int k) {
    int count = 0;

    for (int i = 0; i < v.size(); i++) {
        long sum = 0;
        for (int j = i; j < v.size(); j++) {
            sum += v[j];
            if (sum == k) count++;
        }
    }

    return count;
}
#endif

// Optimal Solution
// Here the concept used in the longest subarray with sum k will be used.
// Instead of storing the last index where the count was equal to sum - k in the map,
// we store the occurrences of the subarrays with sum equal to sum - k
// We also need to keep in mind of first checking if the diff exist in the map and then
// modify the content of the map, otherwise for cases when k = 0, we'll get incorrect sum
// T.C = O(NlogN)
// S.C = O(N)
int subararySum(vector<int> &v, int k) {
    int count = 0;
    map<long, int> m;
    long preSum = 0;

    if (k == 0 && v.size() == 1) return 0;

    // This is requrired otherwises count will be one less for certain cases
    // when the sum becomes 0 for a subarray and only then it's added to the map
    m.insert({0, 1});

    for (int i = 0; i < v.size(); i++) {
        preSum += v[i];
        int diff = preSum - k;
        if (m.find(diff) != m.end()) {
            count += m[diff];
        }

        if (m.find(preSum) == m.end()) {
            m.insert({preSum, 1});
        } else {
            m[preSum]++;
        }
    }

    return count;
}

int main()
{
    vector<int> v = {1};
    cout << subararySum(v, 0) << endl;      // 0

    v.clear();
    v = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout << subararySum(v, 3) << endl;      // 8

    v.clear();
    v = {-1, -1, 1};
    cout << subararySum(v, 1) << endl;      // 1

    return 0;
}