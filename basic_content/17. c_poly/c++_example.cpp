/*
c++_example.cpp
c++中的多态
*/

#include <iostream>
using namespace std;

class A
{
public:
    virtual void f()
    {
        cout << "Base A::f()" << endl;
    }
};

// 必须为共有继承，否则后面调用不到，class默认为私有继承！
class B : public A
{
public:
    //虚函数实现,子类中virtual关键字可以没有
    virtual void f()
    {
        cout << "Derived B::f()" << endl;
    }
};

int main()
{
    A a;    // 基类对象
    B b;    // 派生类对象

    A *pa = &a;  // 父类指针指向父类对象
    pa->f();     // 调用父类的函数

    pa = &b;     // 父类指针指向子类对象，多态实现
    pa->f(); //调用派生类同名函数

    return 0;
}