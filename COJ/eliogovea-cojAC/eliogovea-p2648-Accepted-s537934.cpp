#include<cstdio>
#include<cmath>

int c;
double r,n,l,htri,apo,ab,hpid;

int main()
{
    for(scanf("%d",&c);c--;)
    {
        scanf("%lf%lf",&r,&n);
        l=2.0*r*sin(M_PI/n);
        htri=sqrt(3.0)*l/2.0;
        apo=r*cos(M_PI/(n));
        if(htri*htri-apo*apo>0.0)
        {
            ab=n*r*r*sin(2.0*M_PI/(n))/2.0;
            hpid=sqrt(htri*htri-apo*apo);
            printf("%.2lf\n",ab*hpid/3.0);
        }
        else printf("impossible\n");
    }
}
