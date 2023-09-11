// https://leetcode.com/problems/max-consecutive-ones/
// https://www.codingninjas.com/studio/problems/traffic_6682625

#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i]) {
            count++;
        } else {
            if (count > maxCount) maxCount = count;
            count = 0;
        }
    }

    if (count > maxCount) maxCount = count;

    return maxCount;
}

int main()
{
    vector<int> v = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(v) << endl;

    return 0;
}