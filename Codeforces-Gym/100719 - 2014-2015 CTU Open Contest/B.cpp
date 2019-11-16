// 2014-2015 CTU Open Contest
// 100719B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 10000000;

int a[MAXN] , b[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int tc; cin >> tc;

    while( tc-- ){
        int n; cin >> n;

        int d = 0;

        int sol = 0;

        for( int i = 0; i < n; i++ ){
            cin >> a[i] >> b[i];

            if( i == 0 ){
                d = b[i] - a[i];
                sol = d;
            }
            else{
                d = min( b[i] - a[i] , d + 1 + ( b[i] - b[i-1] ) );
                sol = min( d , sol );
            }
        }

        for( int i = n-1; i >= 0; i-- ){
            if( i == n-1 ){
                d = b[i] - a[i];
            }
            else{
                d = min( b[i] - a[i] , d + 1 + ( b[i] - b[i+1] ) );
            }

            sol = min( sol , d );
        }

        cout << "K prechodu reky je treba " << sol << " pontonu.\n";
    }
}
