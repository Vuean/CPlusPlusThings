#include <iostream>
using namespace std;

int f(int n)
{
    if(0 > n)
    {
        return 0;
    }
    else if(0 == n)
    {
        return 1;
    }
    else
    {
        return n * f(n-1);
    }
}

int main()
{
    cout << "input x: ";
    int x;
    cin >> x;

    cout << f(x) << endl;
    return 0;
}