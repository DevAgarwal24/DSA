// https://leetcode.com/problems/missing-number/description/

#include <iostream>
#include <vector>

using namespace std;

// Brute Force
// We know that the numbers will be between 0 and N
// Iterate over numbers 0 to N and for each number check if its present in the array or not
// T.C = O(N*N)
// S.C = O(1)

// Better Solution
// Hashing
// Create an array to keep track of numbers that are present
// Iterate over the main array and mark the isVisited[i] as true if i is present
// T.C = O(N) + O(N)
// S.C = O(N)

// Optimal Solution
// 1. Sum approach
// Sum all the numbers in the array and then subtract that from (N*(N+1))/2
// T.C = O(N)
// S.C = O(1)
//
// 2. XOR approach
// a ^ a = 0
// 0 ^ a = a
// We first xor all the numbers from 0 to N and store it in a variable
// Then iterate over the array and xor the numbers with the stored value
// In the end we'll be left with the number that is missing
// The xor approach is better because it will never overflow
// T.C = O(N)
// S.C = O(1)

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    int s = ((n+1)*(n+2)) / 2;

    return s - sum;
}

#if 0
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int xor1 = 0;

    for (int i = 1; i <= n+1; i++) {  // eliminate this loop by doing this operation in the other one itself
        xor1 = xor1 ^ i;
    }

    for (int i = 0; i < n; i++) {
        xor1 = xor1 ^ nums[i];  // xor1 = xor1 ^ (i+1) ^ nums[i];
    }

    return xor1;
}
#endif

int main()
{
    vector<int> v = {1, 2, 4, 5};
    cout << missingNumber(v) << endl;

    return 0;
}