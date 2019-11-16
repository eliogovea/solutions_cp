#include<cstdio>

long a,b,c;

int gcd(long a, long b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    while(scanf("%ld%ld%ld",&a,&b,&c))
    {
        if(a==0 && b==0 && c==0)break;
        printf("%s\n",(c%gcd(a,b))?"NO":"YES");
    }
    return 0;
}
