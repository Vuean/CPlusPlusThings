
# const那些事

## 0. 项目来源及原作者

    https://github.com/Light-City/CPlusPlusThings
    原作者个人公众号：guangcity

## 1. const含义

常类型是指使用类型修饰符`const`说明的类型，常类型的变量或对象的值是不能被更新的。

## 2. const作用

- 可以定义常量

```C++
    const int a = 100;
```

- 类型检查
  - `const`常量与`#define`宏定义常量的区别:  
      ->`const`常量具有类型，编译器可以进行安全检查；  
      ->`#define`宏定义没有数据类型，知识简单的字符串替换，不能进行安全检查；
  - `const`定义的变量只有类型为整数或者枚举，且以常量表达式初始化时才能作为常量表达式；
  - 其他情况下它只是一个`const`限定的变量，不能与常量混淆；
- 防止修改，起保护作用；

```C++
    void f(const int i)
    {
        i++;  // error
    }
```

- 可以节省空间，避免不必要的内存分配；
  - `const`定义常量从汇编的角度来看，只是给出了对应的内存地址，而不是像`#define`一样给出的是立即数；
  - `const`定义的常量在程序运行过程中只有一份拷贝，而`#define`定义的常量在内存中有若干个拷贝；

## 3. const对象默认为文件的局部变量

*注意*：非`const`变量默认为`extern`。要使`const`变量能够在其他文件中访问，必须在文件中显式地指定它为`extern`.  

未被`const`修饰的变量在不同文件的访问: 

```C++
    // file1.cpp  
    int ext;

    // file2.cpp
    #include <iostream>
    extern int ext;  
    int main() {
        std::cout << (ext+10) << std::endl;
    }
```

`const`常量在不同文件的访问：

```C++
    // extern_file1.cpp
    exter const int ext = 12;  

    // extern_file2.cpp
    #include <iostream>
    extern const int ext;
    int main() {
        std::cout << ext << std::endl;
    }
```

**小结：**  
可以发现未被`const`修饰的变量不需要`extern`显示声明，而`const`常量需要显示声明`extern`，并且需要做初始化（常量在定义时必须初始化）。

## 4. 定义常量

```C++
    const int b = 10;
    b = 0;    // error: assignment of read-only variable 'b'
    const string s = "helloworld";
    const int i, j = 0;    // error: uninitialized const 'i'
```

上述存在两处错误：

- b为常量，不可更改！
- i为常量，必须在定义时进行初始化！
  
## 5. const指针

使用带有指针的`const`时，有两种选择`const`修饰指针所指的对象，或者`const`修饰在指针里存储的地址。与指针相关的const有四种：

```C++
    const char *a;    // 指向const对象的指针或者说是指向常量的指针
    char const *a;    // 同上
    char * const a;     // 指向类型对象的const指针（常指针、const指针）
    const char * const a;    // 指向const对象的const指针
```

**小结：**
如果`const`位于`*`的左侧，则`const`修饰指针所指向的变量，即指针指向为常量；
如果`const`位于`*`的右侧，则`const`修饰指针本身，即指针本身为常量；

具体使用如下：

### (5.1) 指向常量的指针

```C++
    const int *ptr; // ptr是一个指针，指向一个const int
    *ptr = 10;  // error
```

ptr是一个指向`int`类型的`const`对象的指针，`const`定义的是`int`类型，即ptr指向的对象类型，而不是ptr本身，所以ptr可以不用赋值，但ptr所指的值不能被改变，即不能通过ptr去修改所指对象的值；

同时，也不能使用`void *`指针保存`const`对象的地址，**必须使用`const void *`类型的指针保存`const`对象的地址**

```C++
    const int p = 10;
    const void *vp = &p;
    void *vp = &p;  // error
```

另外，**允许把非`const`对象的地址赋值给指向`const`对象的指针**。

```C++
    const int *ptr;
    int val = 3;
    ptr = &val; // ok
```

但不能通过ptr指针来修改val的值，即使它指向的是非`const`对象!

我们不能使用指向`const`对象的指针修改基础对象，然而如果该指针指向了非`const`对象，可用其他方式修改其所指的对象。可以修改`const`指针所指向的值，但是不能通过`const`对象指针来进行而已！如下修改：

