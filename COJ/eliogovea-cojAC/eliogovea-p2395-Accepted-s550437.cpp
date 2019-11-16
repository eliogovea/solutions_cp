#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAXN 50010
#define LOGMAXN 20

int n,q,a,b,lg,mx,mn;
int MAX[MAXN][LOGMAXN];
int MIN[MAXN][LOGMAXN];

int main()
{
	scanf("%d%d",&n,&q);

	for(int i=1; i<=n; i++)
        scanf("%d",&MAX[i][0]),
        MIN[i][0]=MAX[i][0];


    for(int j=1; 1<<j <= n; j++)
        for(int i=1; 1<<j <= n-i+1; i++)
        {
            MIN[i][j]=min(MIN[i][j-1],MIN[i+(1<<(j-1))][j-1]);
            MAX[i][j]=max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]);
        }

    while(q--)
    {
        scanf("%d%d",&a,&b);
        lg=log2(b-a+1);
        mn=min(MIN[a][lg],MIN[b-(1<<lg)+1][lg]);
        mx=max(MAX[a][lg],MAX[b-(1<<lg)+1][lg]);
        printf("%d\n",mx-mn);
    }
}
