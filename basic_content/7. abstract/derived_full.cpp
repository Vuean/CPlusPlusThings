/*
derived_full.cpp
完整示例！抽象类由派生类继承实现！
*/

#include <iostream>
using namespace std;

class Base 
{
public:
    virtual void func() = 0;
    int getX() { return x; }
private:
    int x;
};

class Derived : public Base
{
public:
    void func() { cout << "func() called"; }
private:
    int y;
};

int main()
{
    Derived d;
    d.func();
    return 0;
}