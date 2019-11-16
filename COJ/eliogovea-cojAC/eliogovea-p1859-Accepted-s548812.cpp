#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#define MAXN 50010
#define MAXK 1010
#define INF 1<<29
using namespace std;

typedef pair<pair<int,int>,int> ppii;

int N,K;
int padre[MAXK];
bool mark[MAXK];
pair<int,int> dist[MAXK];
vector<int> G[MAXK];
vector<int>::iterator it;
priority_queue<ppii,vector<ppii>,greater<ppii> > Q;
stack<int> ans;

int main()
{
	scanf("%d%d",&N,&K);

	for(int i=1,x,y; i<=N; i++)
	{
		scanf("%d%d",&x,&y);
		G[x].push_back(y);

	}

	for(int i=2; i<=K; i++)
		dist[i]=make_pair(INF,INF);

	Q.push(make_pair(make_pair(0,0),1));

	while(!Q.empty())
	{
		int nodo=Q.top().second;
		int distn=Q.top().first.first;
		int sum=Q.top().first.second;

		Q.pop();

		if(mark[nodo])continue;
		mark[nodo]=1;

		for(it=G[nodo].begin(); it!=G[nodo].end(); it++)
			if(dist[*it] > make_pair(distn+1,sum+*it))
			{
				padre[*it]=nodo;
				dist[*it] = make_pair(distn+1,sum+*it);
				Q.push(make_pair(dist[*it],*it));
			}

	}

    if(dist[K].first==1<<29)
        printf("-1\n");
    else
    {
        while(K)
        {
            ans.push(K);
            K=padre[K];
        }

        printf("%d\n",ans.size());

        while(ans.size())
        {
            printf("%d\n",ans.top());
            ans.pop();
        }
    }

    return 0;
}
