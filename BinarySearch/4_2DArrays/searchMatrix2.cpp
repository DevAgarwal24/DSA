// https://leetcode.com/problems/search-a-2d-matrix-ii/description/
//

// The difference here from search Matrix is that the rows and colums are sorted
// individually. The whole matrix is not sorted.
// The binary search solution will be to do binary search on each row to check if
// the value is present.
// Time complexity = O(nlogm)

// Here I provide not the biary search solution, but a more optimised solution
// Time complexity = O(n+m)

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> searchMatrix(vector<vector<int>> &matrix, int num) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // We can start from the corners from where we have continuously increasing values
    int row = 0;    // rows - 1
    int col = cols - 1; // 0

    while (row < rows && col >= 0) {
        if (matrix[row][col] == num) {
            return {row, col};
        } else if (matrix[row][col] > num) {      // Keep eliminating either row/col because its sorted
            col--;
        } else {
            row++;
        }
    }

    return {-1, -1};
}

int main()
{
    vector<vector<int>> matrix = { {1, 4, 7, 11, 15},
                                   {2, 5, 8, 12, 19},
                                   {3, 6, 9, 16, 22},
                                   {10, 13, 14, 17, 24},
                                   {18, 21, 23, 26, 30}
                                 };

    pair<int, int> p;

    p = searchMatrix(matrix, 14);
    cout << p.first << " " << p.second << endl;

    p = searchMatrix(matrix, 1);
    cout << p.first << " " << p.second << endl;

    p = searchMatrix(matrix, 18);
    cout << p.first << " " << p.second << endl;

    p = searchMatrix(matrix, 30);
    cout << p.first << " " << p.second << endl;

    p = searchMatrix(matrix, 39);
    cout << p.first << " " << p.second << endl;
}
