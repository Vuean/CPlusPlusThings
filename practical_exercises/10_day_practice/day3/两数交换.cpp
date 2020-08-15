#include <iostream>
using namespace std;

void swap(int &a, int &b);

int main()
{
    int x1(2020);
    int x2(8);
    cout << "Before swap" << endl;
    cout << "x1: " << x1 << endl;
    cout << "x2: " << x2 << endl;

    swap(x1, x2);
    cout << "After swap" << endl;
    cout << "x1: " << x1 << endl;
    cout << "x2: " << x2 << endl;
    return 0;
}

void swap(int &a, int &b)
{
    int tempint = a;
    a = b;
    b = tempint;
}