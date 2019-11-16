#include<cstdio>

int n,k,a[100],ans,cas;

int main()
{
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&n,&k);

        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);

        for(int i=0; a[i] && i<k; i++)
            ans=i+1;

        if(a[k-1])
            for(int i=k; a[k-1]==a[i] && i<n; i++)
                ans++;
        printf("%d\n",ans);
        ans=0;
    }

    return 0;
}
