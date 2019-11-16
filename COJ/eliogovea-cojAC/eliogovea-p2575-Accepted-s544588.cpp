#include<cstdio>
#include<vector>
#define MAXN 510
using namespace std;

vector<int> G[MAXN];
typedef vector<int>::iterator viit;

int V,E,x,y,tree,cant,padre[MAXN],cas;
bool mark[MAXN];

void DFS(int v)
{
    mark[v]=1;
    for(viit it=G[v].begin(); it!=G[v].end(); it++)
    {
        if(mark[*it] && padre[v]==*it)continue;

        if(mark[*it])tree=0;

        else
        {
            padre[*it]=v;
            DFS(*it);
        }
    }
}


int main()
{
    while(scanf("%d%d",&V,&E) && (V||E))
    {
        for(int i=1; i<=E; i++)
        {
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for(int i=1; i<=V; i++)
        {
            if(!mark[i])
            {
                tree=1;
                DFS(i);
                cant+=tree;
            }
        }
        printf("Case %d: ",++cas);
        if(cant==0)printf("No trees.\n");
        else if(cant==1)printf("There is one tree.\n");
        else printf("A forest of %d trees.\n",cant);

        for(int i=1; i<=V; i++)
        {
            G[i].clear();
            mark[i]=0;
            padre[i]=0;
        }
        cant=0;
    }
}
