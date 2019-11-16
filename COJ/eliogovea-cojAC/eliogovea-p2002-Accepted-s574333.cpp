#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int n,x,sol;
set<int> s;

int main()
{
	scanf( "%d", &n );
	vector<int> v(n);
	for( int i = 0; i < n; i++ )
	{
		scanf( "%d", &v[i] );
		s.insert( v[i] );
	}

	s.insert( -1 );

	for( set<int>::iterator it = s.begin(); it != s.end(); it++ )
	{
		int i = 0, j = 0, cant = 0;
		while( true )
		{
            if( j == n ) break;
            if( v[i] == *it ) { i++; j++; }
            else if( v[j] == v[i] ) { j++; cant++; }
            else if( v[j] == *it ) j++;
            else
            {
                sol = max( sol, cant );
                cant = 0;
                i = j;
            }
		}
		sol = max( sol, cant );
	}

	printf( "%d\n", sol );
}
