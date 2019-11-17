#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //freopen("dat.txt", "r", stdin);

    int tc; cin >> tc;

    while( tc-- ){
        int l1, a1, l2, a2, lt, at; cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;

        if( lt < l1 + l2 || at < a1 + a2 ){
            cout << "?\n";
            continue;
        }

        lt -= l1 + l2;
        at -= a1 + a2;

        int ii = 0, jj;
        int ok = 0;
        for( int i = 0; i <= 10005 && ok <= 1; i++ ){
            if( i * l1 > lt || i * a1 > at ){
                break;
            }

            if( ( lt - i*l1 ) % l2 == 0 && ( at - i*a1 ) % a2 == 0 &&
                ( lt - i*l1 ) / l2 == ( at - i*a1 ) / a2 ){
                ok++;
                ii = i;
                jj = ( lt - i*l1 ) / l2;
            }
        }

        if( ok == 1 ){
            cout << ii+1 << ' ' << jj+1 << '\n';
        }
        else{
            cout << "?\n";
        }
    }
}