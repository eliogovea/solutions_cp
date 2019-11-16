// 2009-2010 Petrozavodsk Winter Training Camp, Warsaw Contest
// 100603C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000100;
const ll oo = ( 1ll << 60ll );

ll m[MAXN];

int a[MAXN];
int ord[MAXN];

ll mn;
ll c;
ll tot;

bool mk[MAXN];

void dfs( int i ){
    if( mk[i] ){
        return;
    }

    mk[i] = true;
    tot += m[ a[i] ];
    mn = min( mn , m[ a[i] ] );
    c++;

    dfs( ord[ a[i] ] );
}

typedef pair<ll,ll> par;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;

    for( int i = 1; i <= n; i++ ){
        cin >> m[i];
    }

    for( int i = 1; i <= n; i++ ){
        cin >> a[i];
    }

    for( int i = 1; i <= n; i++ ){
        int b; cin >> b;
        ord[b] = i;
    }

    ll sol = 0ll;
    vector<par> x;

    for( int i = 1; i <= n; i++ ){
        mn = oo;
        c = 0;
        tot = 0;

        dfs(i);
        if( c == 0 ){
            continue;
        }

        sol += tot - mn;

        x.push_back( par( mn , c ) );
    }

    sort( x.begin() , x.end() );

    if( x[0].second > 1ll ){
        sol += (x[0].second - 1ll) * x[0].first;
    }

    ll mn = x[0].first;

    for( int i = 1; i < x.size(); i++ ){
        sol += min( x[i].first * ( x[i].second - 1ll ) ,
                    mn + 2ll * x[i].first + mn * x[i].second );
    }

    cout << sol << '\n';
}
