// https://leetcode.com/problems/unique-paths/
// https://www.codingninjas.com/studio/problems/unique-paths_1081470

#include <iostream>
#include <vector>
using namespace std;

// Recursive
// T.C = O(2^(m*n)) [Each box will have two possible ways and there are m*n boxes]
// S.C = O(m+n) [Auxillary stack space equal to the length of the path]
#if 0
int solve(int m, int n, int i, int j) {
    if (i == m-1 && j == n-1) return 1;

    if (i != m-1 && j != n-1) return solve(m, n, i+1, j) + solve(m, n, i, j+1);
    else if (i == m-1) return solve(m, n, i, j+1);
    else return solve(m, n, i+1, j);
}

int uniquePaths(int m, int n) {
    return solve(m, n, 0, 0);
}
#endif

// Recursive - Another way to code
// This solution is slower than the previous one on online platforms possibly
// because we're having function calls for the cases where we simply return 0
#if 0
int solve(int m, int n, int i, int j) {
    if (i == m-1 && j == n-1) return 1;
    if (i >= m || j >= n) return 0;

    return solve(m, n, i+1, j) + solve(m, n, i, j+1);
}

int uniquePaths(int m, int n) {
    return solve(m, n, 0, 0);
}
#endif

// Memoization
// T.C = O(m*n)
// S.C = O(m+n) + O(m*n)
#if 0
int solve(int m, int n, int i, int j, vector<vector<int>> &arr) {
    if (i == m-1 && j == n-1) return arr[i][j] = 1;

    if (arr[i][j] != -1) return arr[i][j];

    if (i != m-1 && j != n-1) return arr[i][j] = solve(m, n, i+1, j, arr) + solve(m, n, i, j+1, arr);
    else if (i == m-1) return arr[i][j] = solve(m, n, i, j+1, arr);
    else return arr[i][j] = solve(m, n, i+1, j, arr);
}

int uniquePaths(int m, int n) {
    vector<vector<int>> arr(m, vector<int>(n, -1));
    return solve(m, n, 0, 0, arr);
}
#endif

// Tabulation
// T.C = O(m*n)
// S.C = O(m*n)
#if 0
int uniquePaths(int m, int n) {
    vector<vector<int>> arr(m, vector<int>(n, 0));
    arr[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            if (i != 0 && j != 0) arr[i][j] = arr[i-1][j] + arr[i][j-1];
            else if (i == 0) arr[i][j] = arr[i][j-1];
            else if (j == 0) arr[i][j] = arr[i-1][j];
        }
    }

    return arr[m-1][n-1];
}
#endif

// Space Optimization
// T.C = O(m*n)
// S.C = O(n)
int uniquePaths(int m, int n) {
    vector<int> arr(n, 0);
    arr[0] = 1;

    for (int i = 0; i < m; i++) {
        vector<int> tmp(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                tmp[j] = 1;
                continue;
            }
            if (i != 0 && j != 0) tmp[j] = arr[j] + tmp[j-1];
            else if (i == 0) tmp[j] = tmp[j-1];
            else if (j == 0) tmp[j] = arr[j];
        }
        arr = tmp;
    }

    return arr[n-1];
}

int main()
{
    cout << uniquePaths(2, 2) << endl;  // 2
    cout << uniquePaths(1, 1) << endl;  // 1
    cout << uniquePaths(3, 4) << endl;  // 10
    cout << uniquePaths(7, 6) << endl;  // 462

    return 0;
}