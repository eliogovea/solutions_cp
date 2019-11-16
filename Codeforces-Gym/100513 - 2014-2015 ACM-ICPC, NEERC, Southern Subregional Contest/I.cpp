// 2014-2015 ACM-ICPC, NEERC, Southern Subregional Contest
// 100513I

#include <bits/stdc++.h>

using namespace std;
int dp[1000000];
int l[5000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   // freopen( "dat.txt", "r", stdin );
    int n;
    cin >> n;
    int p = 0;
    for( int i = 0; i < n; i++ ){
        cin >> l[i];
        if( l[p] < l[i] )
            p = i;
    }
    dp[0] = 1;
    for( int i = 0; i < n; i++ ){
        if( i == p )
            continue;
        int c = l[i];
        for( int j = l[p] - c; j >= 0; j-- ){
            if( dp[j]+1 > dp[j + c ] ){
                dp[j+c] = dp[j]+1;
            }
        }
    }
    int sol = 0;
    for( int i = 0; i <= l[p]; i++ )
        sol = max( sol, dp[i] );
    cout << sol << '\n';

}
