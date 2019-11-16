#include<cstdio>
#include<cmath>

const double PI = 3.141592653589793;
double x1,x2,x3,i1,i2,i3,xv1,a,r,l1,l2,l3,p;

int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&i1,&x2,&i2,&x3,&i3)!=EOF)
    {

        l1=sqrt((x1-x2)*(x1-x2)+(i1-i2)*(i1-i2));
        l2=sqrt((x1-x3)*(x1-x3)+(i1-i3)*(i1-i3));
        l3=sqrt((x2-x3)*(x2-x3)+(i2-i3)*(i2-i3));

        p=(l1+l2+l3)/2;
        a=sqrt(p*(p-l1)*(p-l2)*(p-l3));

        r=l1*l2*l3/(4.0*a);

        printf("%.2f\n",2*PI*r);
    }
return 0;
}
