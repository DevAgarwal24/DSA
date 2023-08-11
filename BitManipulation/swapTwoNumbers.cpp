// https://www.codingninjas.com/studio/problems/swap-two-numbers_1380853?leftPanelTab=0

#include <iostream>

using namespace std;

// Here the swap needs to be done without taking a third variable.
// Both addition and subtraction, and division and multiplication methods can be used.
// There is problemes with both these methods. In case of division and multiplication, both the numbers should be non-zero.
// In case of addition and subtraction, the numbers can't be equal.
// We'll use XOR to swap, but this method also gets into trouble when the numbers are the same.
// We have a check when the numbers are same.

void swapNumber(int &a, int &b) {
	if (a == b) return;

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int main()
{
    int a = 10;
    int b = 100;

    swapNumber(a, b);
    cout << a << " " << b << endl;

    a = 73;
    b = 91;

    swapNumber(a, b);
    cout << a << " " << b << endl;

    return 0;
}