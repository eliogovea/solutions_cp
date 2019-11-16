#include<iostream>
#include<limits.h>
using namespace std;

char n1[20],n2[20];
int a1[10000],a2[10000];
long mx1,mx2,n,t,s1,s2;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> n1;
        for(int i=0; i<n; i++)cin >> a1[i];
        cin >> n2;
        for(int i=0; i<n; i++)cin >> a2[i];

        mx1=mx2=INT_MIN;
        for(int i=0; i<n; i++)
        {
            s1+=a1[i];
            s2+=a2[i];			
            if(mx1<s1)mx1=s1;
            if(mx2<s2)mx2=s2;
            if(s1<0)s1=0;
            if(s2<0)s2=0;
        }

        if(mx1>mx2)cout << n1 << " " << mx1 << endl;
        else if(mx1<mx2)cout << n2 << " " << mx2 << endl;
        else cout << "Tied " << mx1 << endl;

        s1=s2=0;
    }
    return 0;
}
