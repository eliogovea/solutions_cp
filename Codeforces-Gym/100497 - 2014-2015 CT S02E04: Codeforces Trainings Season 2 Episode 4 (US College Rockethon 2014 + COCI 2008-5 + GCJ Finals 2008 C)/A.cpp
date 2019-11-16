// 2014-2015 CT S02E04: Codeforces Trainings Season 2 Episode 4 (US College Rockethon 2014 + COCI 2008-5 + GCJ Finals 2008 C)
// 100497A

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

int m[MAXN], w[MAXN], s[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("in.txt","r",stdin);

    int n; cin >> n;

    int W = 0, M = 0, K = 0;

    for( int i = 1; i <= n; i++ ){
        cin >> m[i] >> w[i] >> s[i];

        w[i] = min( s[i] , w[i] );
        W += w[i];

        M += min( s[i] - w[i] , m[i] );
        m[i] -= min( s[i] - w[i] , m[i] );

        K += min( m[i] , w[i] );
    }

    if( M >= W ){
        cout << W << '\n';
    }
    else{
        W -= M;
        cout << min( M + K , M + (W/2) ) << '\n';
    }
}
