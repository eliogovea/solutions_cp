#include<iostream>
#include<cmath>
using namespace std;
long long m,n,c,r;

int main()
{
    while(cin >> m)
    {
        n=m;
        r=1;
        for(long i=2; i*i<=n; i++)
        {
            c=0;
            while(n%i==0)
            {
                n/=i;
                c++;
            }
        if(c)r*=pow(i,c-1)*(i-1);
        }
    if(n>1)r*=(n-1);

    cout << m-r << endl;
    }
return 0;
}
