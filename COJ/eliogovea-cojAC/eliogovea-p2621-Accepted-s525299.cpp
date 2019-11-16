#include<cstdio>
#include<cmath>
using namespace std;

int ans,n;

int main()
{
    scanf("%d",&n);
    while(n)
    {
        ans++;
        n/=2;
    }
    printf("%d\n",ans);
}