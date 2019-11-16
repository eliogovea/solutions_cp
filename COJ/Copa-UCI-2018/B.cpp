#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1000000007;

int add( int a, int b ){
    a += b;
    if( a >= mod ) a -= mod;
    return a;
}

int rest( int a, int b ){
    a -= b;
    if( a < 0 ) a += mod;
    return a;
}

int mult( int a, int b ){
    return (ll) a * b % mod;
}

const int MAXN = 10002;
int sol[MAXN][26][26];
int tot[MAXN][26];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout.precision(7);

    //freopen("dat.txt","r",stdin);

    int n, m; cin >> n >> m;

    for( int i = 0; i < m; i++ ){
        tot[1][i] = 1;
    }

    for( int i = 0; i < m; i++ ){
        for( int j = 0; j < m; j++ ){
            if( i != j ){
                sol[2][i][j] = 1;
                tot[2][j]++;
            }
        }
    }

    for( int z = 3; z <= n; z++ ){
        for( int i = 0; i < m; i++ ){
            for( int j = 0; j < m; j++ ){
                if( i != j ){
                    sol[z][i][j] = rest( tot[z-1][i] , sol[z-1][j][i] );
                    tot[z][j] = add( tot[z][j] , sol[z][i][j] );
                }
            }
        }
    }

    int sol = 0;
    for( int i = 0; i < m; i++ ){
        sol = add( sol , tot[n][i] );
    }

    cout << sol << '\n';
}

