#include<cstdio>
#include<map>
using namespace std;

map<int,int>m;
int c,n,ac,x,ans;

int main()
{
    for(scanf("%d",&c);c--;)
    {
        m.clear();
        ac=ans=0;
        for(scanf("%d",&n);n--;)
        {
            m[ac]++;
            scanf("%d",&x);
            ac+=x;
            if(m[ac-47])ans+=m[ac-47];
        }
        printf("%d\n",ans);
    }
    return 0;
}
