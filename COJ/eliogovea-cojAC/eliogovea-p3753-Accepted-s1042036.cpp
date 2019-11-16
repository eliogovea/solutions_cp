#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int dp[N][1 << N];

int ans[N][N];

inline int getX(int pos, int n, int m) {
	return pos / n;
}

inline int getY(int pos, int n, int m) {
	return pos % n;
}

inline int getPos(int x, int y, int n, int m) {
	return x * n + y;
}

int solve(int n, int m) {
	if (n > m) {
		swap(n, m);
	}
	if (ans[n][m] != -1) {
		return ans[n][m];
	}
	int t = n * m;
	for (int pos = 0; pos < t; pos++) {
		for (int mask = 0; mask < (1 << t); mask++) {
			dp[pos][mask] = 0;
		}
	}
	for (int pos = 0; pos < t; pos++) {
		dp[pos][1 << pos] = 1;
	}
	ans[n][m] = 0;
	for (int mask = 0; mask < (1 << t); mask++) {
		for (int pos = 0; pos < t; pos++) {
			if (mask & (1 << pos)) {
				if (dp[pos][mask]) {
					ans[n][m] += dp[pos][mask];
					int xp = getX(pos, n, m);
					int yp = getY(pos, n, m);
					for (int next = 0; next < t; next++) {
						if (!(mask & (1 << next))) {
							int xn = getX(next, n, m);
							int yn = getY(next, n, m);
							int dx = xn - xp;
							int dy = yn - yp;
							int g = __gcd(abs(dx), abs(dy));
							dx /= g;
							dy /= g;
							bool ok = true;
							for (int i = 1; i < g; i++) {
								int pp = getPos(xp + dx * i, yp + dy * i, n, m);
								if (!(mask & (1 << pp))) {
									ok = false;
									break;
								}
							}
							if (ok) {
								dp[next][mask | (1 << next)] += dp[pos][mask];
							}
						}
					}
				}
			}
		}
	}
	return ans[n][m];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			ans[i][j] = -1;
		}
	}


	int cas = 1;
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		cout << "Case #" << cas++ << ": " << solve(n, m) << "\n";
	}
}
