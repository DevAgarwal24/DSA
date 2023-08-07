#include <iostream>
#include <vector>

using namespace std;

void twoRepeatedNumbers(vector<int>& v) {
    int XOR = 0;
    for (int i = 0; i < v.size(); i++) {
        XOR ^= v[i];
    }

    int count = 0;
    while (XOR) {
        if (XOR & 1) break;
        count++;
        XOR >>= 1;
    }

    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] & (1 << count)) {
            num1 ^= v[i];
        } else {
            num2 ^= v[i];
        }
    }

    cout << num1 << " " << num2;
}

int main()
{
    vector<int> v = {1, 1, 3, 7, 6, 2, 3, 4, 6, 2};
    twoRepeatedNumbers(v);

    cout << endl;

    v.push_back(7);
    v.push_back(9);
    twoRepeatedNumbers(v);

    cout << endl;

    return 0;
}