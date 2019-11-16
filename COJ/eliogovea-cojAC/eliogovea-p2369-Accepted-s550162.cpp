#include<cstdio>
#include<algorithm>
using namespace std;

int n;
long long a,b,c,mn,mx;

int main()
{
	for(scanf("%d",&n); n--;)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		mn=mx=a*b+c;
		mn=min(mn,a+b*c);	mx=max(mx,a+b*c);
		mn=min(mn,a*c+b);	mx=max(mx,a*c+b);
		mn=min(mn,(a+b)*c);	mx=max(mx,(a+b)*c);
		mn=min(mn,(a+c)*b);	mx=max(mx,(a+c)*b);
		mn=min(mn,(b+c)*a);	mx=max(mx,(b+c)*a);

		printf("%lld %lld\n",mn,mx);
	}
}
