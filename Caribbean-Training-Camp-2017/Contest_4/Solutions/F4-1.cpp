#include <bits/stdc++.h>

using namespace std;

const int MAXN = 310;

int n1, n2;

vector<int> g[MAXN];
bool mk[MAXN];
int from[MAXN];
int go[MAXN];

bool dfs_kuhn( int u ){
    if( mk[u] ){
        return false;
    }

    mk[u] = true;

    for( int v : g[u] ){
        if( !from[v] || dfs_kuhn( from[v] ) ){
            go[u] = v;
            from[v] = u;
            return true;
        }
    }

    return false;
}

int kuhn(){
    int matching_sz = 0;
    for( int u = 1; u <= n1; u++ ){
        fill( mk , mk + 1 + n1 , false );
        if( dfs_kuhn(u) ){
            matching_sz++;
        }
    }

    return matching_sz;
}

/////////// MINIMUM VERTEX COVER ON BIPARTITE GRAPH

bool min_cover1[MAXN];
bool min_cover2[MAXN];
int cola[2*MAXN];

int min_cover(){
    int enq = 0, deq = 0;

    fill( min_cover1 , min_cover1 + n1 + 1 , false );
    fill( from , from + n2 + 1 , 0 );
    fill( min_cover2 , min_cover2 + n2 + 1 , 0 );

    int max_matching = kuhn();

    for(int i = 1; i <= n2; i++){
        if( from[i] ){
            min_cover1[ from[i] ] = true;
        }
    }

    for(int i = 1; i <= n1; i++){
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

    int mnv = 0;
    for( int i = 1; i <= n1; i++ ){//el vertice i del grupo_1 pertenece al min_vertex_cover
        if( min_cover1[i] ){
            mnv++;
        }
    }
    for( int i = 1; i <= n2; i++ ){
        if( min_cover2[i] ){//el vertice i del grupo_2 pertenece al min_vertex_cover
            mnv++;
        }
    }

    return mnv;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n1 >> n2;

    for( int u = 1; u <= n1; u++ ){
        int c; cin >> c;
        while( c-- ){
            int v; cin >> v;
            g[u].push_back(v);
        }
    }

    min_cover();

    fill( mk , mk + n2 + 1 , false );
    int s = 0;
    vector<int> sol;
    for( int u = 1; u <= n1; u++ ){
        if( !min_cover1[u] ){
            s++;
            sol.push_back(u);
            for( int v : g[u] ){
                if( !mk[v] ){
                    mk[v] = true;
                    s--;
                }
            }
        }
    }

    if( s < 0 ){
        cout << "0\n";
    }
    else{
        cout << sol.size() << '\n';
        for( int i = 0; i < sol.size(); i++ ){
            cout << sol[i] << " \n"[i+1 == sol.size()];
        }
    }
}
