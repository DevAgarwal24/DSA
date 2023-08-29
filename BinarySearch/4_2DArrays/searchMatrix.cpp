//
//

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix (vector<vector<int>> &matrix, int num) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = 0;
    int high = rows * cols - 1;     // Hypothetically flattening the matrix

    while (low <= high) {
        int mid = low + (high - low)/2;

        int row = mid / cols;
        int col = mid % cols;

        if (matrix[row][col] == num) {
            return true;
        } else if (matrix[row][col] > num) {
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = { {3, 4, 7, 9},
                                   {12, 13, 16, 18},
                                   {20, 21, 23, 29}
                                 };

    cout << searchMatrix(matrix, 23) << endl;
    cout << searchMatrix(matrix, 18) << endl;
    cout << searchMatrix(matrix, 5) << endl;

    return 0;
}