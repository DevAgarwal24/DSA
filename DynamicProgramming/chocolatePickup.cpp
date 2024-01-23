//
// https://www.codingninjas.com/studio/problems/chocolate-pickup_3125885

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive
// T.C = O(3^n * 3^n)
// S.C = O(n)
#if 0
int solve(int r, int c, int i, int j1, int j2, vector<vector<int>> &grid) {
    if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -100000000;
    if (i == r-1) {
        if (j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    int tmpAns = INT_MIN;

    for (int a = -1; a <= 1; a++) {
        for (int b = -1; b <= 1; b++) {
            if (j1 == j2) tmpAns = max(tmpAns, grid[i][j1] + solve(r, c, i+1, j1+a, j2+b, grid));
            else tmpAns = max(tmpAns, grid[i][j1] + grid[i][j2] + solve(r, c, i+1, j1+a, j2+b, grid));
        }
    }

    return tmpAns;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return solve(r, c, 0, 0, c-1, grid);
}
#endif

// Memoization
// T.C = O(n*m*m) * 9, 9 because for each j1 and j2 we've to check 9 different cases
// S.C = O(n*m*m) + O(n)
#if 0
int solve(int r, int c, int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &arr) {
    if (j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) return -100000000;
    if (i == r-1) {
        if (j1 == j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if (arr[i][j1][j2] != -1) return arr[i][j1][j2]; 

    int tmpAns = INT_MIN;

    for (int a = -1; a <= 1; a++) {
        for (int b = -1; b <= 1; b++) {
            if (j1 == j2) tmpAns = max(tmpAns, grid[i][j1] + solve(r, c, i+1, j1+a, j2+b, grid, arr));
            else tmpAns = max(tmpAns, grid[i][j1] + grid[i][j2] + solve(r, c, i+1, j1+a, j2+b, grid, arr));
        }
    }

    return arr[i][j1][j2] = tmpAns;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> arr(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solve(r, c, 0, 0, c-1, grid, arr);
}
#endif

// Tabulation
// T.C = O(n*m*m*9)
// S.C = O(n*m*m)
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> arr(r, vector<vector<int>>(c, vector<int>(c, 0)));
    for (int j1 = 0; j1 < c; j1++) {
        for (int j2 = 0; j2 < c; j2++) {
            if (j1 == j2) arr[r-1][j1][j2] = grid[r-1][j1];
            else arr[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    for (int i = r-2; i >= 0; i--) {
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                int ans = INT_MIN;
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        if (j1+a < 0 || j1+a >= c || j2+b < 0 || j2+b >= c) continue;
                        if (j1 == j2) ans = max(ans, grid[i][j1] + arr[i+1][j1+a][j2+b]);
                        else ans = max(ans, grid[i][j1] + grid[i][j2] + arr[i+1][j1+a][j2+b]);
                    }
                }
                arr[i][j1][j2] = ans;
            }
        }
    }

    return arr[0][0][c-1];
}

// Space optimization
// For this we'll need the 2d matrix


int main() {
    vector<vector<int>> grid = {{2, 3, 1, 2},
                                {3, 4, 2, 2},
                                {5, 6, 3, 5}};

    cout << maximumChocolates(grid.size(), grid[0].size(), grid) << endl;   // 21


    grid.clear();
    grid = {{1, 1},
            {1, 2}};

    cout << maximumChocolates(grid.size(), grid[0].size(), grid) << endl;   // 5

    return 0;
}