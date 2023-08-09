#include <iostream>
#include <cstdint>

using namespace std;

class Set {
public:
    void add(int num) {
        if (num > 60) return;
        bitSet = bitSet | (1UL << num);     // bitSet ^ (1UL << num) -> Confirm this
    }

    void del(int num) {
        if (num > 60) return;
        bitSet = bitSet & ~(1UL << num);    // bitSet ^ ~(1UL << num)
    }

    void print() {
        uint64_t tmp = bitSet;
        
        int count = 0;
        while (tmp) {
            if (tmp & 1UL) {
                cout << count << " ";
            }
            count++;

            tmp >>= 1;
        }

        cout << endl;
    }
private:
    uint64_t bitSet{0};
};

int main()
{
    Set s;
    s.add(65);
    s.add(3);
    s.add(23);
    s.add(54);
    s.add(0);
    s.add(9);

    s.print();

    s.del(3);
    s.del(0);
    s.del(24);

    s.print();
}