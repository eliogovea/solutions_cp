// 2014-2015 ACM-ICPC, NEERC, Southern Subregional Contest
// 100513F

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200100;
int s[MAXN];

int mx[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	int n, k; cin >> n >> k;

    int sol = 0;

    for( int i = 1; i <= n; i++ ){
        cin >> s[i];
        s[i] += s[i-1];

        sol = max( sol , s[i] - s[ max( i-k, 0 ) ] + mx[ max( i - k , 0 ) ] );
        mx[i] = max( s[i] - s[max( i-k , 0 )] , mx[i-1] );
    }

    cout << sol << '\n';
}
