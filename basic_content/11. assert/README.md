# assert那些事

## 0. 项目来源

原项目网址：<https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/assert>  
原作者个人微信公众号：guangcity  
![guangcity](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/8.%20vptr_vtable/img/wechat.jpg)

## 1. 第一个断言案例

assert 断言，**是宏，而非函数。**

`assert`宏的原型定义在<assert.h>(C\C++)中。其作用是如果它的条件返回错误，则终止程序执行。

可以通过定义`NDEBUG`来关闭`assert`，**但是需要在源代码的开头，`include<assert.h>`之前。**

```C++
    void assert(int expression);
```

> 代码示例：
[assert.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/11.%20assert/assert.cpp)

```C++
    #include <stdio.h>
    #include <assert.h>

    int main()
    {
        int x = 7;

        /*  Some big code in between and let's say x is accidentally changed to 9 */
        x = 9;

        // Programmer assumes x to be 7 in rest of the code
        assert(x==7);

        /* Rest of the code */

        return 0;
    }
```

```C++
    输出：
    File: assert.cpp, Line 12
    Expression: x==7
```

## 2. 断言与正常错误处理

- 断言主要用于逻辑上不可能的情况。

例如，它们可用于检查代码在开始运行之前所期望的状态，或者在运行完成后检查状态。与正常的错误处理不同，断言通常在运行时被禁用。

- 忽略断言，在代码开头加上：`#define NDEBUG`

加上`#define NDEBUG`，则`assert`不可用

> 代码示例：
[ignore_assert.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/11.%20assert/ignore_assert.cpp)
