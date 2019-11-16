// 2015 USP Try-outs
// 101047L

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int tc;
	cin >> tc;
	int n, m;

    while( tc-- ){
        cin >> n >> m;
        ll sol = 1ll;

        if( n == 0 && m == 0 ){
            cout << "0\n";
            continue;
        }

        for( int i = 1; i <= max( n , m ); i++ ){
            if( i <= n ){
                sol *= 26ll;
            }
            if( i <= m ){
                sol *= 10ll;
            }
        }

        cout << sol << '\n';
    }
}
