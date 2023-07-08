// https://www.codingninjas.com/studio/problems/smallest-divisor-with-the-given-limit_1755882?

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPossible(vector<int>& arr, int limit, int n)
{
	int sum = 0;

	for (int i = 0; i < arr.size(); i++) {
		sum += ceil((double)arr[i]/(double)n);
		if (sum > limit) {
			return false;
		}
	}

	return true;
}

int smallestDivisor(vector<int>& arr, int limit)
{
	if (arr.size() > limit) return -1;

	int low = 1;
	int high = *max_element(arr.begin(), arr.end());

	while (low <= high) {
		int mid = low + (high - low)/2;

		if (isPossible(arr, limit, mid)) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return low;
}

int main()
{
	vector<int> v = {1, 2, 3, 4, 5};

	cout << smallestDivisor(v, 8) << endl;	// 3

	v.clear();
	v = {8, 4, 2, 3};
	cout << smallestDivisor(v, 10) << endl;	// 2

	v.clear();
	v = {2, 3, 5, 7, 11};
    cout << smallestDivisor(v, 11) << endl;	// 3

	return 0;
}
