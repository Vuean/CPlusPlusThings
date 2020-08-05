/*
interesting_facts4.cpp
抽象类可以有构造函数
*/

#include<iostream> 
using namespace std; 

// An abstract class with constructor 
class Base 
{ 
    protected: 
        int x; 
    public: 
        virtual void show() = 0; 
        Base(int i) { x = i; } 
}; 

class Derived: public Base 
{ 
    int y; 
    public: 
    Derived(int i, int j):Base(i) { y = j; } 
    void show() { cout << "x = " << x << ", y = " << y; } 
}; 

int main(void) 
{ 
    Derived d(4, 5); 
    d.show();   // 输出x = 4, y = 5
    return 0; 
} 