#include<cstdio>
#define MAX 10

char q[2],aux[2];
short X[MAX],Y[MAX],Z[MAX];
int a,b,c;

int main()
{
	while(scanf("%s",q) && q[0]!='Q')
	{
		if(q[0]=='P')
		{
			scanf("%d%d%d",&a,&b,&c);
			if(X[a]&&Y[b]&&Z[c])printf("YES\n");
			else printf("NO\n");
		}
		else if(q[0]=='X')
		{
			scanf("%s%d",aux,&a);
			X[a]^=1;
		}
		else if(q[0]=='Y')
		{
			scanf("%s%d",aux,&a);
			Y[a]^=1;
		}
		else
		{
			scanf("%s%d",aux,&a);
			Z[a]^=1;
		}
	}
}
