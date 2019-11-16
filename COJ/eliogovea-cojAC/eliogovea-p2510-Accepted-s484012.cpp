#include<cstdio>
#include<cmath>

int D1,D2,D3;
double r12,r13,r23,a,b,c,A,r1,r2,r3;

int main()
{
    while(scanf("%d%d%d",&D1,&D2,&D3)!=EOF)
    {
        r1=(double)D1/2;
        r2=(double)D2/2;
        r3=(double)D3/2;

        A=sqrt((r1+r2+r3)*r1*r2*r3);

        r12=r1+r2;
        r13=r1+r3;
        r23=r2+r3;

        a=acos((r12*r12+r13*r13-r23*r23)/(2.0*r12*r13));
        b=acos((r12*r12+r23*r23-r13*r13)/(2.0*r12*r23));
        c=acos((r13*r13+r23*r23-r12*r12)/(2.0*r13*r23));

        A = A - a*r1*r1/2.0 - b*r2*r2/2.0 - c*r3*r3/2.0;

        printf("%.8f\n",A);
    }
return 0;
}
