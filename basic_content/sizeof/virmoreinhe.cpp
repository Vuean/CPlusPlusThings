// virmoreinhe.cpp - moreinhe.cpp
// 虚函数多继承

#include <iostream>
using namespace std;

class A
{
    virtual void func() {}
};

class B
{
    virtual void func2() {}
};

class C : virtual public A, virtual public B
{
public:
    virtual void func3() {}
};

int main()
{
    // 派生类虚继承多个虚函数，会继承所有虚函数的vptr
    // 输出：8 8 16
   cout << sizeof(A) << " " << sizeof(B) << " " << sizeof(C) << endl;
   return 0;
}