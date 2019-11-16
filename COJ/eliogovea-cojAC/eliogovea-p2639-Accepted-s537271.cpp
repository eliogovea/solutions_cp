#include<cstdio>
#include<vector>
#define MAXN 250010
using namespace std;

typedef vector<int>::iterator viit;

vector<int> G[MAXN];
int td[MAXN],low[MAXN],V,E,x,y,k,ans,c;
bool mark[MAXN];
void DFS(int);

int main()
{
    for(scanf("%d",&c);c--;)
    {
        scanf("%d%d",&V,&E);
        for(int i=1; i<=V; i++)
        {
            G[i].clear();
            low[i]=td[i]=mark[i]=k=ans=0;
        }
        for(int i=0; i<E; i++)
        {
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        DFS(1);
        printf("%d\n",ans);
    }
}

void DFS(int x)
{
    td[x]=low[x]=++k;

    for(viit i=G[x].begin(); i!=G[x].end(); i++)
    {
        if(!td[*i])
        {
            DFS(*i);

            low[x]=min(low[x],low[*i]);

            if(!mark[x])
                if((td[x]!=1 && td[x]<=low[*i])||(td[x]==1 && td[*i]>2))
                {
                    mark[x]=1;
                    ans++;
                }
        }
        else  low[x]=min(low[x],td[*i]);
    }
}
