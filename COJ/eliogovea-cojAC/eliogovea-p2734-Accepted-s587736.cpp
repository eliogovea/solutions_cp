#include <iostream>
#include <algorithm>
using namespace std;

int s, x;
string op;

int main()
{
    while (cin >> op >> x)
    {
        if (op[0] == 's') s += x;
        else s -= x;
    }
    cout << "resultado: " << s << endl;
}
