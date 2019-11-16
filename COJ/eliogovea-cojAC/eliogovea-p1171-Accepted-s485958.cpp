#include<cstdio>
#include<cmath>
#include<iostream>

typedef unsigned long long ll;

int n;
ll AA,a,b,c,A,B,C;
double vol,At,r;

double areat(ll l1, ll l2, ll l3)
{
    double p = (double)(l1+l2+l3)/2;
    double a = sqrt(p*(p-l1)*(p-l2)*(p-l3));
    return a;
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d%d%d%d",&c,&B,&A,&a,&b,&C);

        At=areat(a,b,C)+areat(a,B,c)+areat(A,B,C)+areat(A,b,c);

        a*=a;   b*=b;   c*=c;
        A*=A;   B*=B;   C*=C;

        AA = a*A*(b+B+c+C-a-A)+b*B*(a+A-b-B+c+C)+c*C*(a+A+b+B-c-C)-A*B*C-a*b*C-a*B*c-A*b*c;

        vol=(sqrt(AA))/4.0;
        r=vol/At;
        printf("%.4f\n",r);
    }
return 0;
}
