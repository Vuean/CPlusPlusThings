# const那些事
## 0. 项目来源及原作者
	https://github.com/Light-City/CPlusPlusThings
	原作者个人公众号：guangcity
## 1. const含义
常类型是指使用类型修饰符const说明的类型，常类型的变量或对象的值是不能被更新的。
## 2. const作用
- 可以定义常量
	
	`<const int a = 100;>`
- 类型检查
	- ```const```常量与```#define```宏定义常量的区别:    
	  ->const常量具有类型，编译器可以进行安全检查；	    
	  ->#define宏定义没有数据类型，知识简单的字符串替换，不能进行安全检查；
	- const定义的变量只有类型为整数或者枚举，且以常量表达式初始化时才能作为常量表达式；
	- 其他情况下它只是一个```const```限定的变量，不能与常量混淆；
- 防止修改，起保护作用；	    
	```
	void f(const int i) 
	{
		i++;	// error
	}
	```
- 可以节省空间，避免不必要的内存分配；
	- ```const```定义常量从汇编的角度来看，只是给出了对应的内存地址，而不是像```#define```一样给出的是立即数；
	- ```const```定义的常量在程序运行过程中只有一份拷贝，而```#define```定义的常量在内存中有若干个拷贝；
## 3. const对象默认为文件的局部变量
*注意*：非const变量默认为extern。要使const变量能够在其他文件中访问，必须在文件中显式地指定它为extern.  

	未被const修饰的变量在不同文件的访问:  
```
	// file1.cpp  
	int ext; 

	// file2.cpp 
	#include <iostream>
	extern int ext;  
	int main() {
		std::cout << (ext+10) << std::endl;
	} 
```
	const常量在不同文件的访问：
```
	// extern_file1.cpp
	exter const int ext = 12;  

	// extern_file2.cpp
	#include <iostream>
	extern const int ext;
	int main() {
		std::cout << ext << std::endl;
	}	
```
**小结：**  
可以发现未被```const```修饰的变量不需要```extern```显示声明，而```const```常量需要显示声明```extern```，并且需要做初始化（常量在定义时必须初始化）。
## 4. 定义常量










# 备注
	内容来自上述项目，侵删。

