// Same as House Robber
// https://leetcode.com/problems/house-robber/
// https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261

#include <iostream>
#include <vector>
using namespace std;

// Memoization
// T.C = O(N)
// S.C = O(N) + O(N)
#if 0
int solve(int n, vector<int> &nums, vector<int> &arr) {
    if (n == 0) return nums[0];
    if (n < 0) return 0;

    if (arr[n] != -1) return arr[n];

    int pick = nums[n] + solve(n-2, nums, arr);
    int nonPick = 0 + solve(n-1, nums, arr);

    arr[n] = max(pick, nonPick);
    return arr[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> arr(n, -1);
    return solve(n-1, nums, arr);
}
#endif

// Tabulation
// T.C = O(N)
// S.C = O(N)
#if 0
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> arr(n, 0);
    int sLast = 0;
    int last = nums[0];

    for (int i = 1; i < n; i++) {
        int pick = nums[i] + sLast;
        int nonPick = last;

        int curr = max(pick, nonPick);

        sLast = last;
        last = curr;
    }

    return last;
}
#endif

// Space optimization on tabulation
// T.C = O(N)
// S.C = O(1)
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int sLast = 0;
    int last = nums[0];

    for (int i = 1; i < n; i++) {
        int pick = nums[i] + sLast;
        int nonPick = last;

        int curr = max(pick, nonPick);

        sLast = last;
        last = curr;
    }

    return last;
}

int main()
{
    vector<int> nums = {2, 1};
    cout << maximumNonAdjacentSum(nums) << endl;    // 2

    nums.clear();
    nums = {1, 2, 3, 5, 4};
    cout << maximumNonAdjacentSum(nums) << endl;    // 8

    nums.clear();
    nums = {6, 5, 10, 8, 2};
    cout << maximumNonAdjacentSum(nums) << endl;    // 18

    nums.clear();
    nums = {10};
    cout << maximumNonAdjacentSum(nums) << endl;
    
    return 0;
}