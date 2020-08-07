/*
full_virde.cpp
将基类的析构函数声明为虚函数
*/

#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Constructing Base \n";
    }
    virtual ~Base()
    {
        cout << "Destroying Base \n";
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Constructing Derived \n";
    }
    ~Derived()
    {
        cout << "Destroying Derived \n";
    }
};

int main()
{
    Derived *d = new Derived();
    Base *bs = d;
    delete bs;
    return 0;
}

/*
输出：
Constructing Base 
Constructing Derived 
Destroying Derived 
Destroying Base 
*/