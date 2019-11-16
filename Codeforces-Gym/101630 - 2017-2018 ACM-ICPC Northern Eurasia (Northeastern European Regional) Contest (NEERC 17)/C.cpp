// 2017-2018 ACM-ICPC Northern Eurasia (Northeastern European Regional) Contest (NEERC 17)
// 101630C

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;
vector<int> g[MAXN], rg[MAXN];
int s[MAXN], t[MAXN];
bool mk[MAXN];
bool ok[MAXN];

inline int ady( int e, int u ){
    return s[e] == u ? t[e] : s[e];
}

void dfs( int u, vector<int> *g ){
    mk[u] = true;
    for( auto e : g[u] ){
        int v = ady( e , u );
        if( !mk[v] ){
            ok[e] = true;
            dfs( v , g );
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int tc; cin >> tc;

    while( tc-- ){
        int n, m; cin >> n >> m;
        for( int i = 0; i <= max( n , m ); i++ ){
            g[i].clear();
            rg[i].clear();
            mk[i] = ok[i] = false;
        }

        for( int i = 0; i < m; i++ ){
            int u, v; cin >> u >> v;
            g[u].push_back(i);
            rg[v].push_back(i);
            s[i] = u;
            t[i] = v;
        }

        dfs( 1 , g );
        fill( mk , mk + n + 1 , false );
        dfs( 1 , rg );

        int cnt = 0;
        for( int i = 0; i < m && cnt < m - 2*n; i++ ){
            if( !ok[i] ){
                cnt++;
                cout << s[i] << ' ' << t[i] << '\n';
            }
        }
    }
}
