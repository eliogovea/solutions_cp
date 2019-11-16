// 2012-2013 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100685F

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;
int n,k;
vector< int > g[MAXN];

int st[MAXN] , top;
bool mark[MAXN];
bool mk2[MAXN];

bool cycle( int u ){
   // cout << u << '\n';
    if( mark[u] ){
        return false;
    }
    mark[u] = mk2[u] = true;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        if( mk2[v] || cycle(v) ){
           // cout << "---cycle---\n" << '\n';
            return true;
        }
    }

    st[ top-- ] = u;
    mk2[u] = false;

    return false;
}

void topsort( int n ){
    for( int i = 1; i <= n; i++ ){
        if( !mark[i] ){
            cycle(i);
        }
    }
}

double a[MAXN] , p[MAXN], cap[MAXN];
double dp[MAXN];

void solve( int n ){
    for( int i = 1; i <= n; i++ ){
        int u = st[ top + i ];
        //cout << u << ' ';

        if( dp[u] > cap[u] ){
            dp[u] -= cap[u];

            for( int j = 0; j < g[u].size(); j++ ){

                double w = ( double ) dp[u] / ( double ) g[u].size();

                int v = g[u][j];
                dp[v] += w;
            }

            a[u] = p[u];
        }
        else{
            a[u] += dp[u];
        }
    }
    //cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n >> k;

    for( int i = 1; i <= n; i++ ){
        cin >> p[i] >> a[i];
        cap[i] = p[i] - a[i];
    }

    for( int i = 0; i < k; i++ ){
        int x,y; cin >> x >> y;
        g[x].push_back( y );
    }

    int fin = n + 10;
    top = fin;
    topsort(n);

    int x,z; double y;
    cin >> x >> y >> z;

    dp[x] = y;
    solve(n);

    cout.precision( 5 );
    cout << fixed << a[z] << '\n';
}
