#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int lowerBound(vector<int>& v, int number)
{
    int low = 0;
    int high = v.size() - 1;

    int lb = v.size();

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (v[mid] >= number) {
            lb = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return lb;
}

int upperBound(vector<int>& v, int number)
{
    int low = 0;
    int high = v.size() - 1;

    int ub = v.size();

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (v[mid] > number) {
            ub = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ub;
}

int firstOccurrence(vector<int>& v, int number)
{
    int first = -1;

    int low = 0;
    int high = v.size() - 1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (v[mid] == number) {
            first = mid;
            high = mid - 1;
        } else if (v[mid] > number) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return first;
}

int lastOccurrence(vector<int>& v, int number)
{
    int last = -1;

    int low = 0;
    int high = v.size() - 1;

    while (low <= high) {
        int mid = low + (high - low)/2;

        if (v[mid] == number) {
            last = mid;
            low = mid + 1;
        } else if (v[mid] > number) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return last;
}

pair<int, int>
firstAndLastPosition(vector<int>& v, int number)
{
    int lb = lowerBound(v, number);
    int ub = upperBound(v, number);

    if ((lb == v.size()) || (v[lb] != number)) {
        return make_pair(-1, -1);
    }

    return make_pair(lb, ub-1);
}

pair<int, int>
firstAndLastPositionWithoutLowerAndUpperBound(vector<int>& v, int number) {
    int first = firstOccurrence(v, number);
    if (first == -1) {
        return make_pair(-1, -1);
    }

    return make_pair(first, lastOccurrence(v, number));
}

int main()
{
    vector<int> v = {2, 4, 6, 8, 8, 8, 11, 13};

    pair<int, int> p;

    p = firstAndLastPosition(v, 1);
    cout << p.first << " " << p.second << std::endl;

    p = firstAndLastPosition(v, 8);
    cout << p.first << " " << p.second << std::endl;

    p = firstAndLastPosition(v, 10);
    cout << p.first << " " << p.second << std::endl;

    p = firstAndLastPosition(v, 11);
    cout << p.first << " " << p.second << std::endl;

    p = firstAndLastPosition(v, 14);
    cout << p.first << " " << p.second << std::endl;

    cout << std::endl;

    p = firstAndLastPositionWithoutLowerAndUpperBound(v, 1);
    cout << p.first << " " << p.second << std::endl;

    p = firstAndLastPositionWithoutLowerAndUpperBound(v, 8);
    cout << p.first << " " << p.second << std::endl;

    p = firstAndLastPositionWithoutLowerAndUpperBound(v, 10);
    cout << p.first << " " << p.second << std::endl;

    p = firstAndLastPositionWithoutLowerAndUpperBound(v, 11);
    cout << p.first << " " << p.second << std::endl;

    p = firstAndLastPositionWithoutLowerAndUpperBound(v, 14);
    cout << p.first << " " << p.second << std::endl;
}