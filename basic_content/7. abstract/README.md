# 纯虚函数和抽象类

## 0. 项目来源

原项目网址：<https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/abstract>  
原作者个人微信公众号：guangcity

## 1. 纯虚函数与抽象类

C++中的纯虚函数(或抽象函数)是我们没有实现的虚函数！我们只需声明它! 通过声明中赋值0来声明纯虚函数！

```C++
    // 抽象类
    class A{
    public:
        virtual void show() = 0;    // 纯虚函数
    };
```

- 纯虚函数：没有函数体的虚函数
- 抽象类：包含纯虚函数的类

抽象类只能作为基类来派生新类使用，不能创建抽象类的对象，抽象类的指针和引用指向由抽象类派生出来的类的对象！
> 代码样例：
[pure_virtual.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/7.%20abstract/pure_virtual.cpp)

## 2. 实现抽象类

抽象类中：**在成员函数内可以调用纯虚函数，在构造函数/析构函数内部不能使用纯虚函数**。

如果一个类从抽象类派生而来，它必须实现了基类中的所有纯虚函数，才能成为非抽象类。

```C++
    // A为抽象类
    class A {
    public:
        virtual void f() = 0;
        void g() { this->f(); }
        A() { } // 构造函数
    };

    class B : public A{
    public:
        void f() { cout << "B::f()" << endl; } // 实现了抽象类的纯虚函数
    };
```

> 代码样例：
[abstract.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/7.%20abstract/abstract.cpp)

## 3. 重要点

- 纯虚函数使一个类变成抽象类

> 代码样例：
[interesting_facts1.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/7.%20abstract/interesting_facts1.cpp)

```C++
    // 抽象类至少包含一个纯虚函数
    class Base {
    public:
        virtual void show() = 0;
        int getX() { return x; }
    private:
        int x;
    };
```

- 抽象类类型的指针和引用

> 代码样例：
[interesting_facts2.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/7.%20abstract/interesting_facts2.cpp)

```C++
    class Derived : public Base
    {
    public:
        void show() { cout << "In Derived \n";} // 实现抽象类的纯虚函数
        Derived() {}
    };

    int main()
    {
        //Base b;  // error!不能创建抽象类的对象
        //Base *b = new Base(); error!

        Base *bp = new Derived(); // 抽象类的指针和引用 -> 由抽象类派生出来的类的对象
        bp->show();
        return 0;
    }
```

- 如果我们不在派生类中覆盖纯虚函数，那么派生类也会变成抽象类

> 代码样例：
[interesting_facts3.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/7.%20abstract/interesting_facts3.cpp)

```C++
    class Derived : public Base
    {
    public:
        // void show() { cout << " In Derived/n"; }
    };
```

- 抽象类可以有构造函数

> 代码样例：
[interesting_facts4.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/7.%20abstract/interesting_facts4.cpp)

```C++
    // 抽象类
    class Base {
    public:
        virtual void show() = 0;
        Base(int i) { x = i; } // 构造函数
    private:
        int x;
    };

    // 派生类
    class Derived : public Base
    {
    public:
        void show() { cout << "x = " << x << ", y = " << y;} // 实现抽象类的纯虚函数
        Derived(int i, int j) : Base(i) { y = j; }  // 构造函数
    private:
        int y;
    };
```

- 构造函数不能是虚函数，而析构函数可以是虚析构函数

> 代码样例：
[interesting_facts5.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/7.%20abstract/interesting_facts5.cpp)

```C++
    class Base {
    public:
        Base() { cout << "Constructor: Base" << endl; }
        virtual ~Base() { cout << "Destructor: Base" << endl; }

        virtual void func() = 0;
    };

    class Derived : public Base
    {
    public:
        Derived() { cout << "Constructor: Derived" << endl; }
        ~Derived() { cout << "Destructor: Derived" << endl; }

        void func() { cout << "In Derived.func()" << endl; }
    };

    int main()
    {
        Base *Var = new Derived();
        delete Var;
        return 0;
    }

    /*
        输出：
        Constructor: Base
        Constructor: Derived
        Destructor : Derived
        Destructor : Base
    */
```

> - 当基类指针指向派生类对象并删除对象时，我们可能希望调用适当的析构函数。
> - 如果析构函数不是虚拟的，则**只能调用基类析构函数**。

## 4. 完整示例

抽象类由派生类继承实现！

> 代码样例：
[derived_full.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/7.%20abstract/derived_full.cpp)