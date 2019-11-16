/**
   COJ - 1027 - Travel in Desert
   eliogovea
*/
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#define MAXN 1000
#define INF 1e9
using namespace std;

typedef pair<double,int> pdi;

int V,E,st,en;
int padre[MAXN],a,b;
double T[MAXN],D[MAXN],c,d;
vector<pair<int,pair<double,double> > > G[MAXN];
vector<pair<int,pair<double,double> > >::iterator it;
priority_queue<pdi,vector<pdi>,greater<pdi> >Q;
bool M1[MAXN],M2[MAXN];
stack<int> sol;

int main()
{
	while( scanf("%d%d",&V,&E) == 2 )
	{
		scanf("%d%d",&st,&en);

		for(int i=1; i<=E; i++)
		{
			scanf("%d%d%lf%lf",&a,&b,&c,&d);
			G[a].push_back(make_pair(b,make_pair(c,d)));
			G[b].push_back(make_pair(a,make_pair(c,d)));
		}

		for(int i=1; i<=V; i++)
			T[i]=INF;

		T[st]=0;
		Q.push(make_pair(0.0,st));
		while(!Q.empty())
		{
			int act = Q.top().second;
			double tem = Q.top().first;
			Q.pop();

			if(M1[act])continue;
			M1[act]=1;

			for(it=G[act].begin(); it!=G[act].end(); it++)
				if( T[it->first] > max(tem,(it->second).first) )
				{
					T[it->first] = max(tem,(it->second).first);
					Q.push(make_pair(T[it->first],it->first));
				}
		}

		double Temp = T[en];

		for(int i=1; i<=V; i++)
			D[i]=INF;
        D[st]=0;
		Q.push(make_pair(0.0,st));

		while(!Q.empty())
        {
            int act = Q.top().second;
            double dis = Q.top().first;
            Q.pop();

            if(M2[act])continue;
            M2[act]=1;

            for(it=G[act].begin(); it!=G[act].end(); it++)
                if((it->second).first <= Temp)
                    if(D[it->first] > dis + (it->second).second)
                    {
                        D[it->first] = dis + (it->second).second;
                        padre[it->first] = act;
                        Q.push(make_pair(D[it->first],it->first));
                    }
        }

		int aux = en;
		while(aux)
		{
			sol.push(aux);
			aux=padre[aux];
		}

		while(sol.size())
		{
			printf("%d",sol.top());
			sol.pop();
			if(sol.size())printf(" ");
		}

		printf("\n%.1lf %.1lf\n",D[en],T[en]);

		for(int i=1; i<=V; i++)
        {
            G[i].clear();
            M1[i]=M2[i]=padre[i]=0;
            D[i]=T[i]=0.0;
        }
	}
}
