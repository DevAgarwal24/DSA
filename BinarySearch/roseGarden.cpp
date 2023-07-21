// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
// https://www.codingninjas.com/studio/problems/rose-garden_2248080?leftPanelTab=1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible (vector<int>& arr, int day, int k, int m) {
	int count = 0;
	int boquets = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] <= day) {
			count++;
		} else {
			boquets += (count/k);
			count = 0;
		}
	}

	boquets += (count/k);

	if (boquets >= m) {
		return true;
	}

	return false;
}

int roseGarden(vector<int> arr, int k, int m)
{
	if (arr.size() < k*m) {
		return -1;
	}

	int low = *min_element(arr.begin(), arr.end());
	int high = *max_element(arr.begin(), arr.end());

	int ans;

	while (low <= high) {
		int mid = low + (high - low)/2;

		if (isPossible(arr, mid, k, m)) {
			ans = mid;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return ans;
}

int main()
{
	vector<int> v = {1, 2, 1, 2, 7, 2, 2, 3, 1};

    cout << roseGarden(v, 3, 2) << endl;	// 3

    v.clear();
	v = {1, 1, 1, 1};
    cout << roseGarden(v, 1, 1) << endl;	// 1

	return 0;
}
