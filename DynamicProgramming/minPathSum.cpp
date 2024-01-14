// https://leetcode.com/problems/minimum-path-sum/description/
// https://www.codingninjas.com/studio/problems/minimum-path-sum_985349

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive
#if 0
int solve(int n, int m, int i, int j, vector<vector<int>> &grid) {
    if (i == n-1 && j == m-1) return grid[i][j];
    if (i >= n || j >= m) return INT_MAX;

    int right = solve(n, m, i, j+1, grid);
    int down  = solve(n, m, i+1, j, grid);

    return grid[i][j] + min(right, down);
}

int minSumPath(vector<vector<int>> &grid) {
    return solve(grid.size(), grid[0].size(), 0, 0, grid);
}
#endif

// Memoization
#if 0
int solve(int n, int m, int i, int j, vector<vector<int>> &grid, vector<vector<int>> &arr) {
    if (i == n-1 && j == m-1) return grid[i][j];
    if (i >= n || j >= m) return INT_MAX;

    if (arr[i][j] != -1) return arr[i][j];

    int right = solve(n, m, i, j+1, grid, arr);
    int down  = solve(n, m, i+1, j, grid, arr);

    return arr[i][j] = grid[i][j] + min(right, down);
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> arr(n, vector<int>(m, -1));
    return solve(n, m, 0, 0, grid, arr);
}
#endif

// Tabulation
#if 0
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> arr(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                arr[i][j] = grid[i][j];
                continue;
            }

            int left = INT_MAX, up = INT_MAX;
            if (i > 0) up = arr[i-1][j];
            if (j > 0) left = arr[i][j-1];

            arr[i][j] = grid[i][j] + min(up, left);
        }
    }

    return arr[n-1][m-1];
}
#endif

// Space Optimization
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<int> arr(m, 0);
    
    for (int i = 0; i < n; i++) {
        vector<int> tmp(m, 0);
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                tmp[j] = grid[i][j];
                continue;
            }

            int left = INT_MAX, up = INT_MAX;
            if (i > 0) up = arr[j];
            if (j > 0) left = tmp[j-1];

            tmp[j] = grid[i][j] + min(up, left);
        }
        arr = tmp;
    }

    return arr[m-1];
}

int main() {
    vector<vector<int>> v = {{6, 11, 6, 1},
                             {11, 3, 8, 7},
                             {18, 3, 18, 1}, 
                             {8, 9, 6, 6}, 
                             {4, 14, 15, 11}};
    
    cout << minSumPath(v) << endl;      // 49

    v.clear();
    v =     {{20, 7, 18, 6, 6, 5},
             {5, 3, 17, 12, 17, 7},
             {20, 7, 4, 2, 20, 8},
             {2, 12, 18, 2, 17, 7}}; 

    cout << minSumPath(v) << endl;      // 67

    return 0;
}