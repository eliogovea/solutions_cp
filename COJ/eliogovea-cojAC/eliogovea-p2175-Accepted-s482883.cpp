#include<cstdio>

bool sieve[1000001];
int pmayor[100001],pmenor[100001],a,b,n,p,x;

int main()
{
    for(int i=2; i<=1000000; i++)sieve[i]=1;

    for(int i=2; i*i<=100050; i++)
    {
        if(sieve[i])
        {
            for(int j=i*i; j<=100050; j+=i)sieve[j]=0;
        }
    }

    p=2;
    for(int i=2; i<=100000; i++)
    {
        if(sieve[i])p=i;
        pmenor[i]=p;
    }

    p=100003;
    for(int i=100000; i>=2; i--)
    {
        if(sieve[i])p=i;
        pmayor[i]=p;
    }

    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        printf("%d %d\n",pmenor[x],pmayor[x]);
    }
    return 0;
}
