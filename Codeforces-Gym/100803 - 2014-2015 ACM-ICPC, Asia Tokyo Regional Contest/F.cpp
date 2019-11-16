// 2014-2015 ACM-ICPC, Asia Tokyo Regional Contest
// 100803F

#include <bits/stdc++.h>
#include <stdint.h>

using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int MAXN = 510,
          MAXE = 50100;
struct edge{
    int ini, fin, cost;
    bool mst;
};
bool cmp( const edge &A, const edge &B ){
    return A.cost < B.cost;
}

int P[MAXN],
    Rank[MAXN];
int n, m;
vector<edge> e;
vector<int> g[MAXN];
int mk[MAXE];
int p[MAXN], ed[MAXN], depth[MAXN];

void MakeSet( int x ){
    P[x] = x;
    Rank[x] = 1;
}

int FindSet( int x ){
    if( P[x] != x )
        P[x] = FindSet(P[x]);
    return P[x];
}

bool joinSet( int x, int y ){
    int px = FindSet(x),
        py = FindSet(y);
    if( px == py )
        return false;

    if( Rank[px] > Rank[py] ){
        P[py] = px;
        Rank[px] += Rank[py];
    }
    else{
        P[px] = py;
        Rank[py] += Rank[px];
    }
    return true;
}

void dfs( int );
int FindMax(int,int,int);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("data.txt", "r", stdin);
    cin >> n >> m;

    for( int i = 1,a,b,c;i <= m; i++ ){
        cin >> a >> b >> c;
        e.push_back( {a,b,c,0} );
        if( i <= n )
            MakeSet(i);
    }
    MakeSet(n);
    sort( e.begin(), e.end(),cmp );
    int Sol = 0, sol2 = 0;

    for( int i = 0; i < e.size(); i++ ){
        if( !joinSet( e[i].ini, e[i].fin ) ) continue;

        g[ e[i].ini ].push_back( i );
        g[ e[i].fin ].push_back( i );
        e[i].mst = true;
      //  cout << e[i].ini << " " << e[i].fin << endl;
        Sol += e[i].cost;
    }

    depth[1] = 1;
    dfs( 1 );
    //for( int i = 1; i <= n; i++ )
     //   cout << p[i] << endl;
    fill( mk, mk+e.size()+1, 0 );
    for( int i = 0; i < e.size(); i++ ){
        if( e[i].mst ) continue;
        //cout << e[i].ini << " " << e[i].fin << endl;
        int s = FindMax( e[i].ini, e[i].fin, e[i].cost );
        Sol -= s*e[i].cost;
    }
    for(int i = 0; i < e.size(); i++ ){
        if( e[i].mst && !mk[ i ] ) sol2++;
    }
    cout << sol2 << " " << Sol << '\n';
}

int FindMax( int u, int v, int cc ){
    int res = 0;
    if( depth[u] < depth[v] )
        swap( u,v );
    while( depth[ u ] > depth[v] ){
        if( e[ ed[u] ].cost == cc && !mk[ ed[u] ] ){
            res++;
            mk[ ed[u] ] = true;
            }
        u = p[u];
    }
    while( u != v ){
        if( e[ ed[u] ].cost == cc && !mk[ ed[u] ] )
            res++,
            mk[ ed[u] ] = true;
        if( e[ ed[v] ].cost == cc && !mk[ ed[v] ] )
            res++,
            mk[ ed[v] ] = true;

        u = p[u];
        v = p[v];
    }
    return res;
}

void dfs( int u ){
    mk[u] = true;
    for( int i = 0; i < g[u].size(); i++ ){
        int id = g[u][i];
        int v = e[ id ].ini==u? e[ id ].fin: e[ id ].ini;
        if( mk[v] ) continue;
        p[v] = u;
        ed[v] = id;
        depth[v] = depth[u]+1;
        dfs( v );
    }
}


