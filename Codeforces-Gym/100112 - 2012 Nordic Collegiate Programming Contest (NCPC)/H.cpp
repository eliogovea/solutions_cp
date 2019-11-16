// 2012 Nordic Collegiate Programming Contest (NCPC)
// 100112H

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> par;

const int MAXN = 10010;
const int oo = ( 1 << 30 );

int h[MAXN];
int cola[MAXN];

vector<int> g[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n, H, L; cin >> n >> H >> L;

    for( int i = 0; i < n; i++ ){
        h[i] = oo;
    }

    int enq = 0, deq = 0;

    for( int i = 0; i < H; i++ ){
        int x; cin >> x;
        h[x] = 0;
        cola[enq++] = x;
    }

    for( int i = 0; i < L; i++ ){
        int u, v; cin >> u >> v;
        g[u].push_back( v );
        g[v].push_back( u );
    }

    while( enq > deq ){
        int sz = enq - deq;
        for( int i = 0; i < sz; i++ ){
            int u = cola[deq++];
            for( int j = 0; j < g[u].size(); j++ ){
                int v = g[u][j];
                if( h[v] == oo ){
                    h[v] = h[u] + 1;
                    cola[enq++] = v;
                }
            }
        }
    }

    int sol = 0;

    for( int i = 0; i < n; i++ ){
        if( h[sol] < h[i] ){
            sol = i;
        }
    }

    cout << sol << '\n';
}
