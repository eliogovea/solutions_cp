#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string str;
int a, b;

int main()
{
    cin >> str;
    int s = str.size();
    for (int i = 0; i < s; i++)
    if (str[i] == '0') {
        b++;
        a += (str[ (i + 1) % s ] == '0');
    }
    if (a * s > b * b) cout << "SHOOT\n";
    else if (a * s == b * b) cout << "EQUAL\n";
    else cout << "ROTATE\n";
}
