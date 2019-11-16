#include <bits/stdc++.h>

using namespace std;

const int N = 150;

int w, h, s;

int n;

int par[N];

double p[N][N];
double pi[N][N];

void invert() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
                pi[i][j] = 1.0;
			} else {
                pi[i][j] = 0.0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int mx = i;
		for (int j = i + 1; j <= n; j++) {
			if (abs(p[j][i]) > abs(p[mx][i])) {
				mx = j;
			}
		}
		for (int j = 1; j <= n; j++) {
			swap(p[i][j], p[mx][j]);
			swap(pi[i][j], pi[mx][j]);
		}
		double tmp = p[i][i];
		for (int j = 1; j <= n; j++) {
			p[i][j] /= tmp;
			pi[i][j] /= tmp;
		}
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			tmp = p[j][i];
			for (int k = 1; k <= n; k++) {
				p[j][k] -= p[i][k] * tmp;
				pi[j][k] -= pi[i][k] * tmp;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cout.precision(9);
	while (cin >> w >> h >> s) {
		n = h * w;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				p[i][j] = 0.0;
			}
		}
		for (int i = 1; i <= n; i++) {
			par[i] = i;
		}
		int u, v;
		while (s--) {
			cin >> u >> v;
			par[u] = v;
		}
		for (int i = 1; i < n; i++) {
			if (i != par[i]) {
				continue;
			}
			for (int j = 1; j <= 6; j++) {
				int cur = i;
				int dir = 1;
				for (int k = 1; k <= j; k++) {
                    if (cur == n) {
                        dir = -1;
                    }
                    if (cur == 1) {
                        dir = 1;
                    }
                    cur += dir;
				}
				int next = par[cur];
				p[i][next] += 1.0 / 6.0;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				p[i][j] = -p[i][j];
				if (j == i) {
					p[i][j] += 1.0;
				}
			}
		}
		invert();
		double ans = 0;
		for (int i = 1; i < n; i++) {
			ans += pi[1][i];
		}
		cout << fixed << ans << "\n";
	}
}
