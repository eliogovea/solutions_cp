#include<cstdio>
#include<algorithm>
using namespace std;

int n,a,b;

int main()
{
    while(scanf("%d%d%d",&n,&a,&b)!=EOF)printf("%d\n",min(n-a,b+1));
    return 0;
}
