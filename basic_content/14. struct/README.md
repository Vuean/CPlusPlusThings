# 一文搞懂C和C++中struct

## 0. 项目来源

原项目网址：<https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/struct>  
原作者个人微信公众号：guangcity  
![guangcity](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/8.%20vptr_vtable/img/wechat.jpg)

## 1. C中struct

- 在C中struct只单纯的用作数据的复合类型，也就是说，在结构体声明中只能将数据成员放在里面，而不能将函数放在里面;
- 在C结构体生命中不能使用C++访问修饰符，如：`public`、`protected`、`private`而在C++中可以使用;
- 在C中定义结构体变量，如果使用了下面定义必须加struct;
- C的结构体不能继承（没有这一概念）;
- 若结构体的名字与函数名相同，可以正常运行且正常的调用！例如：可以定义与 struct Base 不冲突的 void Base() {}。

完整案例：

```C++
    #include <stdlio.h>

    struct Base
    {
    // public: // error
        int v1;
        int v2;
        int v3;

        // error
        // void print()
        // {
        //    printf("%s\n", "hello world");
        // }
    };

    // 可以定义一个与结构体同名的函数
    void Base(){
        printf("%s\n", "hello world");
    }

    // struct Base base1;  // ok
    // Base base2; // error

    int main()
    {
        struct Base base1;
        base1.v1 = 1;
        printf("%d\n", base1.v1);
        Base();
        return 0;
    }
```

> 代码样例：
[struct_func.c](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/14.%20struct/struct_func.c)

## 2. C++中struct

与C对比如下：

- C++结构体中不仅可以定义数据，还可以定义函数；
- C++结构体中可以使用访问修饰符，如：`public`,`private`和`protected`；
- C++结构体使用可以直接使用，不带struct；
- C++结构体可以继承
- 若结构体的名字和函数同名，可以正常运行且正常调用，但是定义结构体变量时候只用带struct的。

例如：
> 情形1： 不适用typedef定义结构体别名

 未添加同名函数前：

 ```C++
    struct Student{

    };
    struct Student s1;   // ok
    Student s2;          // ok
 ```

 添加同名函数后：

 ```C++
    struct Student{

    };
    Student() {}
    struct Student s1;   // ok
    Student s2;          // error
 ```

 > 情形二：使用typedef定义结构体别名

 ```C++
    typedef struct Base1
    {
        int v1;
    private:    //error!
        int v3;
    public:
        int v2;
        void print()
        {
            printf("%s\n", "hello world");
        }
    } B;

    //void B() {}  //error! 符号 "B" 已经被定义为一个 "struct Base1" 的别名
 ```

 > 前三种案例代码示例：
  [struct_func.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/14.%20struct/struct_func.cpp)

 ```C++
    #include <iostream>
    #include <stdio.h>

    struct Base
    {
        int v1;
    // private: //会使得后续v3不可访问
        int v3;
    public:
        int v2;
        void print()
        {
            printf("%s\n", "hello world");
        }
    };

    int main()
    {
        struct Base base1;
        Base base2; // ok
        Base base;

        base.v1 = 1;
        base.v3 = 2;
        base.print();
        printf("%d\n",base.v1);
        printf("%d\n",base.v3);
        return 0;
    }
 ```

> 继承案例代码示例：
 [ext_struct_func.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/14.%20struct/ext_struct_func.cpp)

```C++
    #include <iostream>
    #include <stdio.h>

    struct Base {
        int v1;
        int v3;
    public:     // 显示声明public
        int v2;
        virtual void print()
        {
            printf("%s\n", "Base");
        }
    };

    struct Derived: Base {
    public:
        int v2;
        void print()
        {
            printf("%s\n", "Derived");
        }
    };

    int main()
    {
        Base *b = new Derived();
        b->print();
        return 0;
    }
```

 > 同名函数代码示例：
 [struct_func_func.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/14.%20struct/struct_func_func.cpp)

 ```C++
    #include <iostream>
    #include <stdio.h>

    struct Base {
        int v1;
        int v3;
    public:     // 显示声明public
        int v2;
        void print()
        {
            printf("%s\n", "hello world");
        }
    };

    typedef struct Base1
    {

        int v1;
        int v3;
    public:
        int v2;
        void print()
        {
            printf("%s\n", "hello world");
        }
    }B;

    void Base()
    {
        printf("%s\n","I am Base func");
    }

    // void B() {}  // error! 符号 "B" 已经被定义为一个 "struct Base1" 的别名

    int main()
    {
        struct Base base;   // ok
        struct Base base;  //ok
        // Base base1;  // error!
        base.v1=1;
        base.v3=2;
        base.print();
        printf("%d\n",base.v1);
        printf("%d\n",base.v3);
        Base();
        return 0;
    }
 ```

## 3. 总结

C和C++中struct的区别：

|C|C++|
|:--------:|:-------:|
|不能将函数放在结构体声明|能将函数放在结构体声明|
|在C结构体声明中不能使用C++访问修饰符|public、protected、private 在C++中可以使用|
|在C中定义结构体变量，如果使用了下面定义必须加struct。|可以不加struct|
|结构体不能继承（没有这一概念）。|可以继承|
|若结构体的名字与函数名相同，可以正常运行且正常的调用！|若结构体的名字与函数名相同，使用结构体，只能使用带struct定义！|