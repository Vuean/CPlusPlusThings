#include <iostream>
using namespace std;

int main()
{
    const int *ptr;
    *ptr = 10;  // error: 表达式必须是可修改的左值
    return 0;
}