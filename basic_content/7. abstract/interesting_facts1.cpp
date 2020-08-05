/*
interesting_facts1.cpp
纯虚函数使一个类变成抽象类
*/

#include <iostream>
using namespace std;

// 抽象类至少包含一个纯虚函数
class Test
{
public:
    virtual void show() = 0;
    int getX() { return x; }
private:
    int x;
};

int main()
{
    Test t; // error
    // 不允许使用抽象类类型"Test"的对象：-- 函数"Test::show"是纯虚函数
    return 0;
}