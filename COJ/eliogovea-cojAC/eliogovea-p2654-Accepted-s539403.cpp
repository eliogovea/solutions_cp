#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long n;
string s;
int main()
{
    cin >> n;

    int k=0;

    while(n-(1<<k)>=0)
    {
        n-=(1<<k);
        k++;
    }

    //cout << n << " " << k <<  endl;

    for(int i=0; i<k; i++)
    {
        if(n&(1<<i))s+='7';
        else s+='4';
    }
    reverse(s.begin(),s.end());

    cout << s << endl;
}
