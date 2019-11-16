#include<cstdio>
#include<vector>
#include<queue>
#define MAXN 5010
using namespace std;

int V,E,C,N,S;
vector<pair<int,int> > G[MAXN];
vector<pair<int,int> >::iterator it;
bool mark[MAXN];
priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > Q;
int dist[MAXN][3];

void Dist(int source, int p)
{
    dist[source][p]=0;
    Q.push(make_pair(0,source));
    for(int i=1; i<=V; i++)
        mark[i]=0;

    while(!Q.empty())
    {
        int nodo=Q.top().second;
        int costo=Q.top().first;
        Q.pop();

        if(mark[nodo])continue;

        mark[nodo]=1;
        for(it=G[nodo].begin(); it!=G[nodo].end(); it++)
            if(dist[it->first][p] > costo + it->second)
            {
                dist[it->first][p] = costo + it->second;
                Q.push(make_pair(dist[it->first][p],it->first));
            }
    }
}

int main()
{
	while(scanf("%d%d%d%d%d",&V,&S,&C,&N,&E))
	{
		if(V==-1)break;

		for(int i=1; i<=V; i++)
		{
		    dist[i][0]=dist[i][1]=dist[i][2]=1<<29;
            G[i].clear();
		}

		for(int i=1,x,y,c; i<=E; i++)
		{
			scanf("%d%d%d",&x,&y,&c);
			G[x].push_back(make_pair(y,c));
			G[y].push_back(make_pair(x,c));
		}

		Dist(S,0);
		Dist(C,1);
		Dist(N,2);

		int mx=0,ch,n,s;

		for(int i=1; i<=V; i++)
            if(dist[i][0]+dist[i][1]==dist[C][0] &&
            dist[i][0]+dist[i][2]==dist[N][0] && mx<=dist[i][0])
            {
                s=mx=dist[i][0];
                n=dist[N][0]-dist[i][0];
                ch=dist[C][0]-dist[i][0];
            }

		printf("%d %d %d\n",s,ch,n);

	}
}
