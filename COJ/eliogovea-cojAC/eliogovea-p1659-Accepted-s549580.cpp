#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define MAXN 500

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int v,e,c,m;
vpii G[MAXN+10];
vpii::iterator it;
vi sol;
vi::iterator iit;
int cow[MAXN+10];
int best[MAXN+10];
priority_queue< pii , vpii , greater< pii > > Q;

int main()
{
	scanf("%d%d%d%d",&v,&e,&c,&m);

	for(int i=1,x,y,z; i<=e; i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		G[x].push_back(make_pair(y,z));
		G[y].push_back(make_pair(x,z));
	}

	for(int i=1; i<=c; i++)
        scanf("%d",&cow[i]);

	for(int i=2; i<=MAXN; i++)
		best[i]=1<<29;

	Q.push(make_pair(0,1));

	while(!Q.empty())
	{
		int field=Q.top().second;
		int time=Q.top().first;

		Q.pop();

		if(best[field]!=time)continue;

		for(it=G[field].begin(); it!=G[field].end(); it++)
			if( best[it->first] > time + it->second  && time+it->second<=m)
			{
				best[it->first] = time + it->second;
				Q.push(make_pair(best[it->first],it->first));
			}
	}

	for(int i=1; i<=c; i++)
    {
        //printf("-->%d %d %d\n",i,cow[i],best[ cow[i] ]);
        if(best[ cow[i] ] <= m)
            sol.push_back(i);
    }


	sort(sol.begin(),sol.end());

	printf("%d\n",sol.size());

	for(iit=sol.begin(); iit!=sol.end(); iit++)
		printf("%d\n",*iit);
}
