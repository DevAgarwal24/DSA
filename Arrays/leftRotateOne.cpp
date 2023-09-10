// https://www.codingninjas.com/studio/problems/left-rotate-an-array-by-one_5026278

#include <iostream>
#include <vector>

using namespace std;

void leftRotateOne(vector<int> &arr) {
    int firstElem = arr[0];

    for(int i = 0; i < arr.size() - 1; i++) {
        arr[i] = arr[i+1];
    }

    arr[arr.size()-1] = firstElem;
}

void printArray(vector<int> &arr) {
    for (int i : arr) {
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    leftRotateOne(v);
    printArray(v);

    v.clear();
    v = {5, 4, 3, 2, 1};
    leftRotateOne(v);
    printArray(v);

    v.clear();
    v = {2};
    leftRotateOne(v);
    printArray(v);

    return 0;
}
