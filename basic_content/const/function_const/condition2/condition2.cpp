#include <iostream>
using namespace std;

int main()
{
    const int num = 0;
    int * const ptr = &num; // error：“const int *”类型的值不能用于初始化“int *const”类型的实体
    cout << "ptr: " << *ptr << endl;

    return 0;
}