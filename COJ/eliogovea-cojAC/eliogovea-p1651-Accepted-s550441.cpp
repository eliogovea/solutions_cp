#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAXN 100000
#define LOGMAXN 50

int n,q,a,b,lg,mn;
int MIN[MAXN][LOGMAXN];

int main()
{
	scanf("%d",&n);

	for(int i=1; i<=n; i++)
        scanf("%d",&MIN[i][0]);


    for(int j=1; 1<<j <= n; j++)
        for(int i=1; 1<<j <= n-i+1; i++)
            MIN[i][j]=min(MIN[i][j-1],MIN[i+(1<<(j-1))][j-1]);

    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        lg=(int)log2(b-a+1);
        mn=min(MIN[a][lg],MIN[b-(1<<lg)+1][lg]);
        printf("%d\n",mn);
    }
}
