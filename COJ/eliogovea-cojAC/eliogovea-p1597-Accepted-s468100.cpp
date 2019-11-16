#include<cstdio>
#include<algorithm>
using namespace std;

int n,h,l,a[5000000];
double s;
int main(){
    while(scanf("%d%d%d",&h,&l,&n)){
              if(h==0 && l==0 && n==0)break;
              else{
                   s=0;
                   for(int i=0; i<n; i++)scanf("%d",&a[i]);
                   sort(a,a+n);
                   for(int i=l; i<n-h; i++)s+=a[i];
                   s/=n-h-l;
                   printf("%.6f\n",s);
                   }
              }
    return 0;
    }
