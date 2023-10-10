// https://leetcode.com/problems/spiral-matrix/
// https://www.codingninjas.com/studio/problems/spiral-matrix_6922069

#include <iostream>
#include <vector>

using namespace std;

// T.C = O(N*M)
// S.C = O(N*M)
vector<int> spiralMatrix(vector<vector<int>> &mat) {
    vector<int> ans;

    int left = 0;
    int right = mat[0].size() - 1;
    int top = 0;
    int bottom = mat.size() - 1;

    while (top <= bottom && left <= right) {
        for (int col = left; col <= right; col++) {
            ans.push_back(mat[top][col]);
        }
        top++;

        for (int row = top; row <= bottom; row++) {
            ans.push_back(mat[row][right]);
        }
        right--;

        // To cover edge cases
        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                ans.push_back(mat[bottom][col]);
            }
            bottom--;
        }

        // To cover edge cases
        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                ans.push_back(mat[row][left]);
            }
            left++;
        }
    }

    return ans;
}

void printArray(vector<int> &arr) {
    for (int i : arr) {
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    vector<vector<int>> matrix = {{1,  2,  3,  4,  5,  6},
                                  {20, 21, 22, 23, 24, 7},
                                  {19, 32, 33, 34, 25, 8},
                                  {18, 31, 36, 35, 26, 9},
                                  {17, 30, 29, 28, 27, 10},
                                  {16, 15, 14 ,13 ,12, 11}};

    vector<int> ans = spiralMatrix(matrix);
    printArray(ans);

    vector<vector<int>> matrix2 = {{1, 2, 3, 4},
                                   {5, 6, 7, 8},
                                   {9, 10, 11, 12}};

    ans.clear();
    ans = spiralMatrix(matrix2);
    printArray(ans);

    return 0;
}