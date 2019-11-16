#include<cstdio>

int a[1001],c,d,b;

int main()
{
    for(int i=1; i<1001; i++)
    {
        int j=i;
        a[i]=a[i-1];
        while(j)
        {
            a[i]+=j&1;
            j>>=1;
        }
    }
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&d,&b);
        printf("%d\n",a[b]-a[d-1]);
    }
    return 0;
}
