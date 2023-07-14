// Painters Partition Problem
// The solution is same for the Split Array Largest sum minimized
// Observer carefully and you'll find that the problem is also same as book allocation problem
// https://www.codingninjas.com/codestudio/problems/painter's-partition-problem_1089557
// https://www.codingninjas.com/studio/problems/largest-subarray-sum-minimized_7461751

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& v, int k, int n) {

    int painters = 1;
    int paintedArea = 0;

    for (int i = 0; i < v.size(); i++) {
        if (paintedArea + v[i] <= n) {
            paintedArea += v[i];
        } else {
            painters++;
            if (painters>k) {
                return false;
            }

            paintedArea = v[i];
        }
    }

    return true;
}

int paintersPartition(vector<int>& v, int k) {
    int low = *(max_element(v.begin(), v.end()));
    int high = accumulate(v.begin(), v.end(), 0);

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (isPossible(v, k, mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    vector<int> v = {5, 5, 5, 5};

    cout << paintersPartition(v, 2) << std::endl;   // 10

    cout << paintersPartition(v, 4) << std::endl;   // 5

    v.clear();
    v = {10, 20, 30, 40};
    cout << paintersPartition(v, 2) << std::endl;   // 60

    v.clear();
    v = {80, 90};
    cout << paintersPartition(v, 2) << std::endl;   // 90

    return 0;
}
