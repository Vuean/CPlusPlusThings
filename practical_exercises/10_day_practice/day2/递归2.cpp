#include <iostream>
using namespace std;

int f(int n, int k)
{
    if((n == k) || (k == 0))
    {
        return 1;
    }
    else
    {
        return f(n-1, k-1) + f(n-1, k);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    if (n < k)
    {
        return -1;
    }
    
    cout << f(n, k) << endl;
    return 0;
}