#include <iostream>
using namespace std;

class Copyable
{
public:
    Copyable()
    {
        cout << "Copyable" << endl;
    }
    Copyable(const Copyable &o)
    {
        cout << "Copied" << endl;
    }
};

Copyable ReturnRvalue()
{
    return Copyable();  //返回一个临时对象
}

void AcceptVal(Copyable a)
{

}
void AcceptRef(const Copyable& a)
{

}

int main()
{
    cout << "pass by value: " << endl;
    AcceptVal(ReturnRvalue()); // 应该调用两次拷贝构造函数

    cout << "pass by reference: " << endl;
    AcceptRef(ReturnRvalue()); //应该只调用一次拷贝构造函数
}

// 实际均未调用拷贝构造函数