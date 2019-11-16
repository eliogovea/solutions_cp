#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char a[1001];

int n,s,s1,s2;

int main()
{
    cin >> n;
    while(n--)
    {
        s=s1=s2=0;
        cin >> a;
        int l=strlen(a);
        if(a[l-1]!='0' && a[l-1]!='5'){cout << "NO"  <<  endl;continue;}
        for(int i=0; i<l; i++)s+=(a[i]-'0');
        if(s%9!=0){cout << "NO" << endl; continue;}
        for(int i=0; i<l; i+=2)s1+=(a[i]-'0');
        for(int i=1; i<l; i+=2)s2+=(a[i]-'0');
        if((abs(s1-s2))%11!=0){cout << "NO" << endl;continue;}
        cout << "YES" << endl;
    }
return 0;
}
