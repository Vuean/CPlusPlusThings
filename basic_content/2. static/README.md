# static那些事

## 0. 项目来源

原项目网址：<https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/static>  
原作者个人微信公众号：guangcity

## 1. static含义

当与不同类型一起使用时，`static`关键字具有不同含义：  
__静态变量：__ 函数中的变量，类中的变量；
__静态类的成员：__ 类对象和类中的函数；

## 2. 静态变量

- 函数中的静态变量
  
当变量声明为`static`时，空间**将在程序的声明周期内分配**。即使多次调用该函数，静态变量的空间也**只分配一次**，前一次调用中的变量值通过下一次函数调用传递。这对于在C/C++或需要存储先前函数状态的任何其他应用程序非常有用。

```C++
    #include <iostream>
    #include <string>
    using namespace std;

    void demo()
    {
        // static variable
        static int count = 0;
        cout << count << " ";

        // value is update and will be carried to next function

        count ++;
    }

    int main()
    {
        for(int i = 0; i < 5; i++)
            demo();
        return 0;
    }
```

输出：

```C++
    0 1 2 3 4
```

在上述程序中，变量count被声明为`static`，它的值通过函数调用来传递，每次调用函数时，不会对变量count进行初始化。

- 类中的静态变量

由于声明为`static`的变量只被初始化一次，因为它们在单独的静态存储中分配了空间，因此，类中的静态变量**由对象共享**。对于不同的对象，不能有相同静态变量的多个副本。也是因为这个原因，静态变量不能使用构造函数初始化。

```C++
    #include <iostream>
    using namespace std;

    class Apple
    {
    public:
        static int i;

        Apple() { }
    };

    int main()
    {
        Apple obj1;
        Apple obj2;
        obj1.i = 2020;
        obj2.i = 3030;

        cout << obj1.i << " " << obj2.i << endl;
        return 0;
    }
```

可以发现在上面的程序中，我们已经尝试为多个对象创建静态变量i的多个副本，但这并没有发生。因此，**类中的静态变量应由用户使用类外的类名和范围解析运算符显式初始化**，如下所示：

```C++
    #include <iostream>
    using namespace std;

    class Apple
    {
    public:
        static int i;
        Apple () { }
    };

    int Apple::i = 2020;

    int main()
    {
        Apple obj1;
        cout << obj1.i << " ";
        Apple obj2;
        cout << obj2.i << " ";
        return 0;
    }
```

输出：

```C++
    2020 2020
```

# 3. 静态成员

- 类对象为静态

就像变量一样，对象也在声明为`static`时具有范围，直到程序的生命周期。  

考虑以下程序，其中对象是**非静态**的。  

```C++
    #include <iostream>
    using namespace std;

    class Apple
    {
        int i;
    public:
        Apple()
        {
            i = 0;
            cout << "Inside Constructor\n";
        }
        ~Apple()
        {
            cout << "Inside Destructor\n";
        }
    };

    int main()
    {
        int x = 0;
        if(x == 0)
        {
            Apple obj;
        }
        cout << "End of main\n";
        return 0;
    }
```

输出：

```C++
    Inside Constructor
    Inside Destructor
    End of main
```

上述程序中，对象在if语句块内声明为非静态的。因此，**变量的范围仅在if语句块内**。因此，当创建对象时，将调用构造函数，并且在if语句块的控制权越过时，析构函数同时被调用。

再考虑将对象声明为**静态**的：

```C++
    #include <iostream>
    using namespace std;

    class Apple
    {
        int i;
    public:
        Apple()
        {
            i = 0;
            cout << "Inside Constructor\n";
        }
        ~Apple()
        {
            cout << "Inside Destructor\n";
        }
    };

    int main()
    {
        int x = 0;
        if(x == 0)
        {
            static Apple obj;
        }
        cout << "End of main\n";
        return 0;
    }
```

输出：

```C++
    Inside Constructor
    End of main
    Inside Destructor
```

从输出可以清晰地看出，析构函数在main函数才被调用。这是因为**静态对象的范围是贯穿程序的生命周期**。

- 类中的静态函数

就像类中的静态数据成员或静态变量一样，**静态成员函数也不依赖于类的对象**。我们被允许使用对象和`.`来调用静态成员函数。但建议使用类名和范围解析运算符调用静态成员。

**允许静态成员函数仅访问静态数据成员或其他静态成员函数，它们无法访问类的非静态数据成员或成员函数。**

```C++
    #include <iostream>
    using namespace std;

    class Apple
    {
    public:
        // static member function 
        static void printMsg()
        {
            cout << "Welcome to Apple!";
        }
    };

    int main()
    {
        // invoking a static member function 
        Apple::printMsg();
    }
```

输出：

```C++
    Welcome to Apple!
```