# this指针那些事

## 0. 项目来源

    作者信息：
    原项目网址：https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/static
    原作者个人微信公众号：guangcity
    ![Alt text](/this/img/作者微信公众号.jpg "guangcity")

## 1. this指针

`this`指针的用处:

- (1) 一个对象的`this`指针并不是对象本身的一部分，不会影响sizeof(对象)的结果；
- (2) `this`作用域是在类内部，当在类的非静态成员函数中访问类的非静态成员的时候，编译器会自动将对象本身的地址作为一个隐含参数，传递给函数。也就是说，即使你没有写上`this`指针，编译器在编译的时候也是加上`this`的，它作为非静态成员函数的隐含形参。对各成员的访问均通过`this`进行。

`this`指针的使用：

- (1) 在类的非静态成员函数中，返回类对象本身时，可直接使用`return *this`；
- (2) 当参数与成员变量名相同时，如`this->n = n`（不能写成n = n）。

另外，在网上大家会看到`this`会被编译器解析成`A *const` ，`A const *` ，究竟是哪一个呢？下面通过断点调试分析：

```C++
    #include <iostream>
    #include <cstring>
    using namespace std;

    class Person {
    public:
        typedef enum{
            BOT = 0,
            GITL
        }SexType;
        Person(char *n, int a, SexType s)
        {
            name = new char[strlen(n)+1];
            strcpy(name, n);
            age = a;
            sex = s;
        }
        int get_age() const{
            return this->age;
        }
        Person& add_age(int a){
            age += a;
            return *this;
        }
        ~Person(){
            delete [] name;
        }
    private:
        char *name;
        int age;
        SexType sex;
    };

    int main()
    {
        Person p("ZhangSan", 20, Person::BOY);
        cout << p.get_age() << endl;
        cout << p.add_age(10).get_age() << endl;
        return 0;
    }
```
为了验证`this`指针是哪一个，现在在`add_age`处添加断点，运行后如下：

会发现编译器自动为我们加上`A* const this`，而不是`A const *this`!

紧接着，上述还有个常函数，那么我们在对`get_age`添加断点，如下：

会发现编译器把上述的`this`，变为`const A* const`，因为该函数是`const`函数，那么针对`const`函数，它只能访问`const`变量与`const`函数，不能修改其他变量的值，所以需要一个`this`指向不能修改的变量，那就是`const A*`,又由于本身`this`是`const`指针，所以就为`const A* const`!

总结：`this`在成员函数的开始执行前构造，在成员的执行结束后清除。上述的`get_age`函数会被解析成`get_age(const A * const this)`,`add_age`函数会被解析成`add_age(A* const this,int a)`。在C++中类和结构是只有一个区别的：**类的成员默认是private，而结构是public**。`this`是类的指针，如果换成结构，那`this`就是结构的指针了。
