#include <iostream>
#include <vector>
using namespace std;

// Recursive Solution with memoization
// Time Complexity = O(N)
// Space Complexity = O(N) + O(N)
int f(int n, vector<int> &dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = f(n-1, dp) + f(n-2, dp);
}

// Recusive to Tabulation
// T.C = O(N)
// S.C = O(N)
int f(int n) {
    vector<int> dp(n+1, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

// Optimizing for space
// T.C = O(N)
// S.C = O(1)
int f1(int n) {
    int prev2 = 0, prev = 1;
    for (int i = 2; i <= n; i++) {
        int curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main()
{
    int n;
    cout << "Input: ";
    cin >> n;

    vector<int> dp(n+1, -1);
    cout << "The " << n << "th number (0 based indexing) in the fibonacci series is: \n";
    cout << f(n, dp) << endl;
    cout << f(n) << endl;
    cout << f1(n) << endl;

    return 0;
}