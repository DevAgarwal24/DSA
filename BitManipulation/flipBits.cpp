// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
// https://www.codingninjas.com/studio/problems/flip-bits_8160405?leftPanelTab=1

#include <iostream>
using namespace std;

// When we do XOR on two numbers, we get a number where the position of 1s mean that the two numbers differ
// at that indexes

int flipBits(int A, int B){
    if (A == B) return 0;

    int tmp = A ^ B;

    int count = 0;
    
    while (tmp) {
        if (tmp & 1) {
            count++;
        }

        tmp >>= 1;
    }

    return count;
}

int main()
{
    cout << flipBits(10, 100) << endl;
    cout << flipBits(80, 80) << endl;
    cout << flipBits(8818, 37) << endl;
    cout << flipBits(0xffff, 0x1) << endl;

    return 0;
}
