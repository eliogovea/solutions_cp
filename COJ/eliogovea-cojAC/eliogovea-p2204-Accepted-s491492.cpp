#include<cstdio>

int c,n;

int main()
{
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&n);
        for(int i=2; i<=n; i++)printf("%d ",i);
        printf("1\n");
    }
    return 0;
}
