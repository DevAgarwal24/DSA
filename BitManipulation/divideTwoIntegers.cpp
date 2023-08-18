// https://leetcode.com/problems/divide-two-integers/
// https://www.codingninjas.com/studio/problems/-divide-two-integers_111261

#include <iostream>
#include <climits>

using namespace std;

int divide(int dividend, int divisor) {
	if (dividend == divisor) return 1;
				
	bool isPositive = ((dividend < 0) ^ (divisor < 0)) ? false : true;

	uint32_t quotient = 0, tmp = 0;
	uint32_t q = 0;

	uint32_t a = abs(dividend);
	uint32_t b = abs(divisor);

	while (a >= b) {
		uint32_t count = 0;
		while (a > (b<<(count+1))) {
			count++;
		}
			
		quotient += (1<<count);		// Here I cannot do "quotient != (1<<count)"
		a = a - (b << count);

	}

	if (quotient == (1<<31) && isPositive) return INT_MAX;

	return isPositive ? quotient : -quotient;
}

int main()
{
    cout << divide(-2147483648, 1) << endl;
    cout << divide(-2147483648, -1) << endl;
    cout << divide(2147483647, 1) << endl;
    cout << divide(2147483647, -1) << endl;

    return 0;
}
