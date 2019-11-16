#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXN 1000010
using namespace std;

int c1,c2,aux,sol;
int v1[MAXN],v2[MAXN];

int main()
{
	while(scanf("%d%d",&c1,&c2) && (c1|c2))
	{
		if(c1>=c2)
		{
			for(int i=1; i<=c1; i++)
				scanf("%d",&v1[i]);
			for(int i=1; i<=c2; i++)
			{
				scanf("%d",&aux);
				sol+=binary_search(v1+1,v1+c1+1,aux);
			}
		}
		else
		{
			for(int i=1; i<=c1; i++)
				scanf("%d",&v1[i]);
			for(int i=1; i<=c2; i++)
				scanf("%d",&v2[i]);
			for(int i=1; i<=c1; i++)
				sol+=binary_search(v2+1,v2+c2+1,v1[i]);
		}

		printf("%d\n",sol);
		sol=0;
	}
}
