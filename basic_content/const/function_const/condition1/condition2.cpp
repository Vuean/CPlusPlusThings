#include <iostream>
using namespace std;

int main()
{
    const int p = 10;
    const void *vp = &p;
    void *vp = &p;  // error: “const int *”类型的值不能用于初始化“void *”类型的实体
    return 0;
}