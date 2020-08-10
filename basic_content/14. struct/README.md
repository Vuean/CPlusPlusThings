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

```