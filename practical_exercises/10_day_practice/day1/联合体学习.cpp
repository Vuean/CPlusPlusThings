#include <iostream>
using namespace std;

// ��ͬ���ڴ��ַ
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
    a.k = 0;    // ���ǵ���һ��int�ռ�ֵ
    a.m = 2020;
    printf("%d %d %d %d %d\n", a.u.x, a.u.y, a.u.z, a.k, a.m);
    system("pause");
    return 0;
}

/*
һ�� union �����ж�����ݳ�Ա������������ʱ��ֻ��һ�����ݳ�Ա������ֵ.
�����2020 5 6 2020 2020
*/