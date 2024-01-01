// https://www.codingninjas.com/studio/problems/minimal-cost_8180930

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Memoization
#if 0
int solve(int n, int k, vector<int> &height, vector<int> &arr) {
    if (n == 0) return 0;
    if (n == 1) return abs(height[1] - height[0]);

    if (arr[n] != -1) return arr[n];
    int minValue = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (n >= i) {
            int value = solve(n-i, k, height, arr) + abs(height[n] - height[n-i]);
            minValue = min(minValue, value);
        }
    }
    arr[n] = minValue;
    return minValue;
}

int frogJump(int n, int k, vector<int> &height) {
    vector<int> arr(n, -1);
    return solve(n-1, k, height, arr);    
}
#endif

// Tabulation
int frogJump(int n, int k, vector<int> &height){
    if (n == 1) return 0;
    if (n == 2) return abs(height[1] - height[0]);

    n = n-1;
    vector<int> arr(n+1, 0);
    arr[0] = 0;
    arr[1] = abs(height[1] - height[0]);

    for (int i = 2; i <= n; i++) {
        int minValue = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (j > i) break;
            int value = arr[i-j] + abs(height[i] - height[i-j]);
            minValue = min(minValue, value);
        }
        arr[i] = minValue;
    }

    return arr[n];
}

int main()
{
    vector<int> height = {1, 4, 8, 7, 5};
    cout << frogJump(5, 4, height) << endl;

    return 0;
}