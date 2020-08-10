/*
ignore_assert.cpp
忽略断言
*/

# define NDEBUG // 忽略断言
#include <assert.h>
#include <iostream>
using namespace std;

int main()
{
    int x = 7;
    assert(x == 5);
    cout << "x = " << x << endl;
    return 0;
}