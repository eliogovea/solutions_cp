#include<cstdio>
#include<algorithm>
#include<limits.h>
using namespace std;
int mx,mn,x,ans,la,lb;
bool a[20001],b[20001];

int main()
{
    while(scanf("%d",&la) && la)
    {
        mx=INT_MIN;mn=INT_MAX;
        for(int i=0; i<la; i++)
        {
            scanf("%d",&x);
            a[x+10000]=1;
            if(x+10000>mx)mx=x+10000;
            if(x+10000<mn)mn=x+10000;
        }
        scanf("%d",&lb);
        for(int i=0; i<lb; i++)
        {
            scanf("%d",&x);
            b[x+10000]=1;
            if(x+10000>mx)mx=x+10000;
            if(x+10000<mn)mn=x+10000;
        }
        int i=mn;
        while(i<=mx)
        {
            int s1=0,s2=0;
            while((!a[i] || !b[i]) && i<=mx)
            {
                if(a[i])s1+=i-10000;
                if(b[i])s2+=i-10000;
                i++;
            }
            ans+=max(s1,s2);
            if(i<=mx)
            {
                ans+=i-10000;
                i++;
            }
        }
        printf("%d\n",ans);
        ans=0;
        for(int i=mn; i<=mx; i++)a[i]=b[i]=0;
    }
    return 0;
}
