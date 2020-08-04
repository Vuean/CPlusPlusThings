// moreinhe.cpp - virmoreinhe.cpp
// 普通函数多继承

#include <iostream>
using namespace std;

class A
{
    virtual void func() {}
};

class B
{
    virtual void func1() {}
};

class C : public A, public B
{
public:
    virtual void func2() {}
};

int main()
{
    //  派生类继承多个虚函数，会继承所有虚函数的vptr
    // 结果：8 8 16
    cout << sizeof(A) << " " << sizeof(B) << " " << sizeof(C) << endl;
    return 0;
}