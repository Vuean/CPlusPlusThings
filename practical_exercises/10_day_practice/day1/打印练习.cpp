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
    system("pause");    // system("pause")�ó�bai����ͣ���۲����н��
    return 0;
}