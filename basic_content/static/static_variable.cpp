#include <iostream>
using namespace std;

class Apple
{
public:
    static int i;
    Apple () { }
};

int Apple::i = 2020;

int main()
{
    Apple obj1;
    cout << obj1.i << " ";
    Apple obj2;
    cout << obj2.i << " ";
    return 0;
}