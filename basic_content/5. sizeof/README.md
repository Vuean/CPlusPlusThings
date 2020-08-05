# 类大小计算

## 0. 项目来源

原项目网址：<https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/sizeof>
原作者个人微信公众号：guangcity
![Alt text](/basic_content/this/img/作者微信公众号.jpg "guangcity")

总结：

- 空类的大小为1字节；
- 一个类中，虚函数本身、成员函数（包括静态与非静态）和静态数据成员都不占用类对象的存储空间；
- 对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针vptr的大小；
- 普通继承，派生类继承了所有基类的函数和成员，需要按照字节对齐来计算大小；
- 虚函数继承，不管是单继承还是多继承，都是继承了基类的vptr；(32位操作系统4字节，64位操作系统 8字节)！
- 虚继承，继承基类的vptr；

## 1. 原则1

```C++
    // blackclass.cpp
    // 空类的大小为1字节
    #include <iostream>
    using namespace std;
    class A{};

    int main() {
        cout << sizeof(A) << endl;
        return 0;
    }
```

## 2. 原则2

```C++
    // static.cpp
    // 静态数据成员
    // 静态数据成员被编译器放在程序的一个global data members中，它是类的一个数据成员，但不影响类的大小。
    // 不管这个类产生了多少个实例，还是派生了多少新的类，静态数据成员只有一个实例。静态数据成员，一旦被声明，就已经存在。

    #include <iostream>
    using namespace std;

    class A
    {
    public:
        char b;
        virtual void func() { };
        static int c;
        static int d;
        static int f;
    };

    int main()
    {
        // 字节对齐、静态变量不影响类的大小、vptr指针=8
        // 结果：16字节
        cout << sizeof(A) << endl;
        return 0;
    }
```

## 3. 原则3

```C++
    // morevir.cpp
    // 对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针,vptr的大小。
    #include <iostream>
    using namespace std;

    class A{
    virtual void func();
    virtual void func1();
    virtual void func2();
    virtual void func3();
    };

    int main()
    {
        cout << sizeof(A) << endl;  // 结果：8
        return 0;
    }
```

## 4. 原则4与5

关于字节对齐，可参考sweetfather的：
<https://blog.csdn.net/sweetfather/article/details/78487563>  

总的来说，对齐后：
- (1) 看变量所在偏移地址是否为变量大小的整数倍
- (2) 看对齐后的总大小是否为最长变量的整数倍

```C++
    // genilhe.cpp
    // 1. 普通单继承,继承就是基类+派生类自身的大小(注意字节对齐)
    // 注意：类的数据成员按其声明顺序加入内存，与访问权限无关，只看声明顺序。
    // 2.虚单继承，派生类继承基类vptr

    #include <iostream>
    using namespace std;

    class A
    {
    public:
        char a;
        int b;
    };

    /*此时B按照顺序：
    char a
    int b
    short a
    long b
    根据字节对齐：4+4 = 8； 8 + 4 + 4 = 16（32位）
    */

    class B : public A
    {
    public:
        short a;
        long b;
    };

    class C
    {
        A a;
        char c;
    };

    class A1
    {
        virtual void func(){}
    };

    class C1 : public A1
    {};

    int main()
    {
        cout << sizeof(A) << endl;  // 8
        cout << sizeof(B) << endl; // 16
        cout << sizeof(C) << endl; // 12

        // 对于虚单函数继承，派生类也继承了基类的vptr，所以是8字节
        cout << sizeof(A1) << endl; // 8
        cout << sizeof(C1) << endl; // 8
        return 0;
    }

```

## 5. 原则6

```C++
    // virnhe.cpp
    // 虚继承

    #include <iostream>
    using namespace std;

    class A
    {
        virtual void func() {}
    };

    class B
    {
        virtual void func2() {}
    };

    class C : virtual public A, virtual public B
    {
    public:
        virtual void func3() {}
    };

    int main()
    {
        // 派生类虚继承多个虚函数，会继承所有虚函数的vptr
        // 输出： 8 8 16
       cout << sizeof(A) << " " << sizeof(B) << " " << sizeof(C) << endl;
       return 0;
    }
```
