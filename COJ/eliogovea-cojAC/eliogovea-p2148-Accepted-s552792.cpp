#include<cstdio>

int n,a,b,c;

int main()
{
	for( scanf( "%d", &n ); n--; )
	{
		scanf( "%d%d%d", &a, &b, &c );
		printf( "%s\n", (b*b-4*a*c < 0)?"NO":"SI" );
	}
}