/*
pure_virtual.cpp
纯虚函数：没有函数体的虚函数
我们只需声明它!通过声明中赋值0来声明纯虚函数！
抽象类：包含虚函数的类
*/

#include <iostream>
using namespace std;

class A
{
public:
    virtual void show() = 0;
private:
    int a;
};

int main()
{
    /*
    1. 抽象类只能作为基类来派生新类使用
    2. 抽象类的指针和引用->由抽象类派生出来的类的对象！
    */
   A a; // error: 不允许使用抽象类类型“A”的对象：--函数A::show是纯虚拟函数

   A *a1;   // ok，可以定义抽象内的指针

   A *a2 = new A(); // error: 不允许使用抽象类类型“A”的对象：--函数A::show是纯虚拟函数
}