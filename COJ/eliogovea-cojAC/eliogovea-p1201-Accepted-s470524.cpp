#include<cstdio>
#include<algorithm>

int c,n,a[1000],s;

int main(){
    scanf("%d",&c);
    while(c--){
               scanf("%d",&n);
               s=0;
               for(int i=0; i<n; i++)scanf("%d",&a[i]);
               std::sort(a,a+n);
               for(int i=0; i<n; i++)if(s < a[i]*(n-i))s=a[i]*(n-i);
               printf("%d\n",s);
               }
    return 0;
    }
