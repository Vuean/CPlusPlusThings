# virtual那些事

## 0. 项目来源

原项目网址：<https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/vptr_vtable>  
原作者个人微信公众号：guangcity  
![guangcity](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/8.%20vptr_vtable/img/wechat.jpg)

## 1. 虚函数与运行多态

**虚函数的调用取决于指向或者引用的对象的类型，而不是指针或者引用自身的类型**。

> 代码样例：
[emp.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/9.%20virtual/set1/emp.cpp)

## 2. vptr与vtable

> 详见：
[vptr_vtable那些事](https://github.com/Vuean/CPlusPlusThings/tree/master/basic_content/8.%20vptr_vtable)

## 3. 虚函数中默认参数

**默认参数是静态绑定的，虚函数是动态绑定的。 默认参数的使用需要看指针或者引用本身的类型，而不是对象的类型。**

> 代码样例：
[default_arg.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/9.%20virtual/set2/default_arg.cpp)

具体可参见：《Effective C++ 改善程序与设计的55个具体做法》条款37写道：绝不重新定义继承而来的缺省参数值（Never redefine function’s inherited default parameters value.）

## 4. 可以不可以

（1） **静态函数可以生命为虚函数吗？**

**静态函数不可以声明为虚函数，同时也不能被`const`和`voliate`关键字修饰**

具体原因有两方面：

- `static`成员函数不属于任何类对象或类实例，所以即使给次函数加上`virtual`也没有任何意义；
- 虚函数依靠vptr和vtable来处理。vptr是一个指针，在类的构造函数中创建，并且只能用`this`指针来访问，静态成员函数没有`this`指针，所以无法访问vptr。

> 代码样例：
[static_error.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/9.%20virtual/set3/static_error.cpp)

（2） **构造函数可以为虚函数吗？**

**构造函数不可以声明为虚函数。同时除了`inline`
、`explicit`之外，构造函数不允许使用其它任何关键字。**

为什么构造函数不可以为虚函数？

尽管虚函数表vtable是在编译阶段就已经建立的，但指向虚函数表的指针vptr是在运行阶段实例化对象时才产生的。 如果类含有虚函数，编译器会在构造函数中添加代码来创建vptr。 问题来了，如果构造函数是虚的，那么它需要vptr来访问vtable，可这个时候vptr还没产生。 因此，构造函数不可以为虚函数。

我们之所以使用虚函数，是因为需要在信息不全的情况下进行多态运行。而构造函数是用来初始化实例的，实例的类型必须是明确的。 因此，构造函数没有必要被声明为虚函数。

尽管构造函数不可以为虚函数，但是有些场景下我们确实需要 “Virtual Copy Constructor”。  
“虚复制构造函数”的说法并不严谨，其只是一个实现了对象复制的功能的类内函数。  
举一个应用场景，比如剪切板功能。 复制内容作为基类，但派生类可能包含文字、图片、视频等等。我们只有在程序运行的时候才知道我们需要复制的具体是什么类型的数据。

> 代码样例：
[copy_construct.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/9.%20virtual/set3/copy_consrtuct.cpp)、
[vir_con.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/9.%20virtual/set3/vir_con.cpp)

（3） **析构函数可以为虚函数吗？**

**析构函数可以声明为虚函数。如果我们需要删除一个指向派生类的基类指针时，应该把析构函数声明为虚函数。 事实上，只要一个类有可能会被其它类所继承， 就应该声明虚析构函数(哪怕该析构函数不执行任何操作)。**

> 代码样例：
[full_virde.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/9.%20virtual/set3/full_virde.cpp)、
[vir_de.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/9.%20virtual/set3/vir_de.cpp)

具体可参见：《Effective C++ 改善程序与设计的55个具体做法》条款07: 为多态基类声明virtual 析构函数 Declare destructors virtual in polymorphic base classes.

（4） **虚函数可以为私有函数吗？**

- 基类指针指向继承类对象，则调用继承类对象的函数；
- int main()必须声明为Base类的友元，否则编译失败。 编译器报错： ptr无法访问私有函数。 当然，把基类声明为`public`， 继承类为`private`，该问题就不存在了。

> 代码样例：
[virtual_function.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/9.%20virtual/set3/virtual_function.cpp)、
[virtual_function1.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/9.%20virtual/set3/virtual_function1.cpp)

（5） **虚函数可以为被内联吗？**

**通常类成员函数都会被编译器考虑是否进行内联。 但通过基类指针或者引用调用的虚函数必定不能被内联。 当然，实体对象调用虚函数或者静态调用时可以被内联，虚析构函数的静态调用也一定会被内联展开。**

- 虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联；
- 内联是在编译器建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时（运行期）不可以内联；
- `inline virtual`唯一可以内联的时候是：编译器知道所调用的对象是哪个类（如`Base::who()`），这只有在编译器具有实际对象而不是对象的指针或引用时才会发生。

> 代码样例：
[virtual_inline.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/9.%20virtual/set3/virtual_inline.cpp)、
[inline_virtual.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/9.%20virtual/set3/inline_virtual.cpp)

## 5. RTTI与dynamic_cast

RTTI（Run-Time Type Identification)，通过运行时类型信息程序能够使用基类的指针或引用来检查这些指针或引用所指的对象的实际派生类型。

在面向对象程序设计中，有时我们需要在运行时查询一个对象是否能作为某种多态类型使用。与Java的instanceof，以及C#的as、is运算符类似，C++提供了dynamic_cast函数用于动态转型。相比C风格的强制类型转换和C++ reinterpret_cast，dynamic_cast提供了类型安全检查，是一种基于能力查询(Capability Query)的转换，所以在多态类型间进行转换更提倡采用dynamic_cast。

> 代码样例：
[rtti.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/9.%20virtual/set4/rtti.cpp)、
[warn_rtti.cpp](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/9.%20virtual/set4/warn_rtti.cpp)

## 6. 纯虚函数和抽象类

> 详见：
[纯虚函数和抽象类那些事](https://github.com/Vuean/CPlusPlusThings/tree/master/basic_content/7.%20abstract)
