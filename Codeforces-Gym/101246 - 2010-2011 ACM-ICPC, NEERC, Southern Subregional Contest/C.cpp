// 2010-2011 ACM-ICPC, NEERC, Southern Subregional Contest
// 101246C

#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int n, m;
string s[35];

int maskX[(1 << N) + 1];
int maskY[N + 5];
int bits[(1 << N) + 1];

map <int, int> pos;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		maskY[i] = 0;
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '*') {
				maskY[i] |= (1 << j);
			}
		}
		//cerr << i << " " << maskY[i] << "\n";
	}

	for (int i = 0; i < n; i++) {
		pos[1 << i] = i;
	}
    bits[0] = 0;
    maskX[0] = 0;
	for (int i = 1; i < (1 << n); i++) {
		maskX[i] = maskX[i ^ (i & -i)] | maskY[pos[i & -i]];
		//cerr << "mask " << i << " " << maskX[i] << "\n";
	}
	for (int i = 1; i < max((1 << n), (1 << m)); i++) {
        bits[i] = bits[i ^ (i & -i)] + 1;
	}
	int all = (1 << n) - 1;
	int ans = min(n, m);
	for (int i = 0; i < (1 << n); i++) {
        //cerr << i << " " << (all ^ i) << " " << bits[i] << " " <<  bits[maskX[all ^ i]] << "\n";
		ans = min(ans, max(bits[i], bits[maskX[all ^ i]]));
	}
	cout << ans << "\n";
}
