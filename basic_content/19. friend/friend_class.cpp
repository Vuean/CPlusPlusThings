#include <iostream>
using namespace std;

class A
{
public:
    A(int _a) : a(_a) { }
    friend class B;
private:
    int a;
};

class B
{
public:
    int getA(A ca)
    {
        return ca.a;
    }
};

// class C : public B
// {
// public:
//     int getA(A ca)
//     {
//         return ca.a;    // error: “A::a”不可访问
//     }
// };

int main()
{
    A a(3);
    B b;

    cout << b.getA(a) << endl;
    return 0;
}