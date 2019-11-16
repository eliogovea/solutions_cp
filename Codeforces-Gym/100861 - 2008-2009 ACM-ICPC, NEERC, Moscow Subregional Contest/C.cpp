// 2008-2009 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100861C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get_sol( ll n, ll m, ll x ){
    ll ro = sqrt( x );
    if( n > m ){
        swap( n , m );
    }

    n = min( n , ro );
    x -= n*n;
    m = n + (x+n-1)/n;

    return 2ll * ( n + m );
}

int a[90010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    ll n, m; cin >> n >> m;

    for( int i = 0; i < n*m; i++ ){
        cin >> a[i];
    }

    int sz = n*m;
    sort( a , a + sz );

    ll sol = 0;
    int j = 0;

    ll r = 0;

    for( int i = 0; i < sz; i = j ){
        while( j < sz && a[j] == a[i] ){
            j++;
        }

        ll x = sz - i;
        sol += (a[i] - r) * get_sol( n , m , x );
        r = a[i];
    }

    cout << sol << '\n';
}
