//

#include <iostream>
#include <vector>

using namespace std;

bool isArraySorted(vector<int> &arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i-1]) {

        } else {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << isArraySorted(v) << endl;

    v.clear();
    v = {2, 1,3, 2, 8};
    cout << isArraySorted(v) << endl;

    v.clear();
    v = {1, 2, 3, 5, 6, 6};
    cout << isArraySorted(v) << endl;

    return 0;
}