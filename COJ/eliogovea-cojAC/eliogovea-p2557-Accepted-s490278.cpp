#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;

int n,i,j,ans;
long long Q[100000],N[100000];

int main()
{
    scanf("%d",&n);
    for(int k=0; k<n; k++)scanf("%d",&Q[k]);
    for(int k=0; k<n; k++)scanf("%d",&N[k]);

    sort(Q,Q+n,greater<int>());
    sort(N,N+n,greater<int>());


    while(i<n && j<n)
    {
        while(N[i]<=Q[j] && j<n)j++;
        if(j<n)ans++;
        i++;j++;
    }
    printf("%d\n",ans);
    return 0;
}
