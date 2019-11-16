#include<cstdio>
#include<cmath>
using namespace std;

int r,n;
double s;

int main(){
    scanf("%d",&n);
    while(n--){
               scanf("%d",&r);
               s=sqrt(3)*(3-sqrt(3))*r/(3.0);
               printf("%.1f\n",s); 
               }
    return 0;
    }
