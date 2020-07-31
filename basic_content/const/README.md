
# const那些事

## 0. 项目来源及原作者

    https://github.com/Light-City/CPlusPlusThings
    原作者个人公众号：guangcity

## 1. const含义

常类型是指使用类型修饰符const说明的类型，常类型的变量或对象的值是不能被更新的。

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
        int * const prt = &num; // const指针必须初始化！且const指针的值不能修改
        int * t = &num;
        *t = 1;
        cout << *prt << endl;
    }
```

