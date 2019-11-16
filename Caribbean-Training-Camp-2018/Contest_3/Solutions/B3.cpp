#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100100;

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
void calc_fact( ll n ){
    f[0] = 1;
    for( int i = 1; i <= n; i++ ) f[i] = mult( f[i-1] , i );
}

int comb( int n, int k ){
    return mult( f[n] , bpow( mult( f[k] , f[n-k] ) , mod-2 ) );
}

int dn[MAXN];
void calc_dn( int n ){
    dn[0] = 1;
    dn[1] = 0;

    for( int i = 2; i <= n; i++ ){
        dn[i] = mult( i , dn[i-1] );
        if( i & 1 ) dn[i] = rest( dn[i] , 1 );
        else dn[i] = add( dn[i] , 1 );
    }
}

bool prime( int n ){
    for( int i = 2; i * i <= n; i++ ){
        if( n % i == 0 ) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    int n; cin >> n;

    calc_fact(n);
    calc_dn(n);

    //cerr << bpow( 2 , 2 ) << '\n';
    //return 0;

    int sol = 0;
    for( int k = 0; k <= n; k++ ){
        sol = add( sol , mult( comb( n , k ) , mult( dn[n-k] , bpow( 2 , n-k ) ) ) );
        //cerr << comb( n , k ) << ' ' << dn[n-k] << ' ' << bpow( 2 , n-k ) << '\n';
        //cerr << mult( comb( n , k ) , mult( dn[n-k] , bpow( 2 , n-k ) ) ) << '\n';
    }

    cout << sol << '\n';

    //cerr << prime(mod) <<'\n';
}

