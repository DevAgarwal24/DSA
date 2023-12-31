// https://www.codingninjas.com/studio/problems/frog-jump_3621012

#include <iostream>
#include <vector>
using namespace std;

#define M 1000000007

// Recursive Solution
#if 0
int solve(int n, vector<int> &heights) {
    if (n == 0) return 0;
    if (n == 1) return abs(heights[1] - heights[0]);
    
    int left = (solve(n-1, heights) + abs(heights[n] - heights[n-1])) % M;
    int right = (solve(n-2, heights) + abs(heights[n] - heights[n-2])) % M;
    
    return min(left, right);
}

int frogJump(int n, vector<int> &heights) {
    return solve(n-1, heights);
}
#endif

// Memoization
#if 0
int solve(int n, vector<int> &heights, vector<int> &arr) {
    if (n == 0) return 0;
    if (arr[n] != -1) return arr[n];
    int left = (solve(n-1, heights, arr) + abs(heights[n] - heights[n-1])) % M;
    if (n > 1) {
        int right = (solve(n-2, heights, arr) + abs(heights[n] - heights[n-2])) % M;
        arr[n] = min(left, right);
        return arr[n];
    }

    arr[n] = left;
    return arr[n];
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> arr(n, -1);
    arr[0] = 0;
    return solve(n-1, heights, arr);
}
#endif

// Tabulation
#if 0
int frogJump(int n, vector<int> &heights)
{
    n = n-1;
    if (n == 0) return 0;
    if (n == 1) return abs(heights[1] - heights[0]);

    vector<int> arr(n+1, 0);

    arr[0] = 0;
    arr[1] = abs(heights[1] - heights[0]);

    for (int i = 2; i <= n; i++) {
        int left = (arr[i-1] + abs(heights[i] - heights[i-1])) % M;
        int right = (arr[i-2] + abs(heights[i] - heights[i-2])) % M;

        arr[i] = min(left, right);
    }

    return arr[n];
}
#endif

// Space Optimization
int frogJump(int n, vector<int> &heights)
{
    n = n-1;
    if (n == 0) return 0;
    if (n == 1) return abs(heights[1] - heights[0]);

    vector<int> arr(n+1, 0);

    int prevTwo = 0;
    int prevOne = abs(heights[1] - heights[0]);

    for (int i = 2; i <= n; i++) {
        int left = (prevOne + abs(heights[i] - heights[i-1])) % M;
        int right = (prevTwo + abs(heights[i] - heights[i-2])) % M;

        int curr = min(left, right);
        prevTwo = prevOne;
        prevOne = curr;
    }

    return prevOne;
}

int main()
{
    vector<int> heights = {7, 4, 4, 2, 6, 6, 3, 4};
    cout << frogJump(8, heights) << endl;   // 7
}
