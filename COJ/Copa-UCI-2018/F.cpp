#include <bits/stdc++.h>

using namespace std;

const int oo = (1<<29);
const int MAXN = 15;

bool ady[MAXN][MAXN];
int z[MAXN][MAXN];

int d[(1<<MAXN)][MAXN][MAXN];
bool mk[(1<<MAXN)][MAXN][MAXN];

typedef pair<int,int> par;
int n;
void dijkstra( int mask, int ini ){
    for( int u = 0; u < n; u++ ){
        d[mask][ini][u] = oo;
    }
    d[mask][ini][ini] = 0;
    priority_queue<par> q;
    q.push( par( 0 , ini ) );

    while( !q.empty() ){
        int u = q.top().second; q.pop();

        if( mk[mask][ini][u] ) continue;

        mk[mask][ini][u] = true;

        for( int v = 0; v < n; v++ ){
            if( ((1<<v) & mask) && ady[u][v] && d[mask][ini][v] > d[mask][ini][u] + z[u][v] ){
                d[mask][ini][v] = d[mask][ini][u] + z[u][v];
                q.push( par( -d[mask][ini][v] , v ) );
            }
        }
    }
}

int dp[1<<MAXN][MAXN];

void solve( int ini ){
    for( int j = 0; j < (1<<n); j++ ){
        for( int i = 0; i < n; i++ ){
            dp[j][i] = oo;
        }
    }

    dp[(1<<ini)][ini] = 0;
    for( int mask = 1; mask < (1<<n); mask++ ){
        for( int u = 0; u < n; u++ ){
            if( (1<<u) & mask ){
                for( int v = 0; v < n; v++ ){
                    if( (1<<v) & mask ){
                        dp[mask][v] = min( dp[mask][v] , dp[mask][u] + d[mask][u][v] );
                    }
                }
            }
        }

        for( int u = 0; u < n; u++ ){
            if( ((1<<u) & mask) && dp[mask][u] != oo ){
                for( int v = 0; v < n; v++ ){
                    if( !((1<<v) & mask) && ady[u][v] ){
                        dp[mask | (1<<v)][v] = min( dp[mask | (1<<v)][v] , dp[mask][u] + z[u][v] );
                    }
                }
            }
        }
    }
}

int a[MAXN];
int cost[1<<MAXN];

int solB[300], solS[300];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int m, b, s, k; cin >> n >> m >> b >> s >> k; b--; s--;

    for( int i = 0; i < n; i++ ) cin >> a[i];

    for( int mask = 1; mask < (1<<n); mask++ ){
        for( int u = 0; u < n; u++ ){
            if( (1<<u) & mask ){
                cost[mask] += a[u];
            }
        }
    }

    while( m-- ){
        int u, v; cin >> u >> v; u--; v--;
        int w; cin >> w;
        if( !ady[u][v] ){
            z[u][v] = z[v][u] = w;
        }
        else{
            z[u][v] = z[v][u] = min( z[u][v] , w );
        }

        ady[u][v] = ady[v][u] = true;
    }

    for( int mask = 1; mask < (1 << n); mask++ ){
        for( int u = 0; u < n; u++ ){
            if( (1<<u) & mask ){
                dijkstra( mask , u );
            }
        }
    }

    solve( s );
    for( int mask = 1; mask < (1<<n); mask++ ){
        for( int u = 0; u < n; u++ ){
            if( (1<<u) & mask ){
                if( dp[mask][u] <= k ){
                    if( u == 3 ){
                        cerr << mask << ' ' << dp[ mask ][u] << ' ' << cost[mask] << '\n';
                    }
                    solS[ dp[mask][u] ] = max( solS[ dp[mask][u] ] , cost[mask] );
                }
            }
        }
    }

    solve( b );
    for( int mask = 1; mask < (1<<n); mask++ ){
        for( int u = 0; u < n; u++ ){
            if( (1<<u) & mask ){
                if( dp[mask][u] <= k ){
                    solB[ dp[mask][u] ] = max( solB[ dp[mask][u] ] , cost[mask] );
                }
            }
        }
    }

    for( int i = 1; i <= k; i++ ){
        solS[i] = max( solS[i] , solS[i-1] );
        solB[i] = max( solB[i] , solB[i-1] );
    }

    int sol = 0;
    for( int i = 0; i <= k; i++ ){
        sol = max( sol , solB[i] + solS[k-i] );
    }

    cout << sol << '\n';
}

