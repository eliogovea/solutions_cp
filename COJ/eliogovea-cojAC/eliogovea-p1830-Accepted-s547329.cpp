#include<cstdio>
#define MAXN 1000010
#define MOD 10000

int n,u,q,arr[MAXN],ac[MAXN];

int main()
{
	scanf("%d%d%d",&n,&u,&q);

	for(int i=1,x,k; i<=u; i++)
	{
		scanf("%d%d",&x,&k);
		arr[x-1]=(arr[x-1]+k)%MOD;
		arr[x]=(arr[x]+k+1)%MOD;
		arr[x+1]=(arr[x+1]+k)%MOD;
	}

	for(int i=1; i<=n; i++)
		ac[i]=(arr[i]+ac[i-1])%MOD;

	for(int i=1,a,b; i<=q; i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",(ac[b]-ac[a-1]+MOD)%MOD);
	}
}
