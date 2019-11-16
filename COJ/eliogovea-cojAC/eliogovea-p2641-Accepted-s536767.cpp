#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

double h,m;

int main()
{
    scanf("%lf%lf",&h,&m);
    printf("%.0lf\n",h-1);
    for(int i=0; i<h-1; i++)
        printf("%d:%.1lf\n",i,i*m/(h-1));

}
