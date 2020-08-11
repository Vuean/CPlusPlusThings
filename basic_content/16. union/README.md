# union那些事

## 0. 项目来源

原项目网址：<https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/union>  
原作者个人微信公众号：guangcity  
![guangcity](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/8.%20vptr_vtable/img/wechat.jpg)

## 1. 正文

联合(union)是一种节省空间的特殊的类，一个 `union` 可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值。当某个成员被赋值后其他成员变为未定义状态。联合有如下特点：

- 默认访问控制符为public；
- 可以含有构造函数、析构函数；
- 不能含有引用类型的成员；
- 不能继承自其他类，不能作为基类；
- 不能含有虚函数；
- 匿名 `union` 在定义所在作用域可直接访问 `union`成员；
- 匿名 `union` 不能包含 `protected` 成员或 `private` 成员；
- 全局匿名联合必须是静态（`static`）的。
