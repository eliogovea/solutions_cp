/**
 * Koder: Sheldon Cooper
 * Task : 2842 - Lazy Cat
 **/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXN 10000010
#define PRINT( x ) printf( "%d ", x );
//#define DEBUG
using namespace std;

int Q;
short no_prime[MAXN];
char aux[10];
vector<int> v;

short is_palind( int x ){
    int len = (int)log10(x)+1;
    if( len == 1 ) return true;
    sprintf( aux+1, "%d", x );
    for( int i = 1, j = len; i <= j; i++, j-- )
        if( aux[i] != aux[j] )
            return false;
    return true;
    }
int main(){


    for( int i = 2; i <= MAXN; i++ ){
        if( no_prime[i] ) continue;
        for( int j = 2*i; j <= MAXN; j += i )
            no_prime[j] = true;
        if( is_palind( i ) )
            v.push_back( i );
        }
#ifdef DEBUG
    for( int i = 0; i < v.size(); i++ ){
        printf( "%d ", v[i] );
        }
#endif
    scanf( "%d", &Q );
    int l, r;
    while( Q-- ){
        scanf( "%d%d", &l, &r );
        int ans = upper_bound( v.begin(), v.end(), r ) - lower_bound( v.begin(), v.end(), l );
        printf( "%d\n", ans );
        }


    }