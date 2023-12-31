// Things not implemented here
// 1. Making pointers thread safe
// 2. Custom Allocator and De-allocators
// 3. Lots of other functionality

#include <iostream>
using namespace std;

template <typename T>
class UniquePtr {
private:
    T* res_;
public:
    UniquePtr(T* res=nullptr) : res_(res) { cout << "Ctor\n"; }

    UniquePtr(const UniquePtr<T>& ptr) = delete;
    UniquePtr& operator=(const UniquePtr<T>& ptr) = delete;

    UniquePtr(UniquePtr<T>&& ptr) {
        res_ = ptr.res_;
        ptr.res_ = nullptr;
    }

    UniquePtr& operator=(const UniquePtr<T>&& ptr) {
        if (this != &ptr) {
            if (res_) delete res_;
            res_ = ptr.res_;
            ptr.res_ = nullptr;
        }

        return *this;
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

    void reset(T* ptr=nullptr) {
        if (res_) delete res_;
        res_ = ptr;
    }

    ~UniquePtr() {
        if (res_) delete res_;
        res_ = nullptr;
    }
};

int main()
{
    UniquePtr<int> ptr1(new int(2));
    // UniquePtr<int> ptr2(ptr1);  // Compilation Error for copy constructor
    // UniquePtr<int> ptr3 = ptr1; // Compilation Error for copy constructor
    UniquePtr<int> ptr4(new int(50));
    // ptr4 = ptr1;                // Compilation Error for copy assignment operator

    UniquePtr<int> ptr5(std::move(ptr1));   // Move constructor
    UniquePtr<int> ptr6 = std::move(ptr4);  // Move assignment operator

    cout << *ptr5 << endl;
    cout << *ptr6 << endl;

    cout << ptr5.get() << endl;
    ptr5.reset(new int(500));
    cout << ptr5.get() << endl;

    // cout << ptr6->func() << endl;
}