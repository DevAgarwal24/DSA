// https://leetcode.com/problems/majority-element/
// https://www.codingninjas.com/studio/problems/majority-element_6783241

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Brute Force
// Pick an element and scan through the entire array to see if the element's count
// is > N / 2
// T.C = O(N*N)
// S.C = O(1)
#if 0
int majorityElement(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        int count = 0;

        for (int j = 0; j < v.size(); j++) {
            if (v[i] == v[j]) {
                count++;
            }
        }

        if (count > v.size()/2) return v[i];
    }

    return -1;
}
#endif

// Better Solution
// Hashing
// T.C = O(N) + O(N) for unordered map best case
//       O(N*N) + O(N) for unordered map worst case
//       O(NlogN) + O(N) for ordered map
// S.C = O(N/2) = O(N)
#if 0
int majorityElement(vector<int> &v)
{
    unordered_map<int, int> m;

    int maxCount = 0;
    int majorElem = -1;

    for (int i : v) {
        if (m.find(i) == m.end()) {
            m[i] = 1;
        } else {
            m[i]++;
        }
    }

    for (auto &a : m) {
		if (a.second > maxCount) {
			maxCount = a.second;
			majorElem = a.first;
		}
	}

    return majorElem;
}
#endif

// Optimal Solution
// Moore's Voting Algorithm
// This algorithm is based on the intuition of picking an element and checking if that element
// can be a major or not
// An element is selected from an array and for every occurrence of the element in the array, a
// counter is incremented and for occurence of any other element the counter is decremented.
// This process continues, until the count becomes zero again.
// If the count becomes zero, it signifies that the element that we selected is not the majority
// element till that point in the array because otherwise the count wouldn't have become zero.
// Pick the next element in the array as our new element and repeat the counting process either
// till we encounter the count to be zero or till the end of the array.
// Whatever element we have in the end may or may not be the majority element depending on whether
// the array has a majority element.
// If the array gurantees to have a majority element then the selected element will always be the majority
// element otherwise the selected element may or may not be the answer.
// T.C = O(N)
// S.C = O(1)
int majorityElement(vector<int> &v) {
    int majorElem = v[0];
    int count = 1;

    for (int i = 1; i < v.size(); i++) {
        if (count == 0) {
            majorElem = v[i];
            count = 1;
        } else if (v[i] == majorElem) {
            count++;
        } else {
            count--;
        }
    }

    count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == majorElem) count++;
    }

    if (count > v.size() / 2) return majorElem;

    return -1;
}

int main()
{
    vector<int> v = {2, 2, 1, 3, 1, 1, 3, 1, 1};
    cout << majorityElement(v) << endl;

    v.clear();
    v = {2, 2, 3, 1, 3, 2, 2};
    cout << majorityElement(v) << endl;

    return 0;
}