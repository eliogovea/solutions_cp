#include<cstdio>
#include<vector>
#include<queue>
#define MAXN 20010
using namespace std;

struct next
{
	int nodo,costo,padre;
	next(int a, int b, int c){nodo=a;costo=b;padre=c;}
	bool operator<(const next &x)const{return costo<x.costo;}
};

int n,m,s,x,y,c;
int padre[MAXN],cost_p[MAXN],level[MAXN];
bool mark[MAXN];
vector<pair<int,int> > G[MAXN],MST[MAXN];
vector<pair<int,int> >::iterator it;
priority_queue<next> Q;


int main()
{
	while(scanf("%d%d%d",&n,&m,&s)==3)
	{
		for(int i=1; i<=m; i++)
		{
			scanf("%d%d%d",&x,&y,&c);
			G[x].push_back(make_pair(y,c));
			G[y].push_back(make_pair(x,c));
		}

		mark[0]=1;
		level[1]=1;
		Q.push(next(1,0,0));
		while(!Q.empty())
		{
			int nod=Q.top().nodo,
				cost=Q.top().costo,
				pad=Q.top().padre;

			Q.pop();

			if(!mark[nod])
			{
				mark[nod]=1;
					MST[nod].push_back(make_pair(pad,cost));
					MST[pad].push_back(make_pair(nod,cost));
					level[nod]=level[pad]+1;
					cost_p[nod]=cost;
					padre[nod]=pad;


				for(it=G[nod].begin(); it!=G[nod].end(); it++)
					if(!mark[it->first])
						Q.push(next(it->first,it->second,nod));
			}
		}

        while(s--)
        {
            scanf("%d%d",&x,&y);
            int mx=1<<29;
            while(x!=y)
            {
                if(level[x]<level[y])
                {
                    mx=min(mx,cost_p[y]);
                    y=padre[y];
                }
                else if(level[x]>level[y])
                {
                    mx=min(mx,cost_p[x]);
                    x=padre[x];
                }
                else
                {
                    mx=min(mx,min(cost_p[x],cost_p[y]));
                    x=padre[x];
                    y=padre[y];
                }
            }
            printf("%d\n",mx);
        }

        for(int i=0; i<=n; i++)
        {
            G[i].clear();
            MST[i].clear();
            padre[i]=0;
            cost_p[i]=0;
            level[i]=0;
            mark[i]=0;
        }
	}
}
