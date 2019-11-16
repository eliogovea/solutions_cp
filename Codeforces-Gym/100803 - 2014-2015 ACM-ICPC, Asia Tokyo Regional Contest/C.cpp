// 2014-2015 ACM-ICPC, Asia Tokyo Regional Contest
// 100803C

#include <bits/stdc++.h>

using namespace std;

typedef long ll;
typedef pair<int,int> par;

const int MAXN = 3000;

par qs[MAXN];
par ok[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n,m; cin >> n >> m;

    for( int i = 0; i < m; i++ ){
        cin >> qs[i].first >> qs[i].second;
    }

    sort( qs , qs + m );

    int sz = 0;

    int l = qs[0].first , r = qs[0].second;

    for( int i = 1; i < m; i++ ){
        if( qs[i].first <= r ){
            r = max( r, qs[i].second );
        }
        else{
            ok[sz++] = par( l , r );
            l = qs[i].first;
            r = qs[i].second;
        }
    }

    ok[sz++] = par( l , r );

    int outp = 0;
    int ini = 0;

    for( int i = 0; i < sz; i++ ){
        outp += ( ok[i].first - ini ) +  ( ok[i].second - ok[i].first ) * 3;
        ini = ok[i].second;
    }

    outp += (n+1) - ini;

    cout << outp << '\n';
}
