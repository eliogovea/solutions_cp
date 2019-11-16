#include<cstdio>
#include<vector>
#include<queue>
#define MAXN 50
using namespace std;

int t,n,m,q,x,y;
int lev[MAXN+10];
vector<int> G[MAXN+10];
vector<int>::iterator it;
queue<int> Q;

int main()
{
	for(scanf("%d",&t); t--;)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1; i<=m; i++)
		{
			scanf("%d%d",&x,&y);
			G[x].push_back(y);
		}
		lev[1]=1;
		Q.push(1);
		while(!Q.empty())
		{
			int act=Q.front();
			Q.pop();

			for(it=G[act].begin(); it!=G[act].end(); it++)
				if(!lev[*it])
				{
					lev[*it]=lev[act]+1;
					Q.push(*it);
				}
		}
		for(int i=1; i<=q; i++)
		{
			scanf("%d",&x);
			if(lev[x])printf("%d\n",lev[x]);
			else printf("-1\n");
		}

		for(int i=1; i<=n; i++)
		{
			G[i].clear();
			lev[i]=0;
		}
	}
}
