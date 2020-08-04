#include <iostream>
using namespace std;

int main()
{
    const int num = 2020;
    const int * const ptr = &num;
    cout << "ptr: " << *ptr << endl;

    return 0;
}

/*
输出：
ptr: 2020
*/