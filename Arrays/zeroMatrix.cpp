// https://leetcode.com/problems/set-matrix-zeroes/
// https://www.codingninjas.com/studio/problems/zero-matrix_1171153

#include <iostream>
#include <vector>

using namespace std;

// Brute Force
// Iterate the matrix and whenever a 0 is encountered, convert only the cells which was not already
// 0 to -1
// Iterate the matrix again and convert all -1s t 0s
// T.C = O((n*m)(n+m)) + O(n*m)
// S.C = O(1)
#if 0
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!matrix[i][j]) {
				for (int idx = 0; idx < m; idx++) {
					if (matrix[i][idx]) {
						matrix[i][idx] = -1;
					}
				}
				for (int idx = 0; idx < n; idx++) {
					if (matrix[idx][j]) {
						matrix[idx][j] = -1;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == -1) matrix[i][j] = 0;
		}
	}

	return matrix;
}
#endif

// Better Solution
// We take almost N^3 time to complete the brute force. This is mainly because, when we encounter
// a 0 in the array, at that instant, we try to mark the row and col elemets as -1, which takes additonal
// time.
// Instead of marking the rows and cols as -1, when a zero is encounterd, we create two arrays, one for
// row and other for column, to incate that the particular row or column has encountered 0.
// Iterate the matrix again, and if the row or col array is set, then mark the matrix element as 0
// T.C = O(n*m*2)
// S.C = O(n+m)
#if 0
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

	vector<int> row(n, false);
	vector<int> col(m, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!matrix[i][j]) {
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (row[i] || col[j]) {
				matrix[i][j] = 0;
			}
		}
	}

	return matrix;
}
#endif

// Optimal Solution
// We cannot optimize anymore on the time complexity because n*m time is required to iterate the array
// Instead we try to optimze on the space complexity by moving the row and col arrays inside the matrix
// and utilizing the first row and col of the matrix as the row and col arrays
// Check this video for detailed explanation
// https://youtu.be/N0MgLvceX7M?si=YGSXPzOLYRLgEe-d&t=857
// T.C = O(n*m*2)
// S.C = O(1)
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

	// vector<int> row(n, false); -> matrix[..][0]
	// vector<int> col(m, false); -> matrix[0][..]
	int col0 = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!matrix[i][j]) {
				//row[i] = true;
				matrix[i][0] = 0;
				//col[j] = true;
				if (j != 0)
					matrix[0][j] = 0;
				else
					col0 = 0;
			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (matrix[i][j] != 0)  {
				// Check for row and col
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
				
			}
		}
	}

	if (matrix[0][0] == 0) {
		for (int j = 0; j < m; j++) {
			matrix[0][j] = 0;
		}
	}

	if (col0 == 0) {
		for (int i = 0; i < n; i++) {
			matrix[i][0] = 0;
		}
	}

	return matrix;
}

void printMatrix(vector<vector<int>> &matrix) {
    for (auto i : matrix) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {{6, 5, 1, 6, 8}, 
                                  {2, 8, 0, 7, 5},
                                  {4, 4, 0, 6, 2},
                                  {9, 6, 3, 7, 5}};

    matrix = zeroMatrix(matrix);
    printMatrix(matrix);
}