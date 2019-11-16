#include<iostream>
using namespace std;

char c;
int cas,ta,x,in;

int main()
{
    cin >> cas;
    while(cas--)
    {
        cin >> in >> ta;
        while(ta--)
        {
            cin >> c >> x;
            if(c=='C')in+=x;
            else in-=x;
        }
        cout << in << endl;
    }
    return 0;
}
