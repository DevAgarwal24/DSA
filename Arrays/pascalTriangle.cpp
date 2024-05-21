// https://leetcode.com/problems/pascals-triangle

#include <iostream>
#include <vector>

using namespace std;

// A simple approach to solve this will be to write the triangle in the right-angled form.
// We observe that from the second row onwards, and except for the first and last column, the value of a
// cell is equal to the sum of the value of the cell above it, and the cell towards it's left diagonal.
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pt;

    for (int i = 0; i < numRows; i++) {
        vector<int> tmp(i+1, 1);
        for (int j = 1; j < i; j++) {
            tmp[j] = pt[i-1][j-1] + pt[i-1][j];
        }

        pt.push_back(tmp);
    }

    return pt;
}

int main() {
    vector<vector<int>> pascalTriangle;

    pascalTriangle = generate(6);

    for (auto i : pascalTriangle) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}