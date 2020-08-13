#include <iostream>
using namespace std;

// 相同的内存地址
union myun
{
    struct { int x; int y; int z;}u;
    int k;
    int m;
}a;

int main()
{
    a.u.x = 4;
    a.u.y = 5;
    a.u.z = 6;
    a.k = 0;    // 覆盖掉第一个int空间值
    a.m = 2020;
    printf("%d %d %d %d %d\n", a.u.x, a.u.y, a.u.z, a.k, a.m);
    system("pause");
    return 0;
}

/*
一个 union 可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值.
输出：2020 5 6 2020 2020
*/