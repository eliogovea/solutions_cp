// 2016-2017 ACM-ICPC, Central Europe Regional Contest (CERC 16)
// 101173F

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int p[MAXN], h[MAXN];
int p2[MAXN], h2[MAXN];

int sol;
void free( int u ){
    if( p[u] ){
        free( p[u] );
        sol++;
    }

    h[ p[u] ] = 0;
    p[u] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	int n; cin >> n;

	for( int i = 1; i <= n; i++ ){
        cin >> p[i];
        h[ p[i] ] = i;
	}


	for( int i = 1; i <= n; i++ ){
        cin >> p2[i];
        h2[ p2[i] ] = i;
	}

	sol = 0;

	for( int i = 1; i <= n; i++ ){
        if( p[i] && p[i] != p2[i] ){
            free(i);
        }
	}

    for( int i = 1; i <= n; i++ ){
        if( p[i] != p2[i] ){
            free(p2[i]);

            p[i] = p2[i];
            h[ p[i] ] = i;
            sol++;
        }
    }

    cout << sol << '\n';
}
