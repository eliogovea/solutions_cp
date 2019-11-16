#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define MAXN 1010
using namespace std;

int n,e,s,t,a,b,c,d;
bool mark[MAXN];
pair<int,int> dist[MAXN];
vector<pair<int,pair<int,int> > > G[MAXN];
vector<pair<int,pair<int,int> > >::iterator it;

priority_queue<
    pair<pair<int,int>,int>,
    vector< pair< pair< int,int >,int > >,
    greater< pair< pair<int,int>,int > >
    > Q;

int main()
{
	scanf("%d%d%d%d",&n,&e,&s,&t);
	s++;    t++;

	for(int i=1; i<=e; i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a++;    b++;
		G[a].push_back(make_pair(b,make_pair(c,d)));
		G[b].push_back(make_pair(a,make_pair(c,d)));
	}

	for(int i=1; i<=n; i++)
		dist[i]=make_pair(1<<29,1<<29);

	dist[s]=make_pair(0,0);

	Q.push(make_pair(make_pair(0,0),s));

	while(!Q.empty())
	{
		int nodo=Q.top().second;

		Q.pop();

		if(mark[nodo])continue;

		mark[nodo]=1;

		for(it=G[nodo].begin(); it!=G[nodo].end(); it++)
		{
			int sinsol=dist[nodo].first+(it->second).first-(it->second).second;
			int distancia=dist[nodo].second+(it->second).first;
			if(dist[it->first] > make_pair(sinsol,distancia))
			{
				dist[it->first] = make_pair(sinsol,distancia);
				Q.push(make_pair(dist[it->first],it->first));
			}
		}
	}

	printf("%d %d\n",dist[t].second,dist[t].first);
}
