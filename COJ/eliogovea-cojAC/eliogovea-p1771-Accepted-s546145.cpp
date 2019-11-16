#include<cstdio>
#include<vector>
#include<queue>
#define MAXN 1010
using namespace std;

int n,m;
int cost[MAXN],mincost[MAXN];
vector<int> G[MAXN];
vector<int>::iterator it;
queue<int> Q;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&cost[i]);
		mincost[i]=1<<29;
	}

	for(int i=1,x,y; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}

	Q.push(1);
	mincost[1]=0;

	while(!Q.empty())
	{
		int nod=Q.front();
		Q.pop();

		for(it=G[nod].begin(); it!=G[nod].end(); it++)
			if(mincost[*it] > mincost[nod]+cost[*it])
			{
				mincost[*it] = mincost[nod]+cost[*it];
				Q.push(*it);
			}
	}

	printf("%d\n",mincost[n]-cost[n]);

}
