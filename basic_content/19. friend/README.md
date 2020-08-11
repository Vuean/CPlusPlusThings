# 友元函数与友元类

## 0. 项目来源

原项目网址：<https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/friend>  
原作者个人微信公众号：guangcity  
![guangcity](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/8.%20vptr_vtable/img/wechat.jpg)

## 1. 概述

友元提供了一种**普通函数或者类成员函数**访问**另一个类中的私有或保护成员**的机制。也就是说有两种形式的友元：

- (1) 友元函数：普通函数访问某个类中的私有或保护成员；
- (2) 友元类：类A中的成员函数访问类B中的私有或保护成员；

优点：提高了程序的运行效率；

缺点：破坏了类的封装性和数据的透明性；

总结：

- 能访问私有成员；
- 破坏封装性；
- 友元关系不可传递；
- 友元关系的单向性；
- 友元声明的形式及数量不受限制。

## 2. 友元函数

在类声明的任何区域中声明，而定义则在类的外部。

```C++
    friend<类型><友元函数名>(<参数列表>);
```

注意，**友元函数只是一个普通函数，并不是该类的类成员函数**，它可以在任何地方调用，友元函数中通过对象名来访问该类的私有或保护成员。

> 代码样例：
[friend_func.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/19.%20friend/friend_func.cpp)

```C++
    #include <iostream>
    using namespace std;

    class A
    {
    public:
        A(int _a) : a(_a) { }
        friend int geta(A &ca); // 友元函数
    private:
        int a;
    };

    int geta(A &ca)
    {
        return ca.a;
    }

    int main()
    {
        A a(3);
        cout << geta(a) << endl;

        return 0;
    }
```

## 3. 友元类

友元类的声明在该类的声明中，而实现在该类外。

```C++
    friend class <友元类名>;
```

类B是类A的友元，那么类B可以直接访问A的私有成员。

> 代码样例：
[friend_class.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/19.%20friend/friend_class.cpp)

```C++
    #include <iostream>
    using namespace std;

    class A
    {
    public:
        A(int _a) : a(_a) { }
        friend class B;
    private:
        int a;
    };

    class B
    {
    public:
        int getA(A ca)
        {
            return ca.a;
        }
    };

    int main()
    {
        A a(3);
        B b;

        cout << b.getA(a) << endl;
        return 0;
    }
```

## 4. 注意

- **友元关系没有继承性**。假如类B是类A的友元，类C继承于类A，那么友元类B是没办法直接访问类C的私有或保护成员；同时假如类D继承自类B，类D也无法访问类A的私有或保护成员；
- **友元关系没有传递性**。假如类B是类A的友元，类C是类B的友元，那么友元类C是没办法直接访问类A的私有或保护成员，也就是不存在“友元的友元”这种关系。
