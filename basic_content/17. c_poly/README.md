# C实现C++的面向对象特性

## 0. 项目来源

原项目网址：<https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/c_poly>  
原作者个人微信公众号：guangcity  
![guangcity](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/8.%20vptr_vtable/img/wechat.jpg)

## 1. C++实现案例

C++中的多态：在C++中会维护一张虚函数表，根据赋值兼容规则，我们知道父类的指针或者引用是可以指向子类对象的。

如果一个父类的指针或者引用调用父类的虚函数则该父类的指针会在自己的虚函数表中查找自己的函数地址，如果该父类对象的指针或者引用指向的是子类的对象，而且该子类已经重写了父类的虚函数，则该指针会调用子类的已经重写的虚函数。

> 代码样例：
[c++_example.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/17.%20c_poly/c%2B%2B_example.cpp)

## 2. C实现

- 封装

C语言中是没有`class`类这个概念的，但是有`struct`结构体，我们可以考虑使用`struct`来模拟；

使用函数指针把属性与方法封装到结构体中。

- 继承
  
结构体嵌套

- 多态
  
类与子类方法的函数指针不同

在C语言的结构体内部是没有成员函数的，如果实现这个父结构体和子结构体共有的函数呢？我们可以考虑使用函数指针来模拟。但是这样处理存在一个缺陷就是：父子各自的函数指针之间指向的不是类似C++中维护的虚函数表而是一块物理内存，如果模拟的函数过多的话就会不容易维护了。

模拟多态，**必须保持函数指针变量对齐(在内容上完全一致，而且变量对齐上也完全一致)**。否则父类指针指向子类对象，运行崩溃！

> 代码样例：
[c_example.c](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/17.%20c_poly/c_example.c)
