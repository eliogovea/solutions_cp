// 2016-2017 CT S03E02: Codeforces Trainings Season 3 Episode 2 - 2004-2005 OpenCup, Volga Grand Prix
// 101090I

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 300000;

int c[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;

    for( int i = 2; i <= n; i++ ){
        int mk = 0;

        for( int j = 1; j+j <= i; j++ ){
            if( c[j] == c[i-j] ){
                mk |= ( 1 << c[j] );
            }
        }

        if( mk == 1023 ){
            for( int j = 1; j <= n; j++ ){
                cout << '0';
            }
            cout << '\n';

            return 0;
        }

        if( !(mk & ( 1 << c[i-1] ) ) ){
            c[i] = c[i-1];
            continue;
        }

        for( int k = 0; k < 10; k++ ){
            if( !(mk & ( 1 << k ) ) ){
                c[i] = k;
                break;
            }
        }
    }

    for( int i = 1; i <= n; i++ ){
        cout << c[i];
    }

    cout << '\n';
}
