// 2015-2016 ACM-ICPC Nordic Collegiate Programming Contest (NCPC 2015)
// 100781A

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

vector<int> g[MAXN];

int d[MAXN];
int d1[MAXN];
int d2[MAXN];
int mk[MAXN];

typedef pair<int,int> par;

int n;

int dfs( int u, int p , int *d, int dist){
    mk[u] = true;
    d[u] = dist;

    if( g[u].size() == 0 || ( g[u].size() == 1 && p != -1 ) ){
        return u;
    }

    int ret = u;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if( v != p ){
            int tmp = dfs( v , u , d , dist+1 );
            if( d[ret] < d[tmp] ){
                ret = tmp;
            }
        }
    }

    return ret;
}

int get_sol( int u , int p ){
    if( g[u].size() == 0 || (g[u].size() == 1 && p != -1 ) ){
        return max( d1[u] , d2[u] );
    }

    int ret = max( d1[u] , d2[u] );

    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if( v != p ){
            int tmp = get_sol( v , u );
            ret = min( ret , tmp );
        }
    }

    return ret;
}

int kk[MAXN];

int solve( int u ){
    int a = dfs( u , -1 , d , 0 );

    int b = dfs( a , -1 , d1 , 0 );

            dfs( b , -1 , d2 , 0 );

    kk[u] = d1[b];

    return get_sol( u , -1 );
}

int sol[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int nsol = 0;

    for(int i = 0; i < n; i++){
        if( !mk[i] ){
            sol[nsol++] = solve( i );
        }
    }

    sort( sol , sol + nsol );

    int outp = 0;
    for(int i = 0; i < n; i++){
        outp = max( outp , kk[i] );
    }
    if( n > 1 ){
        outp = max( outp , sol[nsol-1] + sol[nsol-2] + 1 );
    }
    if( nsol > 2 ){
        outp = max( outp , sol[nsol-2] + sol[nsol-3] + 2 );
    }

    cout << outp << '\n';
}
