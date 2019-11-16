#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

const int N = 30;

int t;
int n;
LD pf, pb;

LD p[N][N];
LD pi[N][N];

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
		LD tmp = p[i][i];
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
	cout.precision(17);
	cin >> t;
	while (t--) {
		cin >> n >> pf >> pb;
		pf /= 100.0;
		pb /= 100.0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				p[i][j] = 0.0;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				p[i][i] = pb + (1.0 - pf - pb);
				p[i][i + 1] = pf;
			} else if (i < n) {
				p[i][i - 1] = pb;
				p[i][i] = 1.0 - pf - pb;
				p[i][i + 1] = pf;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				p[i][j] = -p[i][j];
			}
			p[i][i] += 1.0;
		}
		invert();
		LD ans = 0.0;
		for (int i = 1; i < n; i++) {
			ans += pi[1][i];
		}
		cout << fixed << ans << "\n";
	}
}
