# extern "C"

## 0. 项目来源

原项目网址：<https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/extern>  
原作者个人微信公众号：guangcity  
![guangcity](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/8.%20vptr_vtable/img/wechat.jpg)

## 1. C++与C编译区别

在C++中常在头文件见到`extern "C"`修饰函数，那有什么作用呢？ 是用于C++链接在C语言模块中定义的函数。

C++虽然兼容C，但C++文件中函数编译后生成的符号与C语言生成的不同。因为C++支持函数重载，C++函数编译后生成的符号带有函数参数类型的信息，而C则没有。

例如`int add(int a, int b)`函数经过C++编译器生成.o文件后，`add`会变成形如`add_int_int`之类的, 而C的话则会是形如`_add`, 就是说：相同的函数，在C和C++中，编译后生成的符号不同。

这就导致一个问题：如果C++中使用C语言实现的函数，在编译链接的时候，会出错，提示找不到对应的符号。此时`extern "C"`就起作用了：告诉链接器去寻找`_add`这类的C语言符号，而不是经过C++修饰的符号。

## 2. C++调用C函数

C++调用C函数的例子: 引用C的头文件时，需要加`extern "C"`

```C++
    // add.h
    #ifndef ADD_H
    #define ADD_H

    int add(int x, int y);

    #endif

    // add.c
    #include "add.h"

    int add(int x, int y)
    {
        return x + y;
    }

    // add.cpp
    #include "add.h"
    #include <iostream>
    using namespace std;

    int main()
    {
        add(2, 3);
        return 0;
    }
```