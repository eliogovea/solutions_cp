#include<cstdio>

int cases;
double x,y;

int main()
{
	scanf("%d",&cases);
	for(int i=1; i<=cases; i++)
	{
		scanf("%lf%lf",&x,&y);
		printf("Property %d: This property will begin eroding in year %d.\n",i,int(3.14*(x*x+y*y)/100.0)+1);
	}
	printf("END OF OUTPUT.");
}
