#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000 + 10;
int k, n;
int min1[maxn], min2[maxn];

int mat[maxn][maxn];

priority_queue<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen( "dat.txt", "r", stdin );


    cin >> k >> n;
    for( int i = 1; i <= k; i++ )
        for( int j = 1; j <= n; j++ )
            cin >> mat[i][j];

    int best = 0;

    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= k; j++ ){
            q.push( mat[j][i] );
            if( q.size() > 2 )
                q.pop();
        }
        if( q.size() == 2 ){
            min2[i] = q.top(); q.pop();
            min1[i] = q.top(); q.pop();
        }
        else{
            min1[i] = q.top(); q.pop();
            min2[i] = INT_MAX;
        }
        best += min1[i];
    }
    int ans = 0;

    for( int i = 1; i <= n; i++ ){
        ans = max( ans, best - min1[i] + min( 2*min1[i], min2[i] ) );
    }
    cout << ans << '\n';

}
