/*
copy_construct.cpp
为什么构造函数不可以为虚函数？
*/

#include <iostream>
using namespace std;

class Base
{
public:

};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived created" << endl;
    }
    Derived(const Derived &rhs)
    {
        cout << "Derived created by deep copy" << endl;
    }
    ~Derived()
    {
        cout << "Derived destroyed" << endl;
    }
};

int main()
{
    Derived s1;

    Derived s2 = s1;

    // 如何从指向派生对象的基类的指针（引用）创建Derived1或Derived2对象？

    return 0;
}

/*
输出：
Derived created
Derived created by deep copy
Derived destroyed
Derived destroyed
*/