#include<cstdio>

int n;

int main()
{
    scanf("%d",&n);
    n--;
    printf("%d\n",n*(n+1)*(n+1)*(n+2)/12);
    return 0;
}
