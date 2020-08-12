# decltype那些事

## 0. 项目来源

原项目网址：<https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/decltype>  
原作者个人微信公众号：guangcity  
![guangcity](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/8.%20vptr_vtable/img/wechat.jpg)

## 1. decltype简介

`typeid` 运算符可用来查询一个变量的类型，这种类型查询在运行时进行。RTTI 机制为每一个类型产生一个 type_info 类型的数据，而 `typeid` 查询返回的变量相应 type_info 数据，通过 `name` 成员函数返回类型的名称。同时在C++11中 `typeid` 还提供了 `hash_code` 这个成员函数，用于返回类型的唯一哈希值。RTTI会导致运行时效率降低，且在泛型编程中，我们更需要的是编译时就要确定类型，RTTI并无法满足这样的要求。编译时类型推导的出现正是为了泛型编程，在非泛型编程中，我们的类型都是确定的，根本不需要再进行推导。

`decltype` 与 `auto` 关键字一样，用于进行编译时类型推导，不过它与 `auto` 还是有一些区别的。`decltype` 的类型推导并不是像 `auto` 一样是从变量声明的初始化表达式获得变量的类型，而是总是**以一个普通表达式作为参数**，返回该表达式的类型,而且 `decltype` 并不会对表达式进行求值。

## 2. 基本使用

`decltype`的语法是：

```C++
    decltype(expression)
```

这里括号是必不可少的，`decltype`的作用是**查询表达式的类型**。因此，上面语句的效果是，返回 expression 表达式的类型。注意，`decltype` 仅仅“查询”表达式的类型，并不会对表达式进行“求值”。

### 2.1 推导出表达式类型

```C++
    int i = 4;
    decltype(i) a;  // 推导结果为int。a的类型为int。
```

### 2.2 与using/typedef合用，用于定义类型

```C++
    using size_t = decltype(sizeof(0));     // sizeof(a)的返回值为size_t类型
    using ptrdiff_t = decltype((int*)0 - (int*)0);
    using nullptr_t = decltype(nullptr);

    vector<int> vec;
    typedef decltype(vec.begin()) vectype;
    for(vectype i = vec.begin(); i != vec.end(); ++i)
    {
        // ...
    }
```

这样和`auto`一样，也提高了代码的可读性。

### 2.3 重用匿名类型

在C++中，我们有时候会遇上一些匿名函数，如：

```C++
    struct
    {
        int d;
        double b;
    } anon_s;
```

而借助 `decltype`，我们可以重新使用这个匿名的结构体：

```C++
    decltype(anon_s) as;    //定义了一个上面匿名的结构体
```

### 2.4 泛型编程中结合auto，用于追踪函数的返回值类型

这也是decltype最大的用途了。

> 代码样例：
[decltype.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/23.%20decltype/decltype.cpp)

```C++
    template <typename T>
    auto multiply(T x, T y)->decltype(x*y)
    {
        return x*y;
    }
```

## 3. 判别规则

对于 `decltype(e)` 而言，其判别结果受以下条件的影响：

- 1. 如果 e 是一个没有带括号的标记符表达式或者类成员访问表达式，那么 `decltype(e)` 就是 e 所命名的实体的类型。此外，如果 e 是一个被重载的函数，则会导致编译错误;
- 2. 否则，假设 e 的类型是T，如果 e 是一个将亡值，那么 `decltype(e)` 为 `T&&`;
- 3. 否则，假设 e 的类型是T，如果 e 是一个左值，那么 `decltype(e)` 为 `T&`;
- 4. 否则，假设 e 的类型是T，则`decltype(e)`为 `T`。

标记符指的是除去关键字、字面量等编译器需要使用的标记之外的程序员自己定义的标记，而单个标记符对应的表达式即为标记符表达式。例如：

```C++
    int arr[4];
```

则arr为一个标记符表达式，而 `arr[3]+0` 不是。举例如下：

```C++
    int i = 10;
    decltype(i) a;  // a推导为in
    decltype((i)) b = i;    // b推导为int&，必须为其初始化，否则编译错误
```

仅仅为i加上了()，就导致类型推导结果的差异。这是因为，i是一个标记符表达式，根据推导规则1，类型被推导为int。而(i)为一个左值表达式，所以类型被推导为int&。同时，**推导出为引用类型，必须为其初始化**。

```C++
    int i = 4;
    int arr[5] = { 0 };
    int *ptr = arr;
    struct S
    {
        double d;
    }s;
    void Overloaded(int);
    void Overloaded(char);  // 重载的函数
    int && RvalRef();
    const bool Func(int);

    // 规则一：推导其为类型
    decltype (arr) var1;    // int 标记符表达式
    decltype (ptr) var2;    // int* 标记符表达式
    decltype (s.d) var3;    // double 成员访问表达式
    // decltype(Overloaded) var4;//重载函数。编译错误。

    // 规则二：将亡值。推导为类型的右值引用。
    decltype (RvalRef()) var5 = 1;

    //规则三：左值，推导为类型的引用。
    decltype ((i)) var6 = i;    // int&，左值引用必须给其赋值
    decltype (true ? i : i) var7 = i；  // int&  条件表达式返回左值。
    decltype (++i) var8 = i;            // int&  ++i返回i的左值
    decltype(arr[5]) var9 = i;          // int&  []操作返回左值
    decltype(*ptr) var10 = i;           // int&  *操作返回左值
    decltype("hello") var11 = "hello"   // const char(&)[9] 字符串字面常量为左值，且为const左值

    //规则四：以上都不是，则推导为本类型
    decltype(1) var12;  // const int
    decltype(Func(1)) var13 = true; // const bool
    decltype(i++) var14 = i;        // int i++返回右值
```

> 学习参考：
<hhttps://www.cnblogs.com/QG-whz/p/4952980.html>
