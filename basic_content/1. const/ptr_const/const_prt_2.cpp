#include <iostream>
using namespace std;

int main() {
    const int num = 2020;
    // int * const ptr = &num; // error！ const int* -> int*
    // &num的类型为：const int* 指向常量的指针
    const int *ptr = &num;
    // 或者可更改为：
    const int *const ptr2 = &num;

    cout << *ptr << endl;
    cout << *ptr2 << endl;
}