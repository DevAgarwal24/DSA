// https://leetcode.com/problems/two-sum/
// https://www.codingninjas.com/studio/problems/reading_6845742

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Brute Force
// Iterate over the elements and check if for that element target - elem exist in the array
#if 0
string twoSum(vector<int> arr, int target)
{
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[j] == target - arr[i]) {
                return "YES";
            }
        }
    }

    return "NO";
}
#endif

// Better Approach
// Hashing
// Use a map to store the elements and then check if target - elem is present in the map
// Here instead of iterating over the array again, we just use hashing to get the value
// T.C = O(NlogN), for ordered map
//       O(N) or O(N*N), for unordered map depending on the best or worst case scenario
// S.C = O(N)
#if 0
string twoSum(vector<int> arr, int target)
{
    map<int, int> m;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (m.find(target-arr[i]) != m.end()) {
            return "YES";
        } else {
            m.insert(make_pair(arr[i], i));
        }
    }

    return "NO";
}
#endif

// Optimal Solution
// Two pointer approach
// This is slightly better than the hashing approach as it doesn't use any extra space
// Sort the array and then use greedy method to find the solution
// Keep one pointer at start index and the other pointer at the end index
// Check if the values sum up to the target, if not move the pointers depending on whether the sum is
// greater or lesser than the target
// T.C = O(NlogN) + O(N)
// S.C = O(1)
string twoSum(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());

    int n = arr.size();

    int low = 0;
    int high = n-1;

    while (low < high) {
        if (arr[low] + arr[high] == target) {
            return "YES";
        } else if (arr[low] + arr[high] > target) {
            high--;
        } else {
            low++;
        }
    }

    return "NO";
}

int main()
{
    vector<int> v = {2, 6, 5, 8, 11};
    cout << twoSum(v, 14) << endl;

    v.clear();
    v = {1, 2, 3, 4, 5};
    cout << twoSum(v, 10) << endl;

    return 0;
}
