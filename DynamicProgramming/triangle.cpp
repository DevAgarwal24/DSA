// https://leetcode.com/problems/triangle/
// https://www.codingninjas.com/studio/problems/triangle_1229398

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Recursive
// T.C = 
// S.C = 
#if 0
int solve(int n, int i, int j, vector<vector<int>> &triangle) {
	if (i == n-1) return triangle[i][j];
	if (i > n-1) return 0;

	int down = solve(n, i+1, j, triangle);
	int diag = solve(n, i+1, j+1, triangle);

	return triangle[i][j] + min(down, diag);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	return solve(n, 0, 0, triangle);
}
#endif

// Memoization
// T.C = 
// S.C = 
#if 0
int solve(int n, int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &arr) {
	if (i == n-1) return triangle[i][j];
	if (i > n-1) return 0;

	if (arr[i][j] != -1) return arr[i][j];

	int down = solve(n, i+1, j, triangle, arr);
	int diag = solve(n, i+1, j+1, triangle, arr);

	return arr[i][j] = triangle[i][j] + min(down, diag);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> arr(n, vector<int>(n, -1));
	return solve(n, 0, 0, triangle, arr);
}
#endif 

// Tabulation
// T.C = 
// S.C = 
#if 0
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> arr(n, vector<int>(n, 0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			if (i == 0 && j == 0) {
				arr[i][j] = triangle[i][j];
				continue;
			}

			int top = INT_MAX;
			int diag = INT_MAX;

			if (i > 0) {
				if (j != i) top = arr[i-1][j];
				if (j > 0)  diag = arr[i-1][j-1];
			}

			arr[i][j] = triangle[i][j] + min(top, diag);
		}
	}

	return *min_element(arr[n-1].begin(), arr[n-1].end());
}
#endif

// Space Optimization
// T.C = 
// S.C = 
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int> arr(n, 0);
	
	for (int i = 0; i < n; i++) {
		vector<int> tmp(n, 0);
		for (int j = 0; j < i+1; j++) {
			if (i == 0 && j == 0) {
				tmp[j] = triangle[i][j];
				continue;
			}

			int top = INT_MAX;
			int diag = INT_MAX;

			if (i > 0) {
				if (j != i) top = arr[j];
				if (j > 0)  diag = arr[j-1];
			}

			tmp[j] = triangle[i][j] + min(top, diag);
		}
		arr = tmp;
	}

	return *min_element(arr.begin(), arr.end());
}


int main() {

    vector<vector<int>> triangle = {{2},
                                    {6, 8},
                                    {8, 5, 2},
                                    {3, 8, 7, 3},
                                    {7, 8, 1, 4, 5},
                                    {7, 2, 3, 1, 9, 6}};

    cout << minimumPathSum(triangle, triangle.size()) << endl;  // 20

    return 0;
}