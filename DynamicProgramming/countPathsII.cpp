// https://leetcode.com/problems/unique-paths-ii/
// https://www.codingninjas.com/studio/problems/unique-paths-ii_977241

#include <iostream>
#include <vector>
using namespace std;

// Recursive
// T.C = O(2^(m*n)) [Each box will have two possible ways and there are m*n boxes]
// S.C = O(m+n) [Auxillary stack space equal to the length of the path]
#if 0
int solve(int n, int m, int i, int j, vector<vector<int>> &mat) {
    if (i < n && j < m && mat[i][j] == -1) return 0;
    if (i == m-1 && j == n-1) return 1;

    if (i != m-1 && j != n-1) return solve(m, n, i+1, j, mat) + solve(m, n, i, j+1, mat);
    else if (i == m-1) return solve(m, n, i, j+1, mat);
    else return solve(m, n, i+1, j, mat);
}

int uniquePaths(int n, int m, vector<vector<int>> &mat) {
    return solve(m, n, 0, 0, mat);
}
#endif

// Recursive - Another way to code
// This solution is slower than the previous one on online platforms possibly
// because we're having function calls for the cases where we simply return 0
#if 0
int solve(int n, int m, int i, int j, vector<vector<int>> &mat) {
    if (i < n && j < m && mat[i][j] == -1) return 0;
    if (i == m-1 && j == n-1) return 1;
    if (i >= m || j >= n) return 0;

    return solve(m, n, i+1, j, mat) + solve(m, n, i, j+1, mat);
}

int uniquePaths(int n, int m, vector<vector<int>> &mat) {
    return solve(m, n, 0, 0, mat);
}
#endif

// Memoization
// T.C = O(m*n)
// S.C = O(m+n) + O(m*n)
#if 0
int solve(int n, int m, int i, int j, vector<vector<int>> &mat, vector<vector<int>> &arr) {
    if (i < n && j < m && mat[i][j] == -1) return 0;
    if (i == m-1 && j == n-1) return arr[i][j] = 1;

    if (arr[i][j] != -1) return arr[i][j];

    if (i != m-1 && j != n-1) return arr[i][j] = solve(m, n, i+1, j, mat, arr) + solve(m, n, i, j+1, mat, arr);
    else if (i == m-1) return arr[i][j] = solve(m, n, i, j+1, mat, arr);
    else return arr[i][j] = solve(m, n, i+1, j, mat, arr);
}

int uniquePaths(int n, int m, vector<vector<int>> &mat) {
    vector<vector<int>> arr(m, vector<int>(n, -1));
    return solve(m, n, 0, 0, mat, arr);
}
#endif

// Tabulation
// T.C = O(m*n)
// S.C = O(m*n)
#if 0
int uniquePaths(int n, int m, vector<vector<int>> &mat) {
    vector<vector<int>> arr(m, vector<int>(n, 0));
    arr[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == -1) continue;
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
int uniquePaths(int n, int m, vector<vector<int>> &mat) {
    vector<int> arr(n, 0);

    for (int i = 0; i < m; i++) {
        vector<int> tmp(n, 0);
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == -1) continue;
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
    vector<vector<int>> v = {{0, 0},
                             {0, 0}};
    cout << uniquePaths(2, 2, v) << endl;  // 2

    v.clear();
    v = {{0, 0, 0},
         {0, -1, 0},
         {0, 0, 0}};
    cout << uniquePaths(3, 3, v) << endl;  // 2

    return 0;
}