// https://practice.geeksforgeeks.org/problems/square-root/0

#include <iostream>
#include <math.h>

using namespace std;

float squareRoot(int n, int precison) {
    int low = 0;
    int high = n;

    double squareRoot = -1;

    while(low <= high) {
        int mid = low + (high-low)/2;

        if (mid*mid <= n && (mid+1)*(mid+1) > n) {
            squareRoot = mid;
        }

        if (mid*mid > n) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    double factor = 1;

    for (int i = 0; i < precison; i++) {
        factor = factor / 10;

        while((squareRoot+factor)*(squareRoot+factor) < n) {
            squareRoot = squareRoot + factor;
        }
    }

    return squareRoot;
}

int main()
{
    cout << "Square root of 100: " << squareRoot(100, 3) << std::endl;
    cout << "Square root of 57: " << squareRoot(57, 4) << std::endl;
    cout << "Square root of 126: " << squareRoot(126, 3) << std::endl;
    cout << "Square root of 569: " << squareRoot(569, 3) << std::endl;
    cout << "Square root of 77: " << squareRoot(77, 3) << std::endl;
    cout << "Square root of 15: " << squareRoot(15, 3) << std::endl;

    return 0;
}
