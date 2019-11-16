#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double l,ans,N,K;
int n,k;

int main()
{
    while(cin >> l >> n >> k)
    {
        N=(double)n;
        K=(double)k;

        if(l==0 && n==0 && k==0)break;

        ans=sqrt(3)*l*l*(double(N*N-3.0*K*N+3.0*K*K))/4.0/(N*N);
        printf("%.0f\n",ans);
    }
return 0;
}
