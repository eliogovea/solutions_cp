// 2017-2018 ACM-ICPC East Central North America Regional Contest (ECNA 2017)
// 101673F

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

int cnt[MAXN];
vector<int> g[MAXN];

void dfs( int u, int p ){
    cnt[u] = 1;
    for( auto v : g[u] ){
        if( v != p ){
            dfs(v,u);
            cnt[u] += cnt[v];
        }
    }
}

typedef pair<int,int> par;

par sol;
int n;

void solve( int u, int p ){
    vector<int> cc;
    cc.push_back( n - cnt[u] );
    cc.push_back( 0 );

    for( auto v : g[u] ){
        if( p != v ){
            cc.push_back( cnt[v] );
            solve( v , u );
        }
    }

    sort( cc.begin() , cc.end() , greater<int>() );

    int tot = n-1;
    int n1 = 0;

    for( auto x : cc ){
        tot -= x;
        n1 += x * tot;
    }

    int n2 = n1 - cc[0] * cc[1];

    sol = max( sol , par( n1 , n2 ) );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    int m; cin >> m;

    while( m-- ){
        int u, v; cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);

        n = max( n , max( u , v ) );
    }
    n++;

    dfs( 0 , -1 );
    solve( 0 , -1 );
    cout << sol.first << ' ' << sol.second << '\n';
}
