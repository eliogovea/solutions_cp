#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400;

int n, m;
vector<int> g[MAXN];
int from[MAXN];
bool mk[MAXN];

bool dfs( int u ){
    if( mk[u] ){
        return false;
    }

    mk[u] = true;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];

        if( !from[v] || dfs(from[v]) ){
            from[v] = u;
            return true;
        }
    }

    return false;
}

int kuhn(){
    fill( from , from + m + 1 , 0 );
    int mxf = 0;

    for( int i = 1; i <= n; i++ ){
        fill( mk , mk + n + 1 , false );
        if( dfs(i) ){
            mxf++;
        }
    }

    return mxf;
}

bool min_cover1[MAXN];
bool min_cover2[MAXN];
int cola[MAXN];

void min_cover(){
    fill( min_cover1 , min_cover1 + n + 1 , false );
    fill( min_cover2 , min_cover2 + m + 1 , false );

    for(int i = 1; i <= m; i++){
        if( from[i] ){
            min_cover1[ from[i] ] = true;
        }
    }

    int enq = 0, deq = 0;
    for(int i = 1; i <= n; i++){
        if( !min_cover1[i] ){
            cola[enq++] = i;
        }
    }

    while( deq < enq ){
        int u = cola[deq++];
        for( int i = 0; i < g[u].size(); i++ ){
            int v = g[u][i];

            if( from[v] ){
                min_cover2[v] = true;
                if( min_cover1[ from[v] ] ){
                    cola[enq++] = from[v];
                    min_cover1[ from[v] ] = false;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    cin >> n >> m;
    for( int i = 1; i <= n; i++ ){
        int di; cin >> di;

        int v;
        while( di-- ){
            cin >> v;
            g[i].push_back(v);
        }
    }

    kuhn();
    min_cover();

    vector<int> sol;
    for( int i = 1; i <= n; i++ ){
        if( !min_cover1[i] ){
            sol.push_back(i);
        }
    }

    cout << sol.size() << '\n';
    for( int i = 0; i < sol.size(); i++ ){
        cout << sol[i] << " \n"[i+1==sol.size()];
    }
}
