// 在使用时需要注意：被转换对象obj的类型T1必须是多态类型，
// 即T1必须公有继承自其它类，或者T1拥有虚函数（继承或自定义）。
// 若T1为非多态类型，使用dynamic_cast会报编译错误。

#include <iostream>
#include <typeinfo>
using namespace std;

// A为非多态类型 
class A{ };

//B为多态类型
class B
{ 
    public: virtual ~B(){}
};

//D为多态类型
class D: public A{ };

//E为非多态类型
class E : private A{ };

//F为多态类型
class F : private B{ };

int main()
{
    A *a1 = new D();
    
    A *a2 = new E();    // error：不允许对不可访问的基类“A”进行转换
   
    B *b1 = new F();    // error：不允许对不可访问的基类“B”进行转换
    
    A *objA1 = new A();
    D *d = dynamic_cast<D*>(objA1); // error 运行时dynamic_Cast 的操作数必须包含多态类型

    return 0;
}
