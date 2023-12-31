// sharedptr implementation

#include <iostream>
using namespace std;

template <typename T>
class SharedPtr {
private:
    T *res_;
    int *counter;

    void increment_counter() {
        if (counter) {
            (*counter)++;
        }
    }

    void decrement_counter() {
        if (counter) {
            (*counter)--;
            if ((*counter) == 0) {
                if (res_) {
                    delete res_;
                    delete counter;
                    res_ = nullptr;
                    counter = nullptr;
                }
            }
        }
    }

public:
    // Default Parameterized Ctor
    SharedPtr<T>(T *res=nullptr) : res_{res}, counter{nullptr} {
        // cout << "Default Parameterized Ctor\n";
        if (res_ != NULL) {
            counter = new int(1);
        }
    }

    // Copy Constructor
    SharedPtr<T>(const SharedPtr<T>& ptr) {
        // cout << "Copy Ctor\n";
        res_ = ptr.res_;
        counter = ptr.counter;
        increment_counter();
    }

    // Copy assignment operator
    SharedPtr<T>& operator=(SharedPtr<T>& ptr) {
        // cout << "Copy assignment operator\n";
        if (this != &ptr) {
            decrement_counter();

            res_ = ptr.res_;
            counter = ptr.counter;
            increment_counter();
        }

        return *this;
    }

    // Move constructor
    SharedPtr<T>(SharedPtr<T>&& ptr) {
        // cout << "Move Ctor\n";
        res_ = ptr.res_;
        counter = ptr.counter;

        ptr.res_ = nullptr;
        ptr.counter = nullptr;
    }

    // Move assignment operator
    SharedPtr<T>& operator=(SharedPtr<T>&& ptr) {
        // cout << "Move assignment operator\n";
        if (this != &ptr) {
            decrement_counter();

            res_ = ptr.res_;
            counter = ptr.counter;
            // No increment here

            ptr.res_ = nullptr;
            ptr.counter = nullptr;
        }

        return *this;
    }

    void reset(T* res=nullptr) {
        decrement_counter();
        res_ = res;
        if (res_) {
            counter = new int(1);
        }
    }

    int getCount() {
        if (counter) return *counter;
        return 0;
    }

    T* operator->() {
        return res_;
    }

    T& operator*() {
        return *res_;
    }

    T* get() {
        return res_;
    }

    ~SharedPtr<T>() {
        decrement_counter();
    }
};

int main()
{
    SharedPtr<int> ptr1;                    // Using default constructor
    SharedPtr<int> ptr2(new int(10));       // Using parameterized ctor
    SharedPtr<int> ptr3(ptr2);              // Using Copy ctor
    cout << ptr3.getCount() << endl;        // 2

    SharedPtr<int> ptr4;                    // Default parameterized ctor
    ptr4 = ptr3;                            // Using Copy assignment operator
    cout << ptr4.getCount() << endl;        // 3

    SharedPtr<int> ptr5(std::move(ptr1));   // Using move ctor
    ptr4 = std::move(ptr5);                 // Using move assignment operator
    cout << ptr4.getCount() << endl;        // 0

    ptr1.reset();
    ptr2.reset(new int(5));

    cout << *ptr2 << endl;                  // Implementing * operator
    //ptr2->func();                         // Implementing -> operator

    cout << ptr2.get() << endl;             // Raw Pointer
    cout << ptr3.get() << endl;

    cout << ptr3.getCount() << endl;        // number of objects pointing to the same resource

    SharedPtr<int> ptr6;
    SharedPtr<int> ptr7(ptr6);
    cout << ptr7.getCount() << endl;        // Should return 0

    SharedPtr<int> ptr8(new int(100));
    ptr6 = ptr8;
    cout << ptr7.getCount() << endl;        // Should return 0
    cout << ptr8.getCount() << endl;        // Should return 2

    // Destructor
    return 0;
}