#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define MAXN 110
#define MAXL 55
using namespace std;

struct next
{
	int nodo,costo;
	next(int a, int b){nodo=a;costo=b;}
	bool operator<(const next &x)const{return costo>x.costo;}
};

int n,g[MAXN][MAXN],len[MAXN],lcs[MAXL][MAXL],ans,mx;
bool mark[MAXN];
char city[MAXN][MAXL];

priority_queue<next> q;

int main()
{
	scanf("%d",&n);

	for(int i=1; i<=n; i++)
	{
		scanf("%s",city[i]+1);
		len[i]=strlen(city[i]+1);

		for(int j=1; j<i; j++)
		{
			for(int ii=1; ii<=len[i]; ii++)
				for(int jj=1; jj<=len[j]; jj++)
				{
					if(city[i][ii]==city[j][jj])
						lcs[ii][jj]=lcs[ii-1][jj-1]+1;
					else lcs[ii][jj]=max(lcs[ii-1][jj],lcs[ii][jj-1]);
				}
			g[i][j]=g[j][i]=lcs[len[i]][len[j]];
		}
	}

	/*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            printf("%d ",g[i][j]);
        printf("\n");
    }*/

    ///Prim
	q.push(next(1,0));
	while(!q.empty())
	{
		int nod=q.top().nodo,
			cost=q.top().costo;
		q.pop();

		if(!mark[nod])
		{
			mark[nod]=1;
			//ans+=cost;
			mx=max(mx,cost);

			for(int i=1; i<=n; i++)
				if(!mark[i])
					q.push(next(i,g[nod][i]));
		}
	}
	printf("%d\n",mx+1);
}
