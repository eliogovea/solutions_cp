#include<iostream>
using namespace std;

string s;
int c,sol;

int main()
{
    cin >> s;
    for(string::iterator si=s.begin(); si!=s.end(); si++)
    {
        if(*si=='(')c++;
        else c--;
        if(c<0)sol++,c+=2;
    }
    cout << sol+int(c/2) << endl;
}
