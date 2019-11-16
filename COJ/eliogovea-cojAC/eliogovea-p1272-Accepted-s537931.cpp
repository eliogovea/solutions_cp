#include<cstdio>
#include<queue>
#include<vector>
#define MAXN 20010
using namespace std;

typedef vector<int>::iterator viit;

int cases,V,E,x,y,dist[MAXN],nod,far,cant,maxdist;

vector<int> G[MAXN];
queue<int> Q;

int main()
{
    for(scanf("%d",&cases); cases--;)
    {
        scanf("%d%d",&V,&E);

        for(int i=1; i<=V; i++)
            G[i].clear(),
            dist[i]=1<<29;

        for(int i=1; i<=E; i++)
        {
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for(Q.push(1),dist[1]=0;!Q.empty(); Q.pop())
        {
            nod = Q.front();

            for(viit i=G[nod].begin(); i!=G[nod].end(); i++)
                if(dist[*i]>dist[nod]+1)
                    dist[*i]=dist[nod]+1,
                    Q.push(*i);
        }

        maxdist=dist[nod];

        for(int i=V; i; i--)
            if(dist[i]==maxdist)
                far=i,cant++;

        printf("%d %d %d\n",far,maxdist,cant);

        cant=0;
    }
}
