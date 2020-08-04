#include <iostream>
using namespace std;

int main()
{
    int num = 2020;
    int * const ptr = &num; // const指针必须初始化，且const指针的值（即表示ptr只能指向num？？？）不能修改
    int *t = &num;
    *t = 2012;

    cout << "ptr: " << *ptr << endl;
    cout << "t: " << *t << endl;
    cout << "num: " << num << endl;

    return 0;
}
/*
输出：
ptr: 2012
t: 2012
num: 2012
*/