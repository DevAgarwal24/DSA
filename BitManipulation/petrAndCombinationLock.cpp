// https://codeforces.com/problemset/problem/1097/B

#include <iostream>
#include <vector>

using namespace std;

// We use bit manipulation in this problem to find all the subsets
// This is the power set method and can only be used from smaller values of n (<20)

// In this problem, instead of creating sets based on 1s and 0s, we add the value if we get 1 and subtract
// the value if the get 0 for that particular index.
bool petrAndCombinationLock(vector<int>& v) {
    if (v.size() == 1) {
        return false;
    }

    for (int i = 0; i < (1 << v.size()); i++) {

        int sum = 0;

        for (int j = 0; j < v.size(); j++) {
            if (i & (1 << j)) {
                sum += v[j];
            } else {
                sum -= v[j];
            }
        }

        if (sum % 360 == 0) {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> v = {10, 20, 30};
    cout << petrAndCombinationLock(v) << endl;      // 1

    v.clear();
    v = {10, 10, 10};
    cout << petrAndCombinationLock(v) << endl;      // 0

    v.clear();
    v = {120, 120, 120};
    cout << petrAndCombinationLock(v) << endl;      // 1

    v.clear();
    v = {50};
    cout << petrAndCombinationLock(v) << endl;      // 0

    return 0;
}