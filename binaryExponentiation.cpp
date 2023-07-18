// https://cp-algorithms.com/algebra/binary-exp.html

#include <iostream>

using namespace std;

// Calculate a ^ b
long long binPow(long long a, long long b) {
	if (b == 0) return 1;

	long long res = 1;

	while (b > 0) {
		if (b & 1) res *= a;

		a *= a;
		b >>= 1;
	}

	return res;
}

long long binPowRec(long long a, long long b) {
	if (b == 0) return 1;

	long long res = binPowRec(a, b/2);

	if (b % 2) return res * res * a;

	return res * res;
}

int main()
{
	cout << "3^13 = " << binPow(3, 13) << " " << binPowRec(3, 13) << endl;
	cout << "2^17 = " << binPow(2, 17) << " " << binPowRec(2, 17) << endl;

	return 0;
}
