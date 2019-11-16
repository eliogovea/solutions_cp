#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

typedef long long ll;

int n;
void add( ll *bit, int p, ll upd ){
    //cerr << "add " << p << "  " << upd << '\n';

    while( p <= n ){
        bit[p] += upd;
        p += ( p & -p );
    }
}

ll get( ll *bit, int p ){
    ll re = 0;
    while( p > 0 ){
        re += bit[p];
        p -= (p & -p);
    }
    return re;
}

ll B1[MAXN], B2[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n;

    ll sol = 0;

    for( int i = 1; i <= n; i++ ){
        ll x; cin >> x;
        if( i > 2 ){
            sol += get(B2 , n) - get( B2 , x );
        }

        add( B2 , x , get( B1 , n ) - get( B1 , x ) );
        add( B1 , x , 1 );

        //cerr << sol << '\n';
    }

    cout << sol << '\n';
}

