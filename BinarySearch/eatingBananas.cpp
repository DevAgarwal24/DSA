// https://leetcode.com/problems/koko-eating-bananas/description/
// https://www.codingninjas.com/studio/problems/minimum-rate-to-eat-bananas_7449064

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> v, int h, int n) {

    for (int i = 0; i < v.size(); i++) {

        h -= ceil((double)v[i]/(double)n);

        if (h < 0) {
            return false;
        }
    }

    return true;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1;
    // Here we don't need to take the range till the sum of all elements
    // Koko can only eat upto the maximum number in the pile at once. If it tries to eat any number of bananas
    // more than the maximum, then the amount of time taken will be the constant
    // Here we are trying to find the mininum number of bananas it can eat in an hour, and so we take the maximum of
    // array as the highest value
    int high = *max_element(v.begin(), v.end());

    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (isPossible(v, h, mid)) {
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
    vector<int> v = {7, 15, 6, 3};

    cout << minimumRateToEatBananas(v, 8) << endl;

    v.clear();
    v = {4, 9, 4, 3, 1, 3};

    cout << minimumRateToEatBananas(v, 66) << endl;

    return 0;
}
