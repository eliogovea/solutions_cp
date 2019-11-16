// 2005-2006 ACM-ICPC, NEERC, Southern Subregional Contest
// 100765F

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;

const int oo= (1<<29);
const int MAXN = 3000;
int cost[MAXN];
vector<par> g[MAXN];
int a[MAXN];
int s[MAXN];
par aux[MAXN];

int d[MAXN] , d2[MAXN];
bool mk[MAXN] , mk2[MAXN];

void dijkstra( int start , int *d, bool *mk , int n ){
    priority_queue< par > pq;
    pq.push( par( 0 , start ) );

    for(int i = 0; i <= n; i++){
        d[i] = oo;
    }
    d[start] = 0;

    while( !pq.empty() ){
        int u = pq.top().second; pq.pop();
        if( mk[u] ){
            continue;
        }
        mk[u] = true;

        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i].second;
            int w = g[u][i].first;

            if( d[v] > d[u] + w ){
                d[v] = d[u] + w;
                pq.push( par( -d[v] , v ) );
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n,x,y; cin >> n >> x >> y;
    int m; cin >> m;
    for(int i = 1; i <= m; i++){
        int u,v,l; cin >> u >> v >> l;
        g[u].push_back( par( l , v ) );
        g[v].push_back( par( l , u ) );
    }

    dijkstra( x , d , mk , n );
    dijkstra( y , d2 , mk2 , n );

    map<int,int> dic;

    int sz = 0;

    for(int i = 1; i <= n; i++){
        if( d[i] + d2[i] == d[ y ] ){
            aux[ sz++ ] = par( d[i] , i );
            dic[ d[i] ]++;
        }
    }

    sort( aux , aux + sz );

    for( int u = 1; u <= n; u++ ){
        for( int j = 0; j < g[u].size(); j++ ){
            int v = g[u][j].second;
            int w = g[u][j].first;

            if( d[u] + w + d2[v] == d[y] ){
                int lw = lower_bound( aux , aux + sz , par( d[u] + 1 , 0 ) ) - aux;
                int up = upper_bound( aux , aux + sz , par( d[v] , 0 ) ) - aux;


                s[ lw ]++;
                s[ up ]--;
            }
        }
    }

    int c = 0;
    for( int i = 0; i < sz; i++ ){
        c += s[i];
        a[ aux[i].second ] = c + dic[ d[ aux[i].second ] ];
    }

    for(int u = 1; u <= n; u++){
        if( u > 1 ){
            cout << ' ';
        }
        cout << a[u];
    }
}
