#include<cstdio>
#include<vector>
#include<queue>
#define MAXN 1010
using namespace std;

struct next
{
	int nodo,costo;
	next(int a, int b){nodo=a; costo=b;}
	bool operator<(const next &x)const{return costo<x.costo;}
};

int n,m,x,y,c,sol,mk;
bool mark[MAXN];

vector<next> G[MAXN];
typedef vector<next>::iterator vi;

priority_queue<next> Q;

int main()
{
	scanf("%d%d",&n,&m);

	for(int i=1; i<=m; i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		G[x].push_back(next(y,c));
		G[y].push_back(next(x,c));
	}
	Q.push(next(1,0));

	while(!Q.empty())
	{
		int nod=Q.top().nodo,
			cost=Q.top().costo;
			
        Q.pop();

		if(!mark[nod])
		{
			mk+=mark[nod]=1;;
			sol+=cost;
			for(vi i=G[nod].begin(); i!=G[nod].end(); i++)
				if(!mark[i->nodo])
					Q.push(*i);
		}
	}

	printf("%d\n",(mk==n)?sol:-1);

	return 0;
}
