#include <bits/stdc++.h>

using namespace std;

const int N = 10 * 1000;

const int V[4][4] = {
	{1, 8, 4, 3},
	{0, 4, 7, 7},
	{0, 5, 6, 6},
	{0, 9, 1, 0}
};

const int LN = 64;

int go[LN + 1][N + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int x = 0; x < N; x++) {
		int v[] = {x / 1000, (x / 100) % 10, (x / 10) % 10, x % 10};
		int nv[] = {0, 0, 0, 0};
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				nv[i] = (nv[i] + V[i][j] * v[j]) % 10;
			}
		}
		go[0][x] = 1000 * nv[0] + 100 * nv[1] + 10 * nv[2] + nv[3];
	}
	for (int i = 1; i < LN; i++) {
		for (int x = 0; x < N; x++) {
			go[i][x] = go[i - 1][go[i - 1][x]];
		}
	}
	
	int t;
	cin >> t;
	while (t--) {
		unsigned long long n;
		int a, b, c;
		cin >> n >> a >> b >> c;
		int cur = 100 * a + 10 * b + c;
		for (int i = 0; i < LN && (1ULL << i) <= n; i++) {
			if (n & (1ULL << i)) {
				cur = go[i][cur];
			}
		}
		cout << cur / 1000 << "\n";
	}
}
