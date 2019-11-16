#include<cstdio>
#define mod 1000000007

long long n,base,sol;

int main()
{
	while(scanf("%lld",&n)==1)
	{
		sol=1ll;
		base=3ll;
		while(n)
		{
			if(n&1)sol=(sol*base)%mod;
			base=(base*base)%mod;
			n>>=1;
		}
		printf("%lld\n",sol);
	}
}
