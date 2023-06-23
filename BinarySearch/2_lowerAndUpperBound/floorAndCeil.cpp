// https://practice.geeksforgeeks.org/problems/ceil-the-floor2802/1

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int>
floorAndCeil (vector<int>& v, int number)
{
    int floor = 0;
    int ceil = v.size();

    int low = 0;
    int high = v.size() - 1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (v[mid] == number) {
            floor = mid;
            ceil = mid;
            break;
        } else if (v[mid] > number) {
            ceil = mid;
            high = mid - 1;
        } else {
            floor = mid;
            low = mid + 1;
        }
    }

    if (floor == 0 && ceil == v.size()) {
        return make_pair(-1, -1);
    } else if (floor == 0) {
        return make_pair(-1, v[ceil]);
    } else if (ceil == v.size()) {
        return make_pair(v[floor], -1);
    }

    return make_pair(v[floor], v[ceil]);

}

int main()
{
    vector<int> v = {10, 20, 25, 30, 40, 50};

    pair<int, int> p = floorAndCeil(v, 25);
    cout << p.first << " " << p.second << std::endl;

    p = floorAndCeil(v, 22);
    cout << p.first << " " << p.second << std::endl;

    p = floorAndCeil(v, 5);
    cout << p.first << " " << p.second << std::endl;

    p = floorAndCeil(v, 55);
    cout << p.first << " " << p.second << std::endl;

    v.clear();
    
    p = floorAndCeil(v, 10);
    cout << p.first << " " << p.second << std::endl;

    return 0;
}
