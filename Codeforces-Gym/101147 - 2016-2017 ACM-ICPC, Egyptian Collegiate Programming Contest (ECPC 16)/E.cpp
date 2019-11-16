// 2016-2017 ACM-ICPC, Egyptian Collegiate Programming Contest (ECPC 16)
// 101147E

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 101000;
int n;
int d[MAXN];
int lev[MAXN];
vector<int> g[MAXN];

void bfs( int x ){
    fill( lev, lev+n+1, -1 );
    lev[x] = 0;
    queue<int> q;
    q.push( x );

    while( !q.empty() ){
        int u  = q.front(); q.pop();

        for( int i = 0; i < g[u].size(); i++ ){
            int v = g[u][i];
            if( lev[v] == -1 ){
                lev[v] = lev[u] +1;
                q.push( v );
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
  //  freopen( "dat.txt", "r", stdin );
    freopen( "jumping.in", "r", stdin );
    int tc;
    cin >> tc;
    while( tc-- ){

        cin >> n;
        for( int i = 0; i <= n; i++ )
            g[i].clear();
        for( int i = 1; i <= n; i++ ){
            cin >> d[i];
            int v = i+d[i];
            if( v <= n )
                g[ v ].push_back( i );
            v = i - d[i];
            if( v > 0 )
                g[v].push_back( i );
        }
        bfs( n );
        for( int i = 1; i <= n; i++ ){
            cout << lev[i] << '\n';
        }
    }

}
