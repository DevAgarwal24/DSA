// https://leetcode.com/problems/kth-missing-positive-number/
// https://www.codingninjas.com/studio/problems/kth-missing-element_893215

#include <iostream>
#include <vector>

using namespace std;

int missingK(vector<int> &vec, int n, int k) {
    int tDiff = 0;

    if (vec[0] != 1) {
        tDiff = vec[0] - 0 - 1;
    }

    if (tDiff >= k) {
        return (vec[0] - tDiff + k - 1);
    }

    for (int i = 1; i < n; i++) {
        tDiff += vec[i] - vec[i-1] - 1;

        if (tDiff >= k) {
            return (vec[i] - tDiff + k - 1);
        }
    }

    if (tDiff == 0) {
        return vec[n-1] + k;
    }

    return -1;
}

int missingK2(vector<int> &vec, int n, int k) {
    for (int i = 0; i < n; i++) {
	    if (vec[i] <= k) {
		    k++;
	    } else {
            break;
	    }
    }

    return k;
}

int missingK3(vector<int> &vec, int n, int k) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low)/2;

	    // This tells how many numbers are missing
        int diff = vec[mid] - (mid + 1);

        // If the numbers missing are less than the kth missing to be found
        // it will mean that the number will be on the left side
        if (diff < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // low will point to the index where the missing numbers are greater than k and
    // high will point to the index where the missing numbers are less than k
    // answer will be vec[high] + extra numbers required
    // But there can be a case where high can point to -1
    // extra number required = (k - missing) where missing = vec[high] - (high + 1)
    // Simplyfying,
    // vec[high] + (k - (vec[high] - (high + 1)))

    return high + 1 + k;	// this is same as low + k
}

int main()
{
	vector<int> v = {4, 7, 9, 10};

    cout << missingK(v, v.size(), 1) << endl;   // 1
    cout << missingK2(v, v.size(), 1) << endl;
    cout << missingK3(v, v.size(), 1) << endl;

    cout << endl;
    cout << missingK(v, v.size(), 4) << endl;	// 5
    cout << missingK2(v, v.size(), 4) << endl;	// 5
    cout << missingK3(v, v.size(), 4) << endl;

	return 0;
}
