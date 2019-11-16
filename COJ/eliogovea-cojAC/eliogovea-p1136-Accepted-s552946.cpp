#include<cstdio>
#include<vector>
#define MAXN 31630
using namespace std;

int cas,a,b;
bool criba[MAXN+10];
vector< int > primos;
vector< int >::iterator it;

void Criba()
{
	for( int i = 2; i <= MAXN; i++ )criba[i] = 1;

	for( int i = 2; i <= MAXN; i++ )
		if( criba[i] )
			for( int j = i * i; j <= MAXN; j += i )
				criba[j] = 0;

	for( int i = 2; i <= MAXN; i++ )
		if( criba[i] )
			primos.push_back( i );
}

bool primo( int n )
{
	if( n <= MAXN )
		return criba[n];

	for( it = primos.begin(); it != primos.end() && (*it)*(*it) <= n; it++ )
		if( n % (*it) == 0 )return 0;

	return 1;
}


int main()
{
    Criba();

	for( scanf( "%d", &cas ); cas--; )
	{
		scanf( "%d%d", &a, &b );

		for( int i = a; i <= b; i++ )
			if( primo(i) )printf( "%d\n", i );
        printf("\n");
	}
}
