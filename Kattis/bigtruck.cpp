#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;
typedef pair<par,int> kk;

const int MAXN = 200;
const int oo = ( 1 << 30 );

par d[MAXN];
bool mk[MAXN];
int n;
int t[MAXN];
vector<par> g[MAXN];

bool dijkstra( int ini, int end ){
    for( int i = 0; i <= n; i++ ){
        mk[i] = false;
        d[i] = par( oo , -oo );
    }

    d[ini] = par( 0 , t[ini] );
    priority_queue<kk> pq; pq.push( kk( d[ini] , ini ) );

    while( !pq.empty() ){
        int u = pq.top().second; pq.pop();

        if( mk[u] ){
            continue;
        }

        if( u == end ){
            return true;
        }

        mk[u] = true;
        for( int i = 0; i < g[u].size(); i++ ){
            int v = g[u][i].first;
            int w = g[u][i].second;

            if( d[v].first > d[u].first + w ||
               (d[v].first == d[u].first + w && d[v].second < d[u].second + t[v]) ){
                d[v].first = d[u].first + w;
                d[v].second = d[u].second + t[v];

                pq.push( kk( par( -d[v].first , d[v].second ) , v ) );
            }
        }
    }

    return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

    cin >> n;

    for( int i = 1; i <= n; i++ ){
        cin >> t[i];
    }

    int m; cin >> m;

    for( int i = 0; i < m; i++ ){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back( par( v , w ) );
        g[v].push_back( par( u , w ) );
    }

    if( !dijkstra( 1 , n ) ){
        cout << "impossible\n";
    }
    else{
        cout << d[n].first << ' ' << d[n].second << '\n';
    }
}
