// 
//

#include <iostream>
#include <vector>

using namespace std;

int lowerBound(vector<int> &v, int num) {
    int low = 0;
    int high = v.size() - 1;

    int lb = v.size();

    while (low <= high) {
        int mid = low + (high - low)/2;
        if (v[mid] >= num) {
            lb = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return lb;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int max1s = 0;
    int index = -1;

    for (int i = 0; i < n; i++) {
        int lb = lowerBound(matrix[i], 1);
        int count1s = m - lb;
        if (count1s > max1s) {
            max1s = count1s;
            index = i;
        }
    }

    return index;
}

int main()
{
    vector<vector<int>> matrix = { {0, 0, 1, 1, 1},
                                   {0, 0, 0, 0, 0},
                                   {0, 1, 1, 1, 1},
                                   {0, 0, 0, 0, 1},
                                   {0, 1, 1, 1, 1}
                                 };

    cout << rowWithMax1s(matrix, 5, 5) << endl;
}