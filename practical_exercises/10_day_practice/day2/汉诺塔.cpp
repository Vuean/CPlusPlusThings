#include<iostream>
using namespace std;

void move(char A, char B);
void hanoi(int n, char A, char B, char C);

int main()
{
    cout << "汉诺塔：";
    int disks;
    cin >> disks;

    hanoi(disks, 'A', 'B', 'C');
    return 0;
}

void move(char A , char B)
{
    cout << A << "->" << B << endl;
}

void hanoi(int n, char A, char B , char C)
{
    if(n == 1)
        move(A, C);
    else
    {
        hanoi(n-1, A, C, B);
        move(A, C);
        hanoi(n-1, B, A, C);
    }
}