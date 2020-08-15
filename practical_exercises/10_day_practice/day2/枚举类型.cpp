#include <iostream>
using namespace std;

enum weekday
{
    s, m, t, w, thu, f, sl
};

int main()
{
    weekday wek = s;
    for(int i = wek; i != f; ++i)
    {
        cout << i << endl;
        cout << wek+s << endl;
        cout<<"-------·Ö¸îÏß-------"<<endl;
    }

    cout << wek+m << endl;
    cout << wek+t << endl;
    return 0;
}