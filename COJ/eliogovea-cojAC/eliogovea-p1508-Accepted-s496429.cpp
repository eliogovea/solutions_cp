#include<cstdio>

int n;
double a1,a2,h1,h2;

int main(){
    scanf("%d",&n);
    while(n--){
               scanf("%lf%lf%lf",&a1,&a2,&h1);
               printf("%.2lf\n",a1*h1/a2);
               }
    return 0;
    }
