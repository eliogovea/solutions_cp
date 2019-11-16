#include<cstdio>
#include<cmath>

long n,ans;

int main()
{
    while(scanf("%d",&n) && n)
    {
        ans=ceil(sqrt(n));
        printf("%d\n",ans);
    }
return 0;
}
