// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/submissions/
// https://www.codingninjas.com/studio/problems/capacity-to-ship-packages-within-d-days_1229379?leftPanelTab=0

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool isPossible (vector<int>& weights, int d, int n) {
    int days = 1;
    int sum = 0;

    for (int i = 0; i < weights.size(); i++) {
        if (sum + weights[i] <= n) {
            sum += weights[i];
        } else {
            days++;
            sum = weights[i];
            if (days > d) {
                return false;
            }
        }
    }

    return true;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = std::accumulate(weights.begin(), weights.end(), 0);

    while (low <= high) {
        int mid = low + (high - low)/2;
    
        if (isPossible(weights, d, mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
	vector<int> v = {5, 4, 5, 2, 3, 4, 5, 6};

	cout << leastWeightCapacity(v, 5) << endl;	// 9

    v.clear();
	v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << leastWeightCapacity(v, 1) << endl;	// 55

	return 0;
}
