#include<cstdio>
#include<algorithm>
using namespace std;
int n,mx;

int main()
{
    while(scanf("%d",&n) && n)
    {
        mx=n;
        while(n!=1)
        {
            if(n&1)n=3*n+1;
            else n=n/2;
            mx=max(mx,n);
        }
        printf("%d\n",mx);
    }
}
