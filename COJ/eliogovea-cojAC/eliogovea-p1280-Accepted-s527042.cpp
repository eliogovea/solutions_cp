#include<cstdio>

int n;

int main()
{
    while(scanf("%d",&n) && n)
        printf("%d => %d\n",n,n*n-n+1);
    return 0;
}
