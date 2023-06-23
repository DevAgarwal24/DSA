#include <iostream>
#include <vector>
using namespace std;

int BinarySearchIterative(const vector<int>& v, int number)
{
    int low = 0;
    int high = v.size() - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low)/2;

        if (v[mid] == number) {
            return mid;
        } else if (v[mid] > number) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int BinarySearchRecursive(const vector<int>& v, int number, int low, int high) {

    int mid = low + (high - low)/2;

    if (v[mid] == number) {
        return mid;
    }

    if ((low <= high) &&
         v[mid] > number) {
        return BinarySearchRecursive(v, number, low, mid-1);
    }

    if ((low <= high) &&
         v[mid] < number) {
        return BinarySearchRecursive(v, number, mid+1, high);
    }

    return -1;
}

int main()
{
    vector<int> v = {3, 4, 6, 7, 9, 12, 16, 17};

    for(int i = 0; i < v.size(); i++) {
        cout << BinarySearchIterative(v, v[v.size()-i-1]) << " "
             << BinarySearchRecursive(v, v[v.size()-i-1], 0, v.size()-1) << std::endl;
    }

    cout << BinarySearchIterative(v, 10) << " " << BinarySearchRecursive(v, 10, 0, v.size()) << std::endl;

    return 0;
}