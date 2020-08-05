/*
interesting_facts2.cpp
抽象类类型的指针和引用
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
    void show() { cout << "In Derived \n"; } 
    Derived(){}
};

int main()
{
    //Base b;  //error! 不能创建抽象类的对象
    //Base *b = new Base(); error!
    Base *bp = new Derived(); // 抽象类的指针和引用 -> 由抽象类派生出来的类的对象
    bp->show(); // 输出：In Derived 
    return 0;
}