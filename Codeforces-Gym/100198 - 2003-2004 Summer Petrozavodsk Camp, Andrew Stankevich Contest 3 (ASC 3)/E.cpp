// 2003-2004 Summer Petrozavodsk Camp, Andrew Stankevich Contest 3 (ASC 3)
// 100198E

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000010;

int level[MAXN];
typedef pair<int,int> par;

vector<int> g[MAXN];
par arcos[MAXN];

int cola[MAXN];
vector<int> sol[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);
    freopen("defence.in","r",stdin);
    freopen("defence.out","w",stdout);

    int n,m,s,t; cin >> n >> m >> s >> t;

    for(int i = 0; i < m; i++){
        int u,v; cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);

        arcos[i] = par(u,v);
    }

    int enq = 0, deq = 0;

    level[ s ] = 1;
    cola[enq++] = s;

    while( enq - deq ){
        int u = cola[deq++];
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if( !level[v] ){
                level[v] = level[u] + 1;
                cola[enq++] = v;
            }
        }
    }

    for(int i = 0; i < m; i++){
        int u = arcos[i].first;
        int v = arcos[i].second;

        if( level[u] > level[v] ){
            swap( u , v );
        }

        if( level[v] > level[t] ){
            sol[1].push_back( i+1 );
        }
        else{
            sol[ level[u] ].push_back( i+1 );
        }
    }

    cout << level[t]-1 << '\n';
    for(int i = 1; i < level[t]; i++){
        cout << sol[i].size();
        for(int j = 0; j < sol[i].size(); j++){
            cout << ' ' << sol[i][j];
        }
        cout << '\n';
    }
}
