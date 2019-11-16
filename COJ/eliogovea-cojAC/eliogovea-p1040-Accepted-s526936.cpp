#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 1000000
using namespace std;

typedef vector<int>::iterator vit;

 vector<int> G[MAX];
 int grado[MAX],n,m,rec[MAX],ans,a,b;
 bool mark[MAX];

 void DFS(int x)
 {
     mark[x]=1;
     rec[ans++]=x;
     for(vit it=G[x].begin(); it!=G[x].end(); it++)
         if(!(--grado[*it]))
            DFS(*it);
 }

int main()
{
    while(scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)break;

        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            grado[b]++;
        }

        for(int i=1; i<=n; i++)
            if(!grado[i]&&!mark[i])
                DFS(i);


        if(ans==n)
        for(int i=0; i<ans; i++)
            printf("%d\n",rec[i]);
        else printf("IMPOSSIBLE\n");

        for(int i=1; i<=n; i++)
        {
            G[i].clear();
            mark[i]=0;
            grado[i]=0;
        }
        ans=0;
    }


}
