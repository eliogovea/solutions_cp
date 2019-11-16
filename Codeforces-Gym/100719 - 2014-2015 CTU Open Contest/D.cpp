// 2014-2015 CTU Open Contest
// 100719D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int tc; cin >> tc;

    while( tc-- ){
        ll k; cin >> k;

        ll m = 0ll;
        ll s = 1ll;

        while( s * 3ll <= k ){
            s *= 3ll;
            m++;
        }

        bool ok = false;

        while( m >= 0 ){
            if( ok ){
                cout <<' ';
            }

            cout << (k / s);
            k %= s;

            s /= 3ll;

            ok = true;
            m--;
        }

        cout << '\n';
    }
}
