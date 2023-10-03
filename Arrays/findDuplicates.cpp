//
// https://www.codingninjas.com/studio/problems/find-duplicate-in-array_1112602

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Better Solution
// Hashing
// Create a hash-map and keep adding elements to the map
// If the value is already available in the map, then it occurs more than once and is the duplicate
// T.C = O(NlogN)
// S.C = O(N)
#if 0
int findDuplicate(vector<int> &arr){
    int n = arr.size();
	map<int, int> m;

	for (int i = 0; i < n; i++) {
		if (m.find(arr[i]) != m.end()) {
			return arr[i];
		} else {
			m[arr[i]] = 1;
		}
	}

	return -1;
}
#endif

// Optimal Solution
// The intuition here is to get an index based on the current value and then increment the value
// at the index by n
// If a number has been repeated then we'll get the same index twice and the value of at the index
// will be incremented multiple times.
// Iterating over the array again, we can find the number of times value at an index has been incemented
// As the array contains value from 1 to N-1, the indexes will always be in that range and the value at
// index 0 will never be considered and incremented, but we still do the search from 0 anyways
// T.C = O(2N)
// S.C = O(1)
int findDuplicate(vector<int> &arr){
    int n = arr.size();
	for (int i = 0; i < n; i++) {
		int idx = arr[i] % n;
		arr[idx] += n;
	}

	for (int i = 0; i < n; i++) {
		if (arr[i]/n >= 2) {
			return i;
		}
	}

	return -1;
}


int main()
{
    vector<int> v = {4, 5, 8, 4, 6, 1, 2, 3, 7, 4};
    cout << findDuplicate(v) << endl;

    v.clear();
    v = {2, 2, 2, 5, 6, 7};
    cout << findDuplicate(v) << endl;

    return 0;
}