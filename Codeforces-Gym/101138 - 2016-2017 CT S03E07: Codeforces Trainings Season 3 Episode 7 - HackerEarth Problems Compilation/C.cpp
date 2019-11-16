// 2016-2017 CT S03E07: Codeforces Trainings Season 3 Episode 7 - HackerEarth Problems Compilation
// 101138C

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

inline int power(int x, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		n >>= 1;
	}
	return res;
}

const int INV2 = power(2, MOD - 2);
const int INV6 = power(6, MOD - 2);

inline int nC3(long long n) {
	return mul(n, mul(n - 1, mul(n - 2, INV6)));
}

inline long long nC2(long long n) {
	return mul(n, mul(n - 1, INV2));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <vector <bool> > G(n, vector <bool> (n, 0));
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a][b] = G[b][a] = true;
	}
	int ans = 0;
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			if (a != b && G[a][b]) {
				int sa = 0;
				int sb = 0;
				int sc = 0;
				for (int x = 0; x < n; x++) {
					if (x != a && x != b) {
						if (G[a][x] && !G[b][x]) {
							sa++;
						} else if (!G[a][x] && G[b][x]) {
							sb++;
						} else if (G[a][x] && G[b][x]) {
							sc++;
						}
					}
				}
				//cerr << a << " " << b << " " << sa << " " << sb << " " << sc << " " << ans << "\n";
				if (sb >= 2 && sc + sa >= 3) {
					add(ans, mul(nC3(sc + sa), nC2(sb)));
				}
				if (sc >= 1 && sb >= 1 && sc + sa - 1 >= 3) {
					add(ans, mul(sc, mul(sb, nC3(sc - 1 + sa))));
				}
				if (sc >= 2 && sc - 2 + sa >= 3) {
					add(ans, mul(nC2(sc), nC3(sc - 2 + sa)));
				}
				//cerr << a << " " << b << " " << sa << " " << sb << " " << sc << " " << ans << "\n";
			}
		}
	}
	cout << ans << "\n";
}
