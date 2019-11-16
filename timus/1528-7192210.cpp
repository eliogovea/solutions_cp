// Problem: pace=1&num=1528
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 10005;

LL n, p;
LL f[N], g[N], sg[N], fg[N], sfg[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true) {
		cin >> n >> p;
		if (n == 0 && p == 0) {
			break;
		}
		f[1] = 1;
		g[1] = 1;
		sg[1] = 1;
		fg[1] = 1;
		sfg[1] = 1;
		for (int i = 2; i <= n ; i++) {
			f[i] = 1 + sfg[i - 1];
			if (f[i] >= p) {
				f[i] -= p;
			}
			g[i] = (1 + 2LL * sg[i - 1] + (p - (g[i - 1] * g[i - 1] % p))) % p;
			fg[i] = f[i] * g[i] % p;
			sg[i] = sg[i - 1] + g[i];
			if (sg[i] >= p) {
				sg[i] -= p;
			}
			sfg[i] = sfg[i - 1] + fg[i];
			if (sfg[i] >= p) {
				sfg[i] -= p;
			}
		}
		cout << f[n] << "\n";
	}
}
