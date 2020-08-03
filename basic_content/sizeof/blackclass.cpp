// blackclass.cpp
// 空类的大小为1字节
#include <iostream>
using namespace std;
class A{};

int main() {
    cout << sizeof(A) << endl;
    return 0;
}