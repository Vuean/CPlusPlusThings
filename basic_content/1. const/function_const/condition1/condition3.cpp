#include <iostream>
using namespace std;

int main()
{
    const int *ptr;
    int val = 3;
    ptr = &val; // ok，可行的
    
    int *ptr1 = &val;
    *ptr1 = 4;

    cout << "ptr: " << *ptr << endl;
    cout << "ptr1: " << *ptr1 << endl;
    cout << "val: " << val << endl; 
    return 0;
}

/*
输出：
ptr: 4
ptr1: 4
val: 4
*/