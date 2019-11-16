// 2016-2017 ACM-ICPC East Central North America Regional Contest (ECNA 2016)
// 101196G

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool ok = false;
int cdi[60];

ll sol = 0;

ll pow2[60];

void solve( int n, int a, int b, int c ){
    if( n == 0 ){
        ok = true;
        return;
    }

    int l = cdi[n];

    if( l == b ){
        return;
    }

    if( l == a ){
        sol += pow2[n-1];
        solve( n-1 , a , c , b );
    }
    else{
        solve( n-1 , b , a , c );
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);

    pow2[0] = 1;

    for( int i = 1; i <= 50; i++ ){
        pow2[i] = pow2[i-1] * 2ll;
    }

    int n = 0;

	for( int l = 1; l <= 3; l++ ){
        int m; cin >> m;
        for( int j = 0; j < m; j++ ){
            int x; cin >> x;
            cdi[x] = l;
        }

        n += m;
	}

	solve(n,1,2,3);
	if( ok ){
        cout << sol << '\n';
	}
	else{
        cout << "No\n";
	}
}
