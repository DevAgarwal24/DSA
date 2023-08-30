// median in a row wise sorted matrix

//
//

// log(2^32) * (N * log(M))
// = 32 * (N log(M)) 

#include <iostream>
#include <vector>

using namespace std;

int countSmallerThanEqualToNum(vector<int> &arr, int num) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (arr[mid] > num) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int median(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 1;
    int high = 1000000000;

    while (low <= high) {
        int mid = low + (high - low)/2;

        // Check how many numbers are <= mid in the matrix
        int count = 0;
        for (int i = 0; i < matrix.size(); i++) {
            count += countSmallerThanEqualToNum(matrix[i], mid);    // U.B will give the index where arr[idx] > mid
        }

        if (count <= (n*m)/2) {     // Try to reach the middle
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

int main()
{
    vector<vector<int>> matrix = { {1, 3, 6},
                                   {2, 6, 9},
                                   {3, 6, 9}
                                 };

    cout << median(matrix) << endl;

    return 0;
}