//
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Brute Force
// Iterate over all the elements in a nested for loop to find the sum of all the sub-arrays
// T.C = O(N*N)
// S.C = O(1)
// Some solution mention this solution as the better solution because for the Brute force, they will
// have start index and end index and then the thrid loop will go from start to end to find the sum.
#if 0
long long maxSubarraySum(vector<int> &arr)
{
    long long maxSum = LLONG_MIN;

    for (int i = 0; i < arr.size(); i++) {
        long long sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum < 0 ? 0 : maxSum;
}
#endif

// Optimal Solution
// Kadane's Algorithm
// Intuition
// We add a value at ith index to the sum and update the maxSum
// But if by adding the value at ith index reduces the sum and the sum becomes
// less than 0, then there is no point of taking all the values uptil the ith index
// because together they redunced the sum to less than 0 and by keeping them we will only
// reduce the sum of the next elements
// Carrying forward a positive sum will increase the overall sum, but neglecting a negative
// sum will increase the overall sum
// So, just ignore all the values till ith index when the sum is less than 0 and make the 
// sum 0 again and continue iterating over the next elements
// T.C = O(N)
// S.C = O(1)
long long maxSubarraySum(vector<int> &arr) {
    int n = arr.size();

    long long maxSum = LLONG_MIN;
    long long sum = 0;

    int sIdx = -1;
    int eIdx = -1;

    for (int i = 0; i < n; i++) {
        if (sum == 0) {
            sIdx = i;
        }

        sum += arr[i];

        if (sum >= maxSum) {
            maxSum = sum;
            eIdx = i;
        }

        // If sum is less than 0, there is no point of adding all the elements
        // till that point to the sum, because it will reduce the overall sum
        if (sum < 0) {
            sum = 0;
        }
    }

    if (maxSum > 0) {
        cout << sIdx << " " << eIdx << endl;
    } else {
        cout << "Empty subarray" << endl;
    }
    

    return maxSum < 0 ? 0 : maxSum;
}

int main()
{
    vector<int> v = {1, 2, 7, -4, 3, 2, -10, 9, 1};
    cout << maxSubarraySum(v) << endl;

    v.clear();
    v = {-7, -8, -16, -4, -8, -5, -7, -11, -10, -12, -4, -6, -4, -16, -10};
    cout << maxSubarraySum(v) << endl;

    return 0;
}