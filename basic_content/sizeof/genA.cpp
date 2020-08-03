// genA.cpp
// 普通成员函数，大小为1,一个类中，虚函数本身、成员函数（包括静态与非静态）和
// 静态数据成员都是不占用类对象的存储空间。

#include <iostream>
using namespace std;

class A
{
public:
    A();
    ~A();
    static int a;
    static void func();
    void fun();
    void fun1();
};

int main()
{
    cout << sizeof(A) << endl;  //1
    return 0;
}