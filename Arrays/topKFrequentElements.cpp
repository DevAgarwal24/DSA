// https://leetcode.com/problems/top-k-frequent-elements/description/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Brute Force
// Hashing
// Storing the count of all the elments in a hash map
// Finding the top k elements with maximum occurrences
// T.C = O(N) + O(k*N)
// S.C = O(N)
#if 0
vector<int> topKFrequent(vector<int> &arr, int k) {
    unordered_map<int, int> m;
    vector<int> ans;

    for (auto i : arr) {
        if (m.find(i) == m.end()) {
            m[i] = 1;
        } else {
            m[i]++;
        }
    }

    for (int i = 1; i <= k; i++) {
        int maxCount = 0;
        int num = -1;
        for (auto j : m) {
            if (j.second > maxCount) {
                maxCount = j.second;
                num = j.first;
            }
        }
        m.erase(num);
        ans.push_back(num);
    }

    return ans;
}
#endif

// Another Solution
// Note that using an ordered map vs unordered map can affect the code performance significantly
// In this solution, we will theoretically try to solve the problem in O(N) time complexity
// This uses some concepts from bucket sort, but with some modifications
// If all the elements in the array are the same, we will get the frequency of the element as
// the size of the array and if all the elements are different, then each element will occur exactly
// once. This 1 and n are the bounds that we'll use.
// In bucket sort, we create an array of size equal to the largest element, but if we take that case,
// even if the size of the array is 5 for example and the elements are way larger, the size of the array
// will be unbounded.
// For our solution, we hence take the possible counts that the numbers in the array can have as the size
// and store the elements that occur those number of times in the vector.
// Then we iterate the vector and take the top k elements
vector<int> topKFrequent(vector<int> &arr, int k) {
    unordered_map<int, int> m;
    vector<int> ans;

    for (auto i : arr) {
        if (m.find(i) == m.end()) {
            m[i] = 1;
        } else {
            m[i]++;
        }
    }

    // Create the array and store the elements that occur a certain number of times
    vector<int> nums[arr.size() + 1];
    for (auto i : m) {
        nums[i.second].push_back(i.first);
    }

    for (int i = arr.size(); i > 0; i--) {
        for (auto j : nums[i]) {
            ans.push_back(j);
            if (ans.size() == k) {
                return ans;
            }
        }
    }

    return ans;
}

void printArray(vector<int> &arr) {
    if (arr.size() == 0) {
        cout << "Majority elements doesn't exist\n";
        return;
    }

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {1, 1, 1, 2, 2, 3};
    vector<int> ans = topKFrequent(v, 2);
    printArray(ans);    // 3

    v.clear(); ans.clear();
    v = {1};
    ans = topKFrequent(v, 1);
    printArray(ans);    // 1

    return 0;
}