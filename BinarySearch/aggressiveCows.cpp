// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// v = array
// k = no. of cows
// n = min. distance to place them

// In this solution, I will be sorting the array.
// Check for any possible solution where we don't need to sort it.
bool isPossible(vector<int>& v, int k, int n) {

    int cows = 1;
    int cowPos = v[0];

    for(int i = 1; i<v.size(); i++) {
        if (v[i]-cowPos >= n) {
            // place the cow
            cows++;
            if (cows == k) {
                return true;
            }

            cowPos = v[i];
        }
    }

    return false;
}

int aggressiveCows(vector<int>& v, int k) {

	// The minimum distance between two cows will be the distance between any two consequtive stalls
	// hence we sort the stalls here
    sort(v.begin(), v.end());

    auto min = min_element(v.begin(), v.end()); // can take the mininum value directly
    auto max = max_element(v.begin(), v.end()); // can take the maximum value directly

    int low = *min;
    int high = *max - *min;

    int ans = -1;

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (isPossible(v, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 4};

    cout << aggressiveCows(v, 4) << std::endl;  // 1

    v.clear();
    v = {0, 3, 4, 7, 10, 9};
    cout << aggressiveCows(v, 4) << std::endl;  // 3

    v.clear();
    v = {0, 7, 9};
    cout << aggressiveCows(v, 2) << std::endl;  // 9

    v.clear();
    v = {4, 2, 1, 3, 6};
    cout << aggressiveCows(v, 2) << std::endl;  // 5

    return 0;
}
