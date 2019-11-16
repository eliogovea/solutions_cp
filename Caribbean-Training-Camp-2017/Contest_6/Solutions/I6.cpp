#include <bits/stdc++.h>

using namespace std;

const int MAXN = 6000;
const int MAX = 5000;

const int mod = 1000000007;

inline int add( int a, int b ){
    a += b;
    if( a >= mod ){
        a -= mod;
    }

    return a;
}

typedef long long ll;

inline int mult( int a, int b ){
    return ( (ll)a * (ll)b ) % mod;
}

int bpow( int b, int e ){
    if( e == 0 ){
        return 1;
    }
    if( e == 1 ){
        return b;
    }

    int res = bpow( b , e/2 );
    res = mult( res , res );
    if( e & 1 ){
        res = mult( res , b );
    }

    return res;
}

int fact[MAXN];

inline int comb( int n, int k ){
    if( n < 0 || k < 0 || n < k ){
        return 0;
    }

    return mult( fact[n] , bpow( mult( fact[n-k] , fact[k] ) , mod-2 ) );
}

int cnt[MAXN];
int c[MAXN];
int acc[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    fact[0] = 1;
    for( int i = 1; i < MAXN; i++ ){
        fact[i] = mult( fact[i-1] , i );
    }

    int n, t; cin >> n >> t;

    for( int i = 1; i <= n; i++ ){
        cin >> c[i];

        cnt[ c[i] ]++;
    }

    for( int i = 1; i <= MAX; i++ ){
        acc[i] = acc[i-1] + cnt[i];
        /*if( i <= 10 ){
            cerr << acc[i] << ' ';
        }*/
    }//cerr << '\n';

    int k, x; cin >> k >> x;
    int ck = c[k];

    int sol = 0;

    //cerr << "t = " << t << '\n';

    int acc_mn = acc[ck-1];
    int acc_mx = acc[MAX]-acc[ck];

    //cerr << "acc_mn = " << acc_mn << "  acc_mx = " << acc_mx << '\n';

    for( int eq = 0; eq+1 <= min( cnt[ck] , t ); eq++ ){
        for( int mn = 0; mn <= min( acc_mn , x-1 ) && mn + eq + 1 <= t; mn++ ){
            int mx = t - (mn + eq + 1);
            //cerr << "eq = " << eq << "  mn = " << mn << "  mx = " << mx << '\n';

            if( mx > acc_mx || mn + eq + 1 < x ){
                continue;
            }

            //cerr << "ENTRO\n";
            //cerr << "eq = " << eq << "  mn = " << mn << "  mx = " << mx << '\n';

            sol = add( sol ,
                       mult( comb( cnt[ck]-1 , eq ) ,
                             mult( comb( acc_mn , mn ) , comb( acc_mx , mx ) )
                       )
                      );
        }
    }

    cout << sol << '\n';
}
