// 2014-2015 CT S02E07: Codeforces Trainings Season 2 Episode 7
// 100523G

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

inline pair <int, int> nextZ(LL a, LL c, LL k, LL m, LL z) {
	LL nz = (((z * a + c) / k)) % m;
	return make_pair(nz >= m / 2LL, nz);
}

const int BASE1 = 37;
const int BASE2 = 41;

const int MOD1 = 1000000007;
const int MOD2 = 1000000047;

const int N = 1000005;

int H1[21][N];
int H2[21][N];
int pos[21][N];

int P1[N];
int P2[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int a, c, k, m, n;
	cin >> a >> c >> k >> m >> n;
	string s;
	cin >> s;
	P1[0] = 1;
	P2[0] = 1;
	for (int i = 1; i < N; i++) {
		P1[i] = (LL)P1[i - 1] * BASE1 % MOD1;
		P2[i] = (LL)P2[i - 1] * BASE2 % MOD2;
	}
	for (int r = 0; r < m; r++) {
		pair <int, int> p = nextZ(a, c, k, m, r);
		pos[0][r] = p.second;
		H1[0][r] = p.first;
		H2[0][r] = p.first;
	}
	for (int i = 1; i < 20; i++) {
		for (int r = 0; r < m; r++) {
			pos[i][r] = pos[i - 1][pos[i - 1][r]];
			H1[i][r] = (LL)H1[i - 1][r] * P1[1 << (i - 1)] % MOD1;
			H1[i][r] = (LL)(H1[i][r] + H1[i - 1][pos[i - 1][r]]) % MOD1;
			H2[i][r] = (LL)H2[i - 1][r] * P2[1 << (i - 1)] % MOD2;
			H2[i][r] = (LL)(H2[i][r] + H2[i - 1][pos[i - 1][r]]) % MOD2;
		}
	}
	int hs1 = 0;
	int hs2 = 0;
	for (int i = 0; i < n; i++) {
		hs1 = (LL)hs1 * BASE1 % MOD1;
		hs1 = (LL)(hs1 + s[i] - '0') % MOD1;
		hs2 = (LL)hs2 * BASE2 % MOD2;
		hs2 = (LL)(hs2 + s[i] - '0') % MOD2;
	}
	int ans = 0;
	for (int r = 0; r < m; r++) {
		int h1 = 0;
		int h2 = 0;
		int p = r;
		for (int i = 0; (1 << i) <= n; i++) {
			if (n & (1 << i)) {
				h1 = (LL)h1 * P1[1 << i] % MOD1;
				h1 = (LL)(h1 + H1[i][p]) % MOD1;
				h2 = (LL)h2 * P2[1 << i] % MOD2;
				h2 = (LL)(h2 + H2[i][p]) % MOD2;
				p = pos[i][p];
			}
		}
		if (h1 == hs1 && h2 == hs2) {
			ans++;
		}
	}
	cout << ans << "\n";
}
