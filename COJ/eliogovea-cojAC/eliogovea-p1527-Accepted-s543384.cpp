    #include<cstdio>
    #include<queue>
    #include<vector>
    #include<algorithm>
    #define MAXN 110
    using namespace std;

    typedef vector<int>::iterator vit;

    vector<int> G[MAXN];
    int dist[MAXN],n,m,maxdist;
    queue<int> Q;

    vector<int> D[MAXN];

    int main()
    {
        scanf("%d%d",&n,&m);

        for(int i=1,x; i<=n; i++)
        {
            dist[i]=1<<29;
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&x);
                if(x)G[i].push_back(j);
            }
        }

        Q.push(m);
        dist[m]=0;
        while(!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            for(vit it=G[x].begin(); it!=G[x].end(); it++)
                if(dist[*it]>dist[x]+1)
                    dist[*it]=dist[x]+1,
                    maxdist=max(maxdist,dist[*it]),
                    Q.push(*it);
        }

        for(int i=1; i<=n; i++)
            if(dist[i]<=maxdist)
                D[dist[i]].push_back(i);

        printf("%d\n",m);

        for(int i=1; i<=maxdist; i++)
        {
            for(int j=0; j<D[i].size()-1; j++)
                printf("%d ",D[i][j]);
            printf("%d\n",D[i][D[i].size()-1]);
        }
    }
