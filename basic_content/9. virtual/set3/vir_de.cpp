/*
vir_de.cpp
派生类的析构函数没有被调用!
*/

// CPP program without virtual destructor causing undefined behavior 

#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Constructing Base \n";
    }
    ~Base()
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
    // 1.
    delete bs;
    // 2.
    delete d;
    
    return 0;
}

/*
1. 输出：
Constructing Base 
Constructing Derived 
Destroying Base 
*/

/*
2. 输出
Constructing Base
Constructing Derived
Destroying Derived
Destroying Base
*/