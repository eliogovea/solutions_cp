#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 310;
const int mod = 998244353;

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
    return (ll)a * b % mod;
}

int bpow( int b, int exp ){
    if( exp == 0 ) return 1;
    if( exp == 1 ) return b;
    int sol = bpow( b , exp/2 );
    sol = mult( sol, sol );
    if( exp & 1 ) sol = mult( sol , b );
    return sol;
}

int f[MAXN];
void calc_fact( int n ){
    f[0] = 1;
    for( int i = 1; i <= n; i++ ) f[i] = mult( f[i-1] , i );
}

int comb( int n, int k ){
    return mult( f[n] , bpow( mult( f[k] , f[n-k] ) , mod-2 ) );
}

int disc[MAXN], con[MAXN];

inline int tot( int n ){
    return bpow( 2 , n * (n-1) / 2 );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    const int N = 300;

    calc_fact(N);

    disc[0] = 1;
    disc[1] = 0;
    con[1] = 1;
    for( int n = 2; n <= N; n++ ){
        disc[n] = 0;
        for( int j = 1; j < n; j++ ){
            disc[n] = add( disc[n] , mult( comb( n-1 , j-1 ) , mult( con[j] , tot( n - j ) ) ) );
        }
        con[n] = rest( tot(n) , disc[n] );
    }

    int n;
    while (cin >> n) {
        cout << con[n] << "\n";
    }
}
