#include<iostream>
using namespace std;

typedef string::iterator si;

string num;
int r;

int main()
{
    while(cin >> num)
    {
        r=0;
        for(si i=num.begin(); i!=num.end(); i++)
            r=(r+(*i-'0'))%3;

        if(r==0)cout << '1' << endl;
        else if(r==1)cout << '7' << endl;
        else cout << '4' << endl;
    }
    return 0;
}
