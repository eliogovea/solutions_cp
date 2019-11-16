#include<cstdio>

long n,m,t;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        if(!m || !n)printf("0\n");
        else printf("%d\n",(m+n+!(m&1)+!(n&1))/2);
    }
    return 0;
}
