#include<cstdio>
#include<cmath>
#include<iostream>

typedef unsigned long long ll;

ll AA,a,b,c,A,B,C;
int n;
double vol;

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d%d%d%d",&c,&B,&A,&a,&b,&C);

        a*=a;   b*=b;   c*=c;
        A*=A;   B*=B;   C*=C;

        AA = a*A*(b+B+c+C-a-A)+b*B*(a+A-b-B+c+C)+c*C*(a+A+b+B-c-C)-A*B*C-a*b*C-a*B*c-A*b*c;

        vol=(sqrt(AA))/12.0;

        printf("%.4f\n",vol);
    }
return 0;
}
