// https://leetcode.com/problems/find-a-peak-element-ii/
// https://www.codingninjas.com/studio/problems/find-peak-element_7449073

#include <iostream>
#include <vector>

using namespace std;

int peakElement(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = m - 1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        // Find the row with max element for column mid
        int max_row = 0;
        for (int i = 1; i < n; i++) {
            if (matrix[i][mid] > matrix[max_row][mid]) {
                max_row = i;
            }
        }

        // Check if the right and left sides are smaller or not
        bool isLeftSmaller = (mid - 1 < 0) || (matrix[max_row][mid] > matrix[max_row][mid-1]);
        bool isRightSmaller = (mid + 1 == m) || (matrix[max_row][mid] > matrix[max_row][mid+1]);

        if (isLeftSmaller && isRightSmaller) {
            return matrix[max_row][mid];
        }

        if (!isLeftSmaller) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Shouldn't reach here
    return matrix[0][0];
}

int main()
{
    vector<vector<int>> matrix = { {10, 20, 15}, 
                                   {21, 30, 14},
                                   {7, 16, 32}
                                 };

    cout << peakElement(matrix) << endl;

    vector<vector<int>> matrix2 = {{1, 4}, 
                                   {2, 2}
                                  };

    cout << peakElement(matrix2) << endl;
}