```C++
    int *ptr1 = &val;
    *ptr1 = 4;
    cout << *ptr << endl;
```

**小结：**  
**1.对于指向常量的指针，不能通过指针来修改对象的值。**  
**2.不能使用`void*`指针保存`const`对象的地址，必须使用`const void*`类型的指针保存`const`对象的地址。**  
**3.允许把非`const`对象的地址赋值给`const`对象的指针，如果要修改指针所指向的对象值，必须通过其他方式修改，不能直接通过当前指针直接修改。**

### (5.2) 常指针

`const`指针必须进行初始化，且`const`指针的值不能修改。

```C++
    #include <iostream>
    using namespace std;
    int main(){
        int num = 0;
        int * const ptr = &num; // const指针必须初始化！且const指针的值不能修改
        int * t = &num;
        *t = 1;
        cout << *ptr << endl;
    }
```

上述指针ptr做指向的值，可以通过非`const`指针来修改。

最后，当把一个`const`常量的地址赋值给ptr时，由于ptr指向的是一个常量，而不是`const`常量，所以会报错：`const int* -> int*`错误！

```C++
    #include <iostream>
    using namespace std;
    int main() {
        const int num = 0;
        int * const ptr = &num; // error！ const int* -> int*
        cout << *ptr << endl;
    }
```

上述可改为`const int *ptr`或改为`const int * const ptr`。

## (5.3) 指向常量的常指针

```C++
    const int p = 3;
    const int * const ptr = &p;
```

ptr是一个`const`指针，指向了一个`int`类型的`const`对象。

# 6. 函数中使用const

## (6.1) const修饰函数返回值

__(1) const int__  
这个本身无意义，因为参数返回本身就是赋值给其他变量！

```C++
    const int func1();
```

__(2) const int*__  
指针指向的类容不变。

```C++
    const int* func2();
```

__(3) int *const__  
指针本身不可变。

```C++
    int *const func3();
```

## (6.2) const修饰函数参数

__(1) 传递过来的参数及指针本身在函数内不可变__

```C++
    void func(const int var);   // 传递过来的参数不可变
    void func(int *const ptr);  // 指针本身不可变
```

上述两种`const`修饰的函数参数，表明参数在函数体内不能被修改，但此处没有任何意义，var/ptr本身就是形参，在函数内不会改变。

输入参数采用“值传递”，由于函数将自动产生临时变量用于复制该参数，因此该参数本来就无需保护，所以不需要加`const`修饰。

__(2) 参数指针所指内容为常量不可变__

```C++
    void stringCopy(char *dst, const char *src);
```

其中，src为输入参数，dst为输出参数。给src加上`const`修饰后，如果函数体内的语句试图改动src的内容，编译器将指出错误。

__(3) 参数为引用，为了增加效率同时防止修改__

```C++
    void func(const A &a);
```

对于非内部数据类型的参数而言，如`void func(A a)`这样声明的函数效率较低，因为函数体内将产生A类型的临时对象用于复制a，而临时对象的构造、复制、析构过程将消耗时间。

为了提高效率，可将函数声明为`void func(A &a)`，因为“引用传递”进借用参数的别名，不需要产生临时对象。

> 但是`void func(A &a)`存在一个缺点：  
> “引用传递”有可能改变参数a，这不是我们所期望的。因此，可将参数加const修饰：`void func(const A &a)`。

那是否将`void func(int x) `改写为`void func(const int &x)`，以提高效率呢？完全没有必要，因为内部数据类型的参数不存在构造、析构过程，而且复制过程也非常快，“值传递”和“引用传递”的效率相当。

## (6.3) 小结：

- 1. 对于非内部数据类型的输入参数，应该将“值传递”的方式改为“const 引用传递”，目的是提高效率。
- 2. 对于内部数据类型的输入参数，不要将“值传递”的方式改为“const 引用传递”。否则既达不到提高效率的目的，又降低了函数的可理解性。

以上解决了两个面试问题：

- 如果函数需要传入一个指针，是否需要为该指针加上const，把const加在指针不同的位置有什么区别；
- 如果写的函数需要传入的参数是一个复杂类型的实例，传入值参数或者引用参数有什么区别，什么时候需要为传入的引用参数加上const。
  
# 7. 类中使用const

