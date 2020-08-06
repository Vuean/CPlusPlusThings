// 虚函数的调用取决于指向或者引用的对象的类型，而不是指针或者引用自身的类型

#include <iostream>
using namespace std;

class Employee
{
public:
    virtual void raiseSalary()
    {
        cout << 0 << endl;
    }

    virtual void promote()
    {
        /* common promote code */
    }
};

class Manager : public Employee
{
    virtual void raiseSalary()
    {
        cout << 100 << endl;
    }

    virtual void promote()
    {
        /* manager specific promote */
    }
};

class Enginner : public Employee
{
    virtual void raiseSalary()
    {
        cout << 200 << endl;
    }

    virtual void promote()
    {
        /* manager specific promote */
    }
};

// emp为指针数组
void globalRaiseSalary(Employee *emp[], int n)
{
    for(int i = 0; i < n; i++)
    {
        emp[i]->raiseSalary();
    }
}

int main()
{
    Employee *emp[] = {new Manager(), new Enginner};
    globalRaiseSalary(emp, 2);
    return 0;
}

/* 
输出
100
200
*/