// https://leetcode.com/problems/rotate-image/
// https://www.codingninjas.com/studio/problems/rotate-the-matrix_6825090

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Brute Force
// Create another temporary matrix
// matrix[row][col] --> tmp[col][n-1-row]
// T.C = O(N*N)
// S.C = O(N*N)
#if 0
vector<vector<int>> rotateMatrix(vector<vector<int>> &mat){
	vector<vector<int>> tmp;
	for (int i = 0; i < mat.size(); i++) {
		vector<int> x(mat[0].size(), 0);
		// for (int j = 0; j < mat[0].size(); j++) {
		// 	x.push_back(mat[i][j]);
		// }
		tmp.push_back(x);
	}
	
	for (int row = 0; row < mat.size(); row++) {
		for (int col = 0; col < mat[0].size(); col++) {
			tmp[col][mat.size()-1-row] = mat[row][col];
		}
	}

	return tmp;
}
#endif

// Optimal Solution
// Try to save the space and do the rotation in-place
// Rotation of a matrix to the right = Transpose of the matrix, and the reversing each row
// T.C = O(n*n) + O(n*n)
// S.C = O(1)
vector<vector<int>> rotateMatrix(vector<vector<int>> &mat){
	// Transpose of the matrix
    // If we do the swap all the element, then it will become the same matrix again
    // That's why, here we swap over a certain range
	for (int i = 0; i < mat.size()-1; i++) {
		for (int j = i+1; j < mat[0].size(); j++) {
			swap(mat[i][j], mat[j][i]);
		}
	}

	// Reverse each row
	for (int i = 0; i < mat.size(); i++) {
		reverse(mat[i].begin(), mat[i].end());
	}

    return mat;
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
    vector<vector<int>> mat =  {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};

    cout << "Input Matrix: \n";
    printMatrix(mat);

    vector<vector<int>> ans = rotateMatrix(mat);
    cout << "\nAfter Rotation: \n";
    printMatrix(ans);

    return 0;
}