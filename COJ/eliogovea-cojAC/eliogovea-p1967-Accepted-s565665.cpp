#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>

using namespace std;

const int MAXN = 1000000;

int k,n,a[MAXN + 10],dp[MAXN][12];

int comb( int x,int y )
{
    if( y > x - y ) y = x - y;
    if( y == 0 || y == x )return 1;
    if( dp[x][y] )return dp[x][y];
    return dp[x][y] = comb( x - 1, y - 1 ) + comb( x - 1, y );
}

int main()
{

    cin >> n >> k;
    int mx = 0;
    for( int l = k; l; l-- )
    {
        int len = l;
        for( int i = 0; n - comb( l - 1 + i, i ) > 0; i++ )
        {
            n -= comb( l - 1 + i, i );
            len++;
        }
        a[len] = 1;
        mx = max( mx, len );
    }
    for( int i = mx; i; i-- ) cout << a[i];
    cout << endl;
}


