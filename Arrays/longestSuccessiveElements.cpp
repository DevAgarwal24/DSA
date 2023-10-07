// https://leetcode.com/problems/longest-consecutive-sequence/
// https://www.codingninjas.com/studio/problems/longest-successive-elements_6811740

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Brute Force
// Pick a number, and then iterate over the array again and again, until you keep on finding the
// next elements in the array
// T.C = O(N*N)
// S.C = O(1)
bool linearSearch(vector<int> &v, int num) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == num) {
            return true;
        }
    }

    return false;
}

#if 0
int longestSuccessiveElements(vector<int> &a) {
    int longest = 1;
    for (int i = 0; i < a.size(); i++) {
        int x = a[i];
        int count = 1;
        while (linearSearch(a, x+1)) {
            x++;
            count++;
        }

        longest = max(longest, count);
    }

    return longest;
}
#endif

// Better Solution
// Sort the arrays so that if there are any consequtive elements, then they will occur together
// Pick an element and check if the next element exists (ignore duplicates), and if it does,
// increment the count, otherwise start again from the current element
// T.C = O(NlogN) + O(N)
// S.C = O(1)
#if 0
int longestSuccessiveElements(vector<int> &a) {
    int longest = 1;
    int currCnt = 1;
    int lastSmaller = INT_MIN;

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == lastSmaller) {
            continue;
        } else if (a[i]-1 == lastSmaller) {
            currCnt++;
            longest = max(longest, currCnt);
            lastSmaller = a[i];
        } else {
            currCnt = 1;
            lastSmaller = a[i];
        }
    }

    return longest;
}
#endif

// Optimal Solution
// We are distorting the array in the better solution. We'll try to not modify the array
// Have a set data structure and put all the elements in it
// Insertion in unordered set takes O(1) when there is no collision and O(N) in case of collisions
// Iterate over the elements in the set
// pick an element and check if the element - 1 exists in the set. If it exists, it means that
// our current element cannot be a starting point. If we would have taken that element and checked
// for element + 1, then our solution will become the brute force solution.
// Just because we check if the element - 1 exists, and not work on the current element, the solution differs
// The search in best case is O(1) and worst case, when collision happens, O(logN)
// If an element with no previous element is found, check consecutive elements exists by finding the
// next elements from the set data structure
// T.C = O(N) + O(2N) only if there is no collision in the unordered set
// S.C = O(N)
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) {
        return 0;
    }

    int longest = 1;
    unordered_set<int> st;

    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    for (auto it : st) {
        if (st.find(it-1) == st.end()) {
            int elem = it;
            int count = 1;
            while (st.find(elem+1) != st.end()) {
                elem++;
                count++;
            }
            longest = max(longest, count);
        }
    }

    return longest;
}

int main()
{
    vector<int> v = {100, 1, 2, 3, 102, 101, 1, 3, 2, 103, 4};
    cout << longestSuccessiveElements(v) << endl;

    return 0;
}