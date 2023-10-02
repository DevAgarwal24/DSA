// https://leetcode.com/problems/rearrange-array-elements-by-sign/
// https://www.codingninjas.com/studio/problems/alternate-numbers_6783445

#include <iostream>
#include <vector>

using namespace std;

// Brute Force
// Take two new vector/arrays for storing the positive and the negative elements
// Iterate over the given array and fill the positive and the negative arrays
// Using the positive and the negative array, modify the initial array
// T.C = O(2N)
// S.C = O(N)

// Optimal Solution
// We cannot get rid of that extra space. So, we try to get rid of the extra iteration over the array
// Create a new array
// Keep two pointer for the positive and negative indexes
// Iterate over the given array and if the value is positive, add it to the location pointed by the
// positive index, otherwise negative index
// T.C = O(N)
// S.C = O(N)
vector<int> rearrangeBySign(vector<int>&arr) {
    vector<int> ans(arr.size(), 0);

    int posIdx = 0;
    int negIdx = 1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            ans[posIdx] = arr[i];
            posIdx += 2;
        } else {
            ans[negIdx] = arr[i];
            negIdx += 2;
        }
    }

    return ans;
}

void printArray(vector<int> &arr) {
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    vector<int> ans;

    v = {1, 2, -3, -1, -2, 3};
    ans = rearrangeBySign(v);
    printArray(ans);

    v.clear();
    ans.clear();

    v = {14020, 14050, 17933, -10263, -28274, -32383, 4857, 23042, -7266, -32760, 18024, -12942, 21059, 5995, -29076, -950};
    ans = rearrangeBySign(v);
    printArray(ans);

    return 0;
}