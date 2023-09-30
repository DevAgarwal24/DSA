//
// https://www.codingninjas.com/studio/problems/count-total-set-bits_784

#include <iostream>

using namespace std;

// Brute Force
// Iterate over all the numbers from 1 to N and for each number, find the number
// of set bits.
// T.C = O(NlogN)
// S.C = O(1)
// This solution though, doesn't work for large numbers
#if 0
int countSetBits(int N)
{
    int count = 0;

    for (int i = 1; i <= N; i++) {
        int num = i;
        while (num) {
            if (num & 1) {
                count++;
            }

            num >>= 1;
        }
    }

    return count;
}
#endif

// Optimal Solution
// Finding the pattern in the number of 1s from 1 to N
// Take the example for 6
// 0 0 0
// 0 0 1
// 0 1 0
// 0 1 1
// 1 0 0
// 1 0 1
// 1 1 0
// Find the power of 2 which is less than equal to N
// The number of 1s till 2^b - 1 = b * 2^(b-1)
// The number of 1s till 3 = 2 * 2^(2-1) = 4
// The reset of the numbers will follow the same pattern after we subtract
// 2^b from it and recursively call the function again.
// To take care of the 1s in the beginning after subtraction, we add it directly
// (b * 2^(b-1)) + (N - 2^b + 1) + func(N-2^b)

// Solving using recursion
// T.C = O()
// S.C = O(1)
int countSetBits(int N)
{
    if (N <= 0) return 0;
    if (N == 1) return 1;

    int count = 0;
    int start = 1;
    int bits = 0;

    while ((start<<1) <= N) {
        start <<= 1;
        bits++;
    }

    count = (start/2) * bits;

    return count + (N - start + 1) + countSetBits(N-start);
}

int main()
{
    cout << countSetBits(7) << endl;
    cout << countSetBits(11) << endl;
    cout << countSetBits(24) << endl;
    cout << countSetBits(16) << endl;
    
    return 0;
}