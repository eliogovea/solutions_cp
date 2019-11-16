#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#define MAXN 10
using namespace std;

int v,p,c,s,t;
int id,x,y;
double d;
multimap<int,pair<double,pair<int,int> > > m;
multimap<int,pair<double,pair<int,int> > >::iterator it;
double G[MAXN+5][MAXN+5];

int main()
{
	scanf("%d%d%d%d%d",&v,&p,&c,&s,&t);

	for(int i=1; i<=p; i++)
	{
		scanf("%d%d%d%lf",&id,&x,&y,&d);
		m.insert(make_pair(id,make_pair(d,make_pair(x,y))));
	}

	for(int i=1; i<=c; i++)
	{
		scanf("%d",&id);
		m.erase(m.find(id));
	}

	for(it=m.begin(); it!=m.end(); it++)
	{
		double dist=(it->second).first;
		int xx=(it->second).second.first;
		int yy=(it->second).second.second;

		if(G[xx][yy]>0.0)G[yy][xx]=G[xx][yy]=min(G[xx][yy],dist);
		else G[yy][xx]=G[xx][yy]=dist;
	}

	for(int k=1; k<=v; k++)
		for(int i=1; i<=v; i++)
			for(int j=1; j<=v; j++)
				if(G[i][k]>0.0 && G[k][j]>0.0)
                {
                    if(G[i][j]>0.0)
                        G[i][j]=G[j][i]=min(G[i][j],G[i][k]+G[k][j]);
                    else G[i][j]=G[i][k]+G[k][j];
                }

	printf("%.2lf\n",G[s][t]);
}
