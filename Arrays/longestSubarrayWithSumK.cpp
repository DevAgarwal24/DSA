// 
// https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Brute Force
// Generate all the subarrays and then check if the sum = k
// Start at i = 0 and then j will start from i
// Find the sum of all the elements from i to j, and check for the length
// T.C = O(N*N*N)
// S.C = O(1)

// Modified brute force
// Keep on adding to the sum when incrementing j
// Return the length of the maximum subarray
// T.C = O(N*N)
// S.C = O(1)
#if 0
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int maxCount = 0;

    for (int i = 0; i < a.size(); i++) {
        long long sum = 0;
        int count = 0;
        for (int j = i; j < a.size(); j++) {
            sum += a[j];
            if (sum <= k) {
                count++;
                if (sum == k) {
                    if (count > maxCount) maxCount = count;
                }
            } else {
                count = 0;
                break;  // breaking when sum > k
            }
        }
    }

    return maxCount;
}
#endif

// Better Approach
// Hashing using an unordered map
// Find the sum of elements from 0 to ith index and store it in an unordered map with key as the sum and the
// value as index
// Check if key "sum - k" is available in the map, if yes it means that there can be a subarray with a sum k
// The idea here is that at any i, if the sum of the subarray has to be k, then there should be a subarray
// with sum = total sum till i - k
// The code can fail in cases when there are 0s in the array because then the value in the map will be overwritten
// T.C = O(NlogN) for ordered map
//       O(N*1) for unordered map in best case and O(N*N) in worst case
// S.C = O(N)
// This solution with modifications done for 0s will work for array with negative elements as well and will be
// the most optimal solution for that question
int longestSubarrayWithSumK(vector<int> arr, long long k) {
    unordered_map<long long, int> m;

    int maxCount = 0;
    long long sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (m.find(sum) == m.end()) {
            m.insert(make_pair(sum, i));
        }

        long long diff = sum - k;
        if (diff == 0) {
            maxCount = max(maxCount, i + 1);
        } else if (m.find(diff) != m.end()) {
            maxCount = max(maxCount, i - m[diff]);
        }
    }

    return maxCount;
}


// Optimal Solution
// Two pointer approach
// Keep one pointer fixed and keep moving the other pointer and sum the elements
// Move the fixed pointer only when the sum is greater than the required sum of the sub array
// T.C = O(N) and worst case O(2N)
// S.C = O(1)
// This solution works with only positive integers
#if 0
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0;
    int right = 0;

    int maxCount = 0;
    long long sum = 0;

    while (right < a.size()) {
        sum += a[right];

        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        
        if (sum == k) {
            maxCount = max(maxCount, right-left+1);
        }

        right++;
    }

    return maxCount;
}
#endif

int main()
{
    vector<int> v = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    cout << longestSubarrayWithSumK(v, 3) << endl;		// 3

    v.clear();
    v = {-1, 0, 1, 1, -1, -1, 0};
    cout << longestSubarrayWithSumK(v, 0) << endl;		// 6

    return 0;
}
