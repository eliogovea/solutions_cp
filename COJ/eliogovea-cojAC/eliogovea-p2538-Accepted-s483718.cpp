#include<cstdio>

const long MOD = 1000000000;

int n,r;
long x,r0,r1,r2,nr0,nr1,nr2;

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        r=x%3;
        if(r==0)
        {
            nr0=(r0+r0+1)%MOD;
            nr1=(r1+r1)%MOD;
            nr2=(r2+r2)%MOD;
            r0=nr0;
            r1=nr1;
            r2=nr2;
        }
        else if(r==1)
        {
            nr0=(r0+r2)%MOD;
            nr1=(r1+r0+1)%MOD;
            nr2=(r2+r1)%MOD;
            r0=nr0;
            r1=nr1;
            r2=nr2;
        }
        else if(r==2)
        {
            nr0=(r0+r1)%MOD;
            nr1=(r1+r2)%MOD;
            nr2=(r2+r0+1)%MOD;
            r0=nr0;
            r1=nr1;
            r2=nr2;
        }
    }
    printf("%d\n",r0);
    return 0;
}
