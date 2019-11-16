#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> G[15];
typedef vector<int>::iterator viit;
int n,k,p,x,ans;

int main()
{
	G[0].push_back(0);

	while(scanf("%d%d%d",&n,&k,&p)==3)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            for(int j=min(i,k); j; j--)
                for(viit it=G[j-1].begin(); it!=G[j-1].end(); it++)
                    G[j].push_back(*it+x);
        }

        for(viit it=G[k].begin(); it!=G[k].end(); it++)
            if(__gcd(p,*it)!=1)ans++;

        printf("%d\n",ans);

        ans=0;
        for(int i=1; i<=k; i++)
            G[i].clear();
    }
}
