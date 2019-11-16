#include<cstdio>

int n,a[50001];

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%d",&a[i]);

    for(int i=1; i<=n; i++)
    {
        if(i>1 && a[i]<a[i-1])continue;
        if(i<n && a[i]<a[i+1])continue;

        printf("%d\n",i);
    }
    return 0;
}
