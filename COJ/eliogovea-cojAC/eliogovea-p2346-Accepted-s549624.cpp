#include<cstdio>
#include<cmath>

double R,r,H,h,c;

int main()
{
	while(scanf("%lf%lf%lf%lf",&r,&R,&H,&h))
	{
	    if(R==0.0 && r==0.0 && H==0.0 && h==0.0)break;
        if(R==r)
        {
            double v=M_PI*R*R*(H-h);
            printf("%.4lf\n",v);
            continue;
        }
		double c=r*H/(R-r);
		double rc=r*(h+c)/c;
		double vt=M_PI*( R*R*(H+c) - r*r*c )/3.0;
		double vp=M_PI*( rc*rc*(h+c) - r*r*c )/3.0;

		printf("%.4lf\n",vt-vp);
	}
}
