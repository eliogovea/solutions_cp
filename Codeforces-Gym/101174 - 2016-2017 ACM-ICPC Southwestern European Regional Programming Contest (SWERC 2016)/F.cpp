// 2016-2017 ACM-ICPC Southwestern European Regional Programming Contest (SWERC 2016)
// 101174F

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

vector<int> g[MAXN];
int m[MAXN], r[MAXN], t[MAXN];

const int MAX = 100010;

typedef long long ll;

ll BIT[MAX];

void upd_bit( int p, ll upd ){
    while( p < MAX ){
        BIT[p] += upd;
        p += (p & -p );
    }
}

ll get_bit( int p ){
    ll res = 0;
    while( p > 0 ){
        res += BIT[p];
        p -= ( p & -p );
    }

    return res;
}

ll sol[MAXN];

void dfs( int u ){
    sol[u] -= get_bit( r[u] - 1 );

    for( int i = 0; i < g[u].size(); i++ ){
        dfs( g[u][i] );
    }

    sol[u] += get_bit( r[u] - 1 );

    upd_bit( r[u] , t[u] );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;

    int ro = 0;

    for( int i = 1; i <= n; i++ ){
        cin >> m[i] >> r[i] >> t[i];
        if( m[i] == -1 ){
            ro = i;
        }
        else{
            g[ m[i] ].push_back(i);
        }
    }

    dfs( ro );

    for( int i = 1; i <= n; i++ ){
        cout << sol[i] << '\n';
    }
}
