// 2016-2017 CT S03E04: Codeforces Trainings Season 3 Episode 4
// 101104I

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2000;

int ab[MAXN][MAXN];
int a[MAXN], b[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int tc; cin >> tc;

    while( tc-- ){
        ll d, n; cin >> d >> n;

        for( int i = 0; i < d; i++ ){
            for( int j =0 ; j < d; j++ ){
                ab[i][j] = 0;
            }

            a[i] = b[i] = 0;
        }

        int sol = n;

        for( int i = 0; i < n; i++ ){
            ll x, y; cin >> x >> y; x += 1000000000; y += 1000000000;

            a[x%d]++;
            b[y%d]++;

            ab[x%d][y%d]++;
        }

        for( int i = 0; i < d; i++ ){
            for( int j = 0; j < d; j++ ){
                sol = min( sol , a[i] + b[j] - ab[i][j] );
            }
        }

        cout << sol << '\n';
    }
}
