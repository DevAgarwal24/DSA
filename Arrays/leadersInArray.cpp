// https://www.codingninjas.com/studio/problems/superior-elements_6783446

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// Brute Force
// Pick an element and check if a number greater than it exists to it's right or not
// T.C = O(N*N)
// S.C = O(N) / O(1) depending on how you put it
#if 0
vector<int> leadersInArray(vector<int> &arr)
{
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++) {
        bool isLeader = true;
        for (int j = i+1; j < arr.size(); j++) {
            if (arr[j] > arr[i]) {
                isLeader = false;
                break;
            }
        }

        if (isLeader) {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}
#endif

// Optimal Solution
// We know that the last element will always be the leader because there is no other element
// to its right
// To find any other leader, that number should be greater than the all the numbers to the right
// Start from the back, find the maximum number, and if the element is greater than maximum then,
// that element is the leader
// T.C = O(N)
// S.C = O(N) / O(1)
vector<int> leadersInArray(vector<int> &arr)
{
    vector<int> ans;
    int maxNum = INT_MIN;

    for (int i = arr.size()-1; i >= 0; i--) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
            ans.push_back(maxNum);
        }
    }

    reverse(ans.begin(), ans.end());

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
    vector<int> v = {10, 22, 12, 3, 0, 6};
    vector<int> ans = leadersInArray(v);

    printArray(ans);

    v.clear();
    ans.clear();

    v = {6, 7, 2, 1, 0};
    ans = leadersInArray(v);
    printArray(ans);

    return 0;
}