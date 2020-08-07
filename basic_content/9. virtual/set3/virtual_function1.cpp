#include <iostream>
using namespace std;

class Dereived;

class Base
{
private:
    virtual void func() { cout << "Base Func"; }
    // friend int main();
};

class Derived : public Base
{
public:
    void func() { cout << "Derived Func"; }
};

int main()
{
    Base *ptr = new Derived;
    ptr->func();    // error 函数“Base::func”(已声明所在行数：9)不可访问
    return 0;
}