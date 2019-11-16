#include<cstdio>
#include<cmath>

int m1,m2,m3;
double a,p,M1,M2,M3;

int main()
{
    for(int i=1; i<=1000; i++)
    {
        scanf("%d%d%d",&m1,&m2,&m3);
        double M1=(double)m1,M2=(double)m2,M3=(double)m3;
        p=(M1+M2+M3)/2;
        if(M1>=p||M2>=p||M3>=p)printf("-1.000\n");
        else printf("%.3lf\n",4.0*sqrt(p*(p-M1)*(p-M2)*(p-M3))/3.0);
    }
    return 0;
}
