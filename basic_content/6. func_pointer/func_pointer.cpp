// 函数指针的使用

#include <iostream>
using namespace std;

// 定义了一个变量pFun，这个变量是个指针，
// 指向返回值为空，参数为int类型的函数的指针！
void (*pFun)(int);

// 代表一种新类型，不是变量！所以与上述的pFun不一样！
typedef void (*func)(void);

void myfunc(void)
{
    cout << "asda" << endl;
}

void glFun(int a)
{
    cout << a << endl;
}

int main()
{
    func pfun = myfunc; // 赋值
    pfun(); // 调用

    pFun = glFun;
    (*pFun)(2);
    return 0;
}