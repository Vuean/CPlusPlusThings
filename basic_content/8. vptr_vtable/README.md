# 深入浅出C++虚函数的vptr与vtable

## 0. 项目来源

原项目网址：<https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/vptr_vtable>  
原作者个人微信公众号：guangcity  
![guangcity](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/8.%20vptr_vtable/img/wechat.jpg)

## 1. 基础理论

为了实现虚函数，C ++使用一种称为虚拟表的特殊形式的后期绑定。该虚拟表是用于解决在动态/后期绑定方式的函数调用函数的查找表。虚拟表有时会使用其他名称，例如“vtable”，“虚函数表”，“虚方法表”或“调度表”。

虚拟表实际上非常简单，虽然用文字描述有点复杂。首先，**每个使用虚函数的类（或者从使用虚函数的类派生）都有自己的虚拟表**。该表只是编译器在编译时设置的静态数组。虚拟表包含可由类的对象调用的每个虚函数的一个条目。此表中的每个条目只是一个函数指针，指向该类可访问的派生函数。

其次，编译器还会添加一个隐藏指向基类的指针，称之为vptr。vptr在创建类实例时自动设置，以便指向该类的虚拟表。与this指针不同，this指针实际上是编译器用来解析自引用的函数参数，vptr是一个真正的指针。

因此，它使每个类对象的分配打一个指针的大小，这也意味着**vptr由派生类继承**。

## 2. 实现与内部结构

下面我们来看自动与手动操纵vptr来获取地址与调用虚函数！

开始看代码之前，为了方便大家理解，这里给出调用图：

![base](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/8.%20vptr_vtable/img/base.jpg)

> 代码样例：vptr1.cpp

```C++
    // vptr1.cpp
    // C++虚函数vptr和vtable

    #include <iostream>
    #include <stdio.h>
    using namespace std;

    // 函数指针
    typedef void (*Fun)();

    class Base
    {
    public:
        Base() {}
        virtual void fun1()
        {
            cout << "Base::fun1" << endl;
        }
        virtual void fun2()
        {
            cout << "Base::fun2" << endl;
        }
        virtual void fun3() {}
        ~Base() {}
    };

    // 派生类
    class Derived : public Base
    {
    public:
        Derived() {}
        void fun1()
        {
            cout << "Derived::fun1" << endl;
        }

        void fun2()
        {
            cout << "Derived::fun2" << endl;
        }
        ~Derived(){}
    };

    // 获取vptr地址与func地址,vptr指向的是一块内存，
    // 这块内存存放的是虚函数地址，这块内存就是我们所说的虚表

    Fun getAddr(void *obj, unsigned int offset)
    {
        cout << "=======================" << endl;
        // 64位操作系统，占8字节，通过*(unsigned long *)obj取出前8字节，即vptr指针
        void *vptr_addr = (void *)*(unsigned long *)obj;
        printf("vptr_addr: %p\n", vptr_addr);

        // 通过vptr指针访问virtual table，因为虚表中每个元素(虚函数指针)
        // 在64位编译器下是8个字节，因此通过*(unsigned long *)vptr_addr取出
        // 前8字节，后面加上偏移量就是每个函数的地址

        void *func_addr = (void *)*((unsigned long *)vptr_addr + offset);
        printf("func_addr: %p\n",func_addr);
        return (Fun)func_addr;
    }

    int main()
    {
        Base ptr;
        Derived d;
        Base *pt = new Derived();   // 基类指针指向派生类实例
        
        Base &pp = ptr; // 基类引用指向基类实例
        Base &p = d;    // 基类引用指向派生类实例

        cout << "基类对象直接调用：" << endl;
        ptr.fun1();

        cout << "基类对象调用基类实例：" << endl;
        pp.fun1();
    
        cout << "基类指针指向基类实例并调用虚函数" << endl;
        pt->fun1();

        cout << "基类引用指向基类实例并调用虚函数" << endl;
        p.fun1();
    
        // 手动查找vptr 和 vtable
        Fun f1 = getAddr(pt, 0);
        (*f1)();
        
        Fun f2 = getAddr(pt, 1);
        (*f2)();
        delete pt;
        return 0;
    }
```

运行结果：

```C++
基类对象直接调用：
Base::fun1
基类对象调用基类实例：
Base::fun1
基类指针指向基类实例并调用虚函数
Derived::fun1
基类引用指向基类实例并调用虚函数
Derived::fun1
=======================
vptr_addr: 0000000000409a20
func_addr: 0000000000407cd0
Derived::fun1
=======================
vptr_addr: 0000000000409a20
func_addr: 0000000000000000
```

我们发现C++的动态多态性是通过虚函数来实现的。简单的说，通过virtual函数，**指向子类的基类指针可以调用子类的函数**。例如，上述通过基类指针指向派生类实例，并调用虚函数，将上述代码简化为：

```C++
    Base *pt = new Derived();   // 基类指针指向派生类实例
    cout << "基类指针指向派生类实例并调用虚函数" << endl;
    pt->fun1();
```

其过程为：

- 1. 首先，程序识别出`fun1()`是个虚函数;
- 2. 其次，程序使用`pt->vptr`来获取Derived的虚拟表；
- 3. 第三，它查找Derived虚拟表中调用哪个版本的fun1()

这里就可以发现调用的是`Derived::fun1()`。因此`pt->fun1()`被解析为`Derived::fun1()`!
