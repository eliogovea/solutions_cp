#include<cstdio>

long n;

int main()
{
    while(scanf("%ld",&n) && n)
    printf("%ld\n",n*(n+1)*(2*n+1)/6);
    return 0;
}
