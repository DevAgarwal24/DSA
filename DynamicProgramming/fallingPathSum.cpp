// https://leetcode.com/problems/minimum-falling-path-sum/
// https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Recursive
// T.C = O(3^n) where n is number of rows
// S.C = O(n)
#if 0
int solve(int n, int m, int i, int j, vector<vector<int>> &arr) {
    if (j < 0 || j >= m) return INT_MIN;
    if (i == 0) return arr[i][j];

    int up = solve(n, m, i-1, j, arr);
    int upLeft = solve(n, m, i-1, j-1, arr);
    int upRight = solve(n, m, i-1, j+1, arr);

    return arr[i][j] + max(up, max(upLeft, upRight));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int maxPath = INT_MIN;

    for (int i = 0; i < m; i++) {
        int sum = solve(n, m, n-1, i, matrix);
        maxPath = max(maxPath, sum);
    }

    return maxPath;
}
#endif

// Memoization
// T.C = O(n*m) because there will be n*m states at max and once we solve for a value, we fetch in O(1)
// S.C = O(n*m) + O(n)
#if 0
int solve(int n, int m, int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &arr) {
    if (j < 0 || j >= m) return INT_MIN;
    if (i == 0) return matrix[i][j];

    if (arr[i][j] != -1) return arr[i][j];

    int up = solve(n, m, i-1, j, matrix, arr);
    int upLeft = solve(n, m, i-1, j-1, matrix, arr);
    int upRight = solve(n, m, i-1, j+1, matrix, arr);

    return arr[i][j] = matrix[i][j] + max(up, max(upLeft, upRight));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int maxPath = INT_MIN;
    vector<vector<int>> arr(n, vector<int>(m, -1));

    for (int i = 0; i < m; i++) {
        int sum = solve(n, m, n-1, i, matrix, arr);
        maxPath = max(maxPath, sum);
    }

    return maxPath;
}
#endif

// Tabulation
// T.C = O(n*m)
// S.C = O(n*m)
#if 0
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int maxPath = INT_MIN;
    vector<vector<int>> arr(n, vector<int>(m, -1));
    for (int st = 0; st < m; st++) {
        arr[0][st] = matrix[0][st];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = INT_MIN, ld = INT_MIN, rd = INT_MIN;
            up = arr[i-1][j];
            if (j-1 >= 0) ld = arr[i-1][j-1];
            if (j+1 < m)  rd = arr[i-1][j+1];

            arr[i][j] = matrix[i][j] + max(up, max(ld, rd));
        }
    }

    return *max_element(arr[n-1].begin(), arr[n-1].end());
}
#endif

// Space Optimization
// T.C = O(n*m)
// S.C = O(n)
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> arr(m, 0);
    for (int st = 0; st < m; st++) {
        arr[st] = matrix[0][st];
    }

    for (int i = 1; i < n; i++) {
        vector<int> tmp(m, 0);
        for (int j = 0; j < m; j++) {
            int up = INT_MIN, ld = INT_MIN, rd = INT_MIN;
            up = arr[j];
            if (j-1 >= 0) ld = arr[j-1];
            if (j+1 < m)  rd = arr[j+1];

            tmp[j] = matrix[i][j] + max(up, max(ld, rd));
        }
        arr = tmp;
    }

    return *max_element(arr.begin(), arr.end());
}

int main() {
    vector<vector<int>> matrix =    {{-9999, -9888, -9777, -9666, -9555},
                                     {1, 10, 2, 4, 5},
                                     {-9999, -9888, -9777, -9666, -9555},
                                     {0, 0, 0, 0, 0},
                                     {-99, -98, -97, -96, -95}};

    cout << getMaxPathSum(matrix) << std::endl;     // -19200

    return 0;
}