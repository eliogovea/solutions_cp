#include<cstdio>
#include<cmath>

const double c = sqrt(3)/4.0;
double l;

int main()
{
    while(scanf("%lf",&l)!=EOF)
        printf("%.6f\n",c*l);
    return 0;
}
