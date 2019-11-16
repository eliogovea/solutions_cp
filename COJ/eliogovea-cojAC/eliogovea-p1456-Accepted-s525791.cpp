#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

set<long long> S;
int n;
long long x;

int main()
{

    for(scanf("%d",&n);n--;)
    {
        scanf("%lld",&x);
        if(S.find(x)!=S.end())S.erase(x);
        else S.insert(x);
    }
    printf("%lld\n",*(S.begin()));
    return 0;
}
