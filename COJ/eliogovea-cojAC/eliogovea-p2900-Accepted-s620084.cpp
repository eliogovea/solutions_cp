#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string str, aux, mn;
int main()
{
    for (int i = 0; i <= 50; i++) mn += "z";
    cin >> str;
    int s = str.size();
    for (int i = 0; i < s - 2; i++)
    for (int j = i + 1; j < s - 1; j++) {
        aux = "";
        for (int k = i; k >= 0; k--) aux += str[k];
        for (int k = j; k > i; k--) aux += str[k];
        for (int k = s - 1; k > j; k--) aux += str[k];
        mn = min(mn, aux);
    }
    cout << mn << endl;
}
