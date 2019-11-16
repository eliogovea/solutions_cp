// 2017 United Kingdom and Ireland Programming Contest (UKIEPC 2017)
// 101606A

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen( "dat.txt", "r", stdin );

    int n; cin >> n;
    int h[n+2], r[n+2], t[n+2];

    int mx = 1;

    for( int i = 1; i <= n; i++ ){
        cin >> h[i] >> r[i] >> t[i];

        if( h[mx] < h[i] ){
            mx = i;
        }
    }

    for( int i = 0; i < 1825 * h[mx]; i++ ){
        bool ok = true;

        for( int j = 1; j <= n; j++ ){
            int cur = i % h[j];

            if( r[j] < t[j] ){
                ok &= (cur <= r[j] || t[j] <= cur);
            }
            else{
                ok &= (t[j] <= cur && cur <= r[j]);
            }
        }

        if( ok ){
            cout << i << '\n';
            return 0;
        }
    }

    cout << "impossible\n";
}
