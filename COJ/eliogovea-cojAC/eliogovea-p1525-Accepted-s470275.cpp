#include<cstdio>
using namespace std;

long n,m,s,r=1;

int main(){
    scanf("%d%d",&n,&m);
    while(m&1 && n&1){
              s+=r;
              r*=4; 
              m=(m-1)/2;
              n=(n-1)/2;
              }
    printf("%d",s);
    return 0;
    }
