#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
const int MAXM = 100100;

int n1, n2, m;

struct arc{
    int u, v;
    arc(){}
    arc( int u, int v ) : u(u), v(v){}
}E[MAXM];

inline int ady( int e, int u ){
    if( E[e].u == u ){
        return E[e].v;
    }

    return E[e].u;
}

vector<int> g[MAXN];

bool mk[MAXN];
int from[MAXN];
int go[MAXN];

int matching_SZ;

bool kuhn( int u ){
    if( mk[u] ){
        return false;
    }

    mk[u] = true;
    for( int e : g[u] ){
        int v = ady(e,u);
        if( !from[v] || kuhn( from[v] ) ){
            from[v] = u;
            go[u] = v;
            return true;
        }
    }

    return false;
}

inline bool node_in_matching( int u ){
    if( u <= n1 ){
        return go[u] > 0;
    }

    return from[u] > 0;
}

inline bool arc_in_matching( int e ){
    return go[ E[e].u] == E[e].v;
}

inline bool low_nod(int u){
    return !node_in_matching(u);
}

inline bool low_arc( int e ){
    return !node_in_matching(E[e].u) || !node_in_matching(E[e].v);
}

int ord[MAXN], _t;
int SCC[MAXN], _scc;

inline bool can_move_scc_dfs1( int e, int u ){
    if( low_arc(e) ){
        return false;
    }

    if( arc_in_matching(e) ){
        return E[e].u == u;
    }

    return E[e].v == u;
}

inline bool can_move_scc_dfs2( int e, int u ){
    if( low_arc(e) ){
        return false;
    }

    return !can_move_scc_dfs1(e,u);
}

void scc_dfs1( int u ){
    mk[u] = true;
    for( int e : g[u] ){
        int v = ady(e,u);
        if( can_move_scc_dfs1(e,u) && !mk[v] ){
            scc_dfs1(v);
        }
    }

    ord[--_t] = u;
}

void scc_dfs2( int u ){
    mk[u] = true;
    SCC[u] = _scc;
    for( int e : g[u] ){
        int v = ady(e,u);
        if( can_move_scc_dfs2(e,u) && !mk[v] ){
            scc_dfs2(v);
        }
    }
}

void find_scc(){
    _scc = 0;
    _t = matching_SZ*2 + 1;
    fill( mk , mk + 1 + n1 + n2 , false );
    for( int u = 1; u <= n1 + n2; u++ ){
        if( !mk[u] && node_in_matching(u) ){
            scc_dfs1(u);
        }
    }

    fill( mk , mk + 1 + n1 + n2 , false );
    for( int i = 1; i <= matching_SZ*2; i++ ){
        int u = ord[i];
        if( !mk[u] ){
            _scc++;
            scc_dfs2(u);
        }
    }
}

bool mkE[MAXM];

inline bool can_move_dfs1( int e, int u ){
    if( arc_in_matching(e) ){
        return E[e].u == u;
    }

    return E[e].v == u;
}

void dfs1( int u ){
    mk[u] = true;
    for( int e : g[u] ){
        int v = ady(e,u);
        if( !can_move_dfs1(e,u) ){
            continue;
        }
        mkE[e] = true;
        if( !mk[v] ){
            dfs1(v);
        }
    }
}

void dfs2( int u ){
    mk[u] = true;
    for( int e : g[u] ){
        int v = ady(e,u);
        if( can_move_dfs1(e,u) ){
            continue;
        }
        mkE[e] = true;
        if( !mk[v] ){
            dfs2(v);
        }
    }
}

inline bool in_sol( int e ){
    return arc_in_matching(e) || low_arc(e) || mkE[e] || (SCC[ E[e].u ] > 0 && SCC[ E[e].u ] == SCC[ E[e].v ]);
}

void print_sol(){
    vector<int> sol;
    for( int e = 1; e <= m; e++ ){
        if( in_sol(e) ){
            sol.push_back(e);
        }
    }

    cout << sol.size() << '\n';
    for( int i = 0; i < sol.size(); i++ ){
        cout << sol[i] << " \n"[i+1==sol.size()];
    }
}

void print_scc(){
    cerr << "SCC\n";
    for( int u = 1; u <= n1 + n2; u++ ){
        cerr << SCC[u] << " \n"[u==n1+n2];
    }
}

void print_matching(){
    cerr << "Matching\n";
    for( int e = 1; e <= m; e++ ){
        if( arc_in_matching(e) ){
            cerr << E[e].u << ' ' << E[e].v - n1 << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n1 >> n2 >> m;

    for( int e = 1; e <= m; e++ ){
        int u, v; cin >> u >> v; v += n1;
        E[e] = arc( u , v );
        g[u].push_back(e);
        g[v].push_back(e);
    }

    matching_SZ = 0;
    for( int u = 1; u <= n1; u++ ){
        fill( mk , mk + 1 + n1 , false );
        if( kuhn(u) ){
            matching_SZ++;
        }
    }

    find_scc();

    fill( mk , mk + 1 + n1 + n2 , false );
    for( int u = n1+1; u <= n1+n2; u++ ){
        if( !node_in_matching(u) && !mk[u] ){
            dfs1(u);
        }
    }

    fill( mk , mk + 1 + n1 + n2 , false );
    for( int u = 1; u <= n1; u++ ){
        if( !node_in_matching(u) && !mk[u] ){
            dfs2(u);
        }
    }

    print_sol();
}
