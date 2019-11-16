#include<cstdio>
#define MAXN 1000010
using namespace std;

int q,a,b,ac[MAXN],cas;
char word[MAXN];

int main()
{

	while(scanf("%s",word+1)!=EOF)
	{
		for(char *p=word+1; *p; p++)
			ac[p-word]=ac[p-word-1]+(*p-'0');

		printf("Case %d:\n",++cas);

		for(scanf("%d",&q);q--;)
		{
			scanf("%d%d",&a,&b);
			if(a>b){int t=a;a=b;b=t;}

			if(ac[b+1]-ac[a]==b+1-a || ac[b+1]-ac[a]==0)
                printf("Yes\n");
			else printf("No\n");
		}
	}
}
