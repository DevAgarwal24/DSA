// https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679

#include <iostream>
#include <cmath>

using namespace std;

// This is when we don't want to use the pow() to find the power
// ***Here the overflow cases needs to be handled ourselves***
// Takes the number for which we need to find the nth power and the number which with we are comparing the nth root
// These approach is generally used to handle edge cases only. Otherwise we're good with the normal ones also.
int func(int num, int n, int m) {
    long long int exp = 1;

    for (int i = 1; i <= n; i++) {
        exp = exp * num;

        if (exp > m) {
            return -1;
        }
    }

    if (exp == m) {
        return 1;
    }

    return 0;
}

int nthRoot (int n, int m) {
    int low = 1;
    int high = m;

    while (low <= high) {
        int mid = low + (high - low)/2;

#if 0
        if (pow(mid, n) == m) {
            return mid;
        }

        if (pow(mid, n) > m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
#endif
        int x = func(mid, n, m);

        if (x == 1) {
            return mid;
        } else if (x == -1) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }

    }

    return -1;
}

int main()
{
    cout << nthRoot(3, 27) << endl;
    cout << nthRoot(4, 69) << endl;

    return 0;
}
