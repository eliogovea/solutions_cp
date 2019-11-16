#include<cstdio>
using namespace std;

const int MAX=500001;
long sd[MAX];
int c,n;

int main(){
    for(int i=1; i<=MAX; i++){
            for(int j=i; j<=MAX; j+=i)sd[j]+=i;
            sd[i]-=i;
            }
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&n);
        printf("%d\n",sd[n]);
    }
    return 0;
    }
