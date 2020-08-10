# struct与class区别

## 0. 项目来源

原项目网址：<https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/struct_class>  
原作者个人微信公众号：guangcity  
![guangcity](https://github.com/Vuean/CPlusPlusThings/blob/master/basic_content/8.%20vptr_vtable/img/wechat.jpg)

## 1. 正文

关于C与C++中struct内容：见[struct那些事](https://github.com/Vuean/CPlusPlusThings/tree/master/basic_content/14.%20struct)

总的来说，`struct` 更适合看成是一个数据结构的实现体，`class` 更适合看成是一个对象的实现体。

两者最本质的区别：默认的访问控制

默认的继承访问权限。`struct` 是`public` 的，`class` 是`private` 的。

`struct`作为数据结构的实现体，它默认的数据访问控制是 `public` 的，而 `class` 作为对象的实现体，它默认的成员变量访问控制是 `private` 的。