#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int t;
int n;
double p[N][N];
double pi[N][N];

void invert(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pi[i][j] = 0.0;
		}
		pi[i][i] = 1.0;
	}
	for (int i = 0; i < n; i++) {
		int mx = i;
		for (int j = i + 1; j < n; j++) {
			if (abs(p[j][i]) > abs(p[mx][i])) {
				mx = j;
			}
		}
		for (int j = 0; j < n; j++) {
			swap(p[i][j], p[mx][j]);
			swap(pi[i][j], pi[mx][j]);
		}
		double tmp = p[i][i];
		for (int j = 0; j < n; j++) {
			p[i][j] /= tmp;
			pi[i][j] /= tmp;
		}
		for (int j = 0; j < n; j++) {
			if (i != j) {
				tmp = p[j][i];
				for (int k = 0; k < n; k++) {
					p[j][k] -= p[i][k] * tmp;
					pi[j][k] -= pi[i][k] * tmp;
				}
			}
		}
	}
}

void solve(int n, double pc) {
	for (int i = 0; i < 2 * n + 1; i++) {
		for (int j = 0; j < 2 * n + 1; j++) {
			p[i][j] = 0.0;
			pi[i][j] = 0.0;
		}
	}
	for (int i = 1; i < 2 * n; i++) {
		p[i][i] = 1.0;
		p[i][i - 1] = -(1.0 - pc);
		p[i][i + 1] = -pc;
	}
	p[0][0] = 1.0;
	p[2 * n][2 * n] = 1.0;
	invert(2 * n + 1);

	double e = 0.0;
	for (int i = 1; i < 2 * n; i++) {
		e += pi[n][i];
	}
	cout << fixed << e << " " << fixed << pi[n][2 * n] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(5);
	string a, b, c;
	int n;
	double pc;
	while (cin >> n >> pc) {
		solve(n, pc / 100.0);
	}
}
