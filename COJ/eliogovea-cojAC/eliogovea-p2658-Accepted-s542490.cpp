#include<cstdio>

int cas,a,b,c,cant,dif,first,sum;

int main()
{
	for(scanf("%d",&cas);cas--;)
	{
		scanf("%d%d%d",&a,&b,&c);

		cant=2*c/(a+b);
		dif=(b-a)/(cant-5);

		printf("%d\n",cant);
		for(first=a-2*dif,sum=0; sum<=c; first+=dif,sum+=first)
		{
            printf("%d",first);
            if(sum<c)printf(" ");
            else printf("\n");
		}
	}
}


