#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int a,b,c;
double r,A,p;

int main(){
    while( scanf("%d%d%d",&a,&b,&c)!=EOF ){
           if(2*max(a,max(b,c))>a+b+c)printf("ERROR\n");
           else if(2*max(a,max(b,c))==a+b+c)printf("0.00 %.2f\n",(double)max(a,max(b,c))/2.0);
           else{
                p=(double)(a+b+c)/2;
                A=sqrt(p*(p-a)*(p-b)*(p-c));
                printf("%.2f %.2f\n",A/p,(double)(a*b*c)/(4.0*A));
                }
           }
    return 0;
    }
