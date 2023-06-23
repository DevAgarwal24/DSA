// https://www.codingninjas.com/codestudio/problems/cooking-ninjas_1164174

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& v, int m, long long time) {

    int total = 0;
    int count = 1;

    for (int i = 0; i < v.size(); i++) {
        while(v[i]*count*(count+1)/2 <= time) {
            count++;
        }

        total += count - 1;
        count = 1;

        if (total >= m) {
            return true;
        }
    }

    return false;
}

int cookingNinjas(vector<int>& v, int m) {
    
    int max = *(max_element(v.begin(), v.end()));

    long long low = 0;
    long long high = max*(m*(m+1))/2;

    long long ans = -1;

    while (low <= high) {
        long long mid = low + (high - low)/2;

        if (isPossible(v, m, mid)) {
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
    vector<int> v = {1, 2, 3, 4};

    cout << cookingNinjas(v, 11) << std::endl;  // 12

    cout << cookingNinjas(v, 10) << std::endl;  // 12

    v.clear();
    v = {10};
    cout << cookingNinjas(v, 1) << std::endl;   // 10

    v.clear();
    v = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << cookingNinjas(v, 8) << std::endl;   // 1

    return 0;
}