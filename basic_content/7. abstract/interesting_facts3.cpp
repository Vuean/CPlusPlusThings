/*
interesting_facts3.cpp
如果我们不在派生类中覆盖纯虚函数，那么派生类也会变成抽象类
*/

#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show() = 0; 
    int getX() { return x; }
private:
    int x;
};

class Derived : public Base
{
public:
    // void show() { cout << "In Derived \n"; } 
    Derived(){}
};

int main()
{
    Derived d;  // error
    // Base *bp = new Derived(); // error
    return 0;
}