#include<cstdio>
#include<algorithm>
using namespace std;

const int ML = 2100;

typedef struct
{
    int len,d[ML];
    void bigint()
    {
        len=1;
        for(int i=0; i<ML; i++)
            d[i]=0;
    }
}bigint;

bigint asigna(int n)
{
    bigint a=bigint();
    for(int i=1; n; i++)
    {
        a.d[i]=n%10;
        n/=10;
        a.len=i;
    }
    return a;
}

bigint suma(bigint a, bigint b)
{
    bigint c=bigint();
    int s,ac=0;
    c.len=max(a.len,b.len);
    for(int i=1; i<=c.len; i++)
    {
        s = ac+a.d[i]+b.d[i];
        c.d[i]=s%10;
        ac=s/10;
    }
    if(ac)
    {
        c.len++;
        c.d[c.len]=ac;
    }
    return c;
}

bigint fib[10003];
int cas,n;

int main()
{
    fib[1]=fib[2]=asigna(1);

    for(int i=3; i<=10001; i++)
    {
        fib[i]=bigint();
        fib[i]=suma(fib[i-1],fib[i-2]);
    }

    while(scanf("%d",&n) != EOF)
    {
        bigint ans = suma(fib[n-1],fib[n+1]);
        //printf("%d\n", ans.len);
        for(int i=ans.len; i; i--)
            printf("%d",ans.d[i]);
        printf("\n");
    }
    return 0;
}
