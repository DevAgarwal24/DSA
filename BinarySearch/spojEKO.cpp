// https://www.spoj.com/problems/EKO/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& v, int m, int h) {
    int l = 0;

    for (int i = 0; i < v.size(); i++) {
        if ((v[i]-h) > m) {
            return true;
        } else {
            if ((v[i]-h) < 0) {
                continue;
            }

            l += v[i] - h;
            if (l >= m) {
                return true;
            }
        }
    }

    return false;
}

int EKO(vector<int>& v, int m) {
    int low = 0;
    int high = *(max_element(v.begin(), v.end()));

    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (isPossible(v, m, mid)) {
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
    vector<int> v = {20, 15, 10, 17};

    cout << EKO(v, 7) << std::endl;     // 15
    cout << EKO(v, 15) << std::endl;    // 12

    v.clear();
    v = {4, 42, 40, 26, 46};
    cout << EKO(v, 20) << std::endl;    // 20

    return 0;
}