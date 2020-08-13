#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int i, j, k, f;
    for(i = 0; i <= 4; i++)
    {
        for(j = 1; j <= 30; j++)
            cout << " ";
        for(k = 1; k < 8-2*i; k++)
            cout << " ";
        for(f = 1; f <= 2 * i; f++)
            cout << "*";
        cout << endl;
    }
    system("pause");    // system("pause")让程bai序暂停，观察运行结果
    return 0;
}