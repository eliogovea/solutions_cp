#include<cstdio>
#include<cmath>
using namespace std;

const double PI = 3.141592653589793, x=tan(PI/4.0)+tan(PI/3.0)+tan(5.0*PI/12.0);

int n;
double r;

int main(){
    scanf("%d",&n);
    while(n--){
               scanf("%lf",&r);
               printf("%.4f\n",r*r*x);
               }
    return 0;
    }
