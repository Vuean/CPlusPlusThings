#include <iostream>
using namespace std;
struct student
{
    int num;
    char name[21];
    char gender;
};

int main()
{
    student s = {10, "China", 'M'};
    cout << s.num << endl;

    cout << "sizeof(s.num): " << sizeof(s.num) << endl;
    cout << "sizeof(s.name): " << sizeof(s.name) << endl;
    cout << "sizeof(s.gender): " << sizeof(s.gender) << endl;
    
    cout<<"---------------"<<endl;

    cout << "sizeof(student): " << sizeof(student) << endl;
    cout << "sizeof(s): " << sizeof(s) << endl;
    return 0;
}