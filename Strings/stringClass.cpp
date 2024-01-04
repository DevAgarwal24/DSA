// Implement te C++ string class

#include <iostream>
#include <cstring>

using namespace std;

class String {
public:
    // Default constructor
    String() : str{nullptr}, length{0} { cout << "Calling Default Constructor\n"; }

    ~String() {
        if (str) delete[] str;
        str = nullptr;
        length = 0;
    }

    // Parameterized Constructor
    String(const char *s) {
        cout << "Calling Parameterized Constructor\n";
        length = strlen(s);
        str = new char[length+1];
        strcpy(str, s);
    }

    // Copy Constructor
    String(const String& s) {
        cout << "Calling Copy Constructor\n";
        length = s.length;
        str = new char[length+1];
        strcpy(str, s.str);
    }

    // Move Constructor
    String(String &&s) {
        cout << "Calling Move Constructor\n";
        length = s.length;
        str = s.str;

        s.str = nullptr;
        s.length = 0;
    }

    // Copy assignment operator
    // String& operator= (const String& s) {
    //     if (this == &s) return *this;

    //     cout << "Calling Copy Assignment Operator\n";

    //     // Free the already allocated resource
    //     delete[] str;

    //     length = s.length;
    //     str = new char[length+1];
    //     strcpy(str, s.str);

    //     return *this;
    // }

    // This uses Copy and Swap
    // We can't have both this one and copy assignment together
    // This is another way of writing copy assignment
    // As we're not taking a const reference, a copy of the string will be
    // created, which will call the copy constructor
    String& operator= (String s) {
        cout << "Calling the Copy and Swap one\n";
        Swap(*this, s);
        return *this;
    }

    void Swap(String &s1, String &s2) {
        std::swap(s1.str, s2.str);
        std::swap(s1.length, s2.length);
    }

    friend ostream& operator<<(ostream &os, const String &s);
    friend istream& operator>>(istream &is, const String &s);

    unsigned int len() { return length; }

private:
    char *str = nullptr;
    unsigned int length = 0;
};

ostream& operator<<(ostream &os, const String &s) {
    os << s.str;
    return os;
}

istream& operator>>(istream &is, String &s) {
    char *buffer = new char[1000];
    memset(&buffer[0], 0, 1000);
    is >> buffer;
    s = String(buffer);
    delete[] buffer;
    return is;
}

int main()
{
    String s1;              // Default Ctor
    String s2 = "Hello";    // Parameterzied Ctor
    String s3 = s2;         // Copy Ctor
    String s4(s3);          // Copy Ctor
    s1 = s2;                // Copy assignment operator

    int length = s3.len();

    String s5;
    cin >> s5;
    cout << s5 << endl;

    String s6(std::move(s5));

    return 0;
}
