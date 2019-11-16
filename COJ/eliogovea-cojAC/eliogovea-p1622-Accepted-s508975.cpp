#include<cstdio>

int cas,n,a[100],sum,ans,x;

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&x);
            a[i]=x&1;
            sum=(sum==a[i])?0:1;
        }

        for(int i=0; i<n; i++)
            ans+=(a[i]==sum);
        printf("%d\n",ans);

        ans=sum=0;
    }
    return 0;
}
