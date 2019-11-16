// 2012 Nordic Collegiate Programming Contest (NCPC)
// 100112J

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> par;

const int MAXN = 10010;

par a[MAXN];

int r[MAXN] , c[MAXN];
int p[MAXN];

bool ok( int u, int d ){
    if( u == 0 ){
        return true;
    }

    return ( c[u] >= d && ok( p[u] , d ) );
}

void doo( int u, int d ){
    if( u == 0 ){
        return;
    }
    c[u] -= d;
    doo( p[u] , d );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> p[i] >> r[i] >> c[i];
        a[i-1] = par( r[i] , i );
    }

    sort( a , a + n );

    int sol = 0;
    for( int i = 0; i < n; i++ ){
        if( ok( a[i].second , a[i].first ) ){
            sol++;
            doo( a[i].second , a[i].first );
        }
    }

    cout << sol << '\n';
}
