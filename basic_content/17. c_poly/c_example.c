/*
c_example.c
C实现多态
*/

#include <stdio.h>

// 重定义一个函数指针类型
typedef void (*pf) ();

// 父类
typedef struct _A
{
    pf _f;
} A;

// 子类
typedef struct _B
{
    A _b;   // 在子类中定义一个基类的对象即可实现对父类的继承。 
} B;

void FunA()
{
    printf("%s\n", "Base A::fun()");
}

void FunB()
{
    printf("%s\n", "Derived B::fun()");
}

int main()
{
    A a;
    B b;

    a._f = FunA;
    b._b._f = FunB;

    A *pa = &a;
    pa->_f();
    pa = (A*) &b;   // 让父类指针指向子类的对象,由于类型不匹配所以要进行强转 
    pa->_f();

    return 0;
}