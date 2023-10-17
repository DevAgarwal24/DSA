// https://leetcode.com/problems/majority-element-ii/description/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Brute Force
// Using hashing and counting
// T.C = O(N)
// S.C = O(N)
#if 0
vector<int> majorityElement(vector<int> &arr) {
    unordered_map<int, int> m;
    vector<int> ans;

    for (auto i : arr) {
        if (m.find(i) == m.end()) {
            m[i] = 1;
        } else {
            m[i]++;
        }
    }

    for (auto i : m) {
        if (i.second > arr.size()/3) {
            ans.push_back(i.first);
        }
    }

    return ans;
}
#endif

// The following solution doesn't give a better time complexity but rather tries to solve the
// problem in O(1) space
// When we are trying to find the majority elements, and especially in this case where we need
// to find the elements which occurs more than n/3 times, there can be at-most 2 majority elements
// because if two numbers are greater than n/3, then the third will definitely be less than 2n/3
// (considering the case with just 3 different numbers)
// The idea here is to keep the size of the map to 2 and not increment it beyond size 2, to save
// the space.
// We add the element in the map and its count, but when the size of the map is more than 2, we
// reduce the count of each element by 1. If the count of any element is 0, remove that element
// from the map.
// Doing the above steps, we try to make sure that the elements that appear more than n/3 times,
// will be left in the array. But there can be cases when none of the numbers are majority but the
// map still has some elements left. That's when we iterate the array again and check if the
// memebers in the map are really greater than n/3.
vector<int> majorityElement(vector<int> &arr) {
    unordered_map<int, int> m;
    vector<int> ans;

    for (auto i : arr) {
        if (m.find(i) == m.end()) {
            m[i] = 1;
        } else {
            m[i]++;
        }

        if (m.size() > 2) {
            unordered_map<int, int> tmp;
            for (auto itr : m) {
                if (itr.second > 1) {
                    tmp[itr.first] = itr.second - 1;
                }
            }
            m = tmp;
        }
    }

    for (auto i : m) {
        int count = 0;
        for (auto j : arr) {
            if (j == i.first) count++;
        }
        if (count > arr.size()/3) {
            ans.push_back(i.first);
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
    vector<int> v = {3, 2, 3};
    vector<int> ans = majorityElement(v);
    printArray(ans);    // 3

    v.clear(); ans.clear();
    v = {1, 2, 3, 4};
    ans = majorityElement(v);
    printArray(ans);    // []

    v.clear(); ans.clear();
    v = {1, 2, 2, 3, 1, 1, 1, 2, 1};
    ans = majorityElement(v);
    printArray(ans);    // 1

    v.clear(); ans.clear();
    v = {1, 2};
    ans = majorityElement(v);
    printArray(ans);    // 1 2

    return 0;
}