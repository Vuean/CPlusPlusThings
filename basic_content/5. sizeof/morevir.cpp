#include<iostream>
using namespace std;
// 对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针,vptr的大小。
class A{
    virtual void fun();
    virtual void fun1();
    virtual void fun2();
    virtual void fun3();
};

int main()
{
    cout<<sizeof(A)<<endl; // 结果：8
    return 0;
}