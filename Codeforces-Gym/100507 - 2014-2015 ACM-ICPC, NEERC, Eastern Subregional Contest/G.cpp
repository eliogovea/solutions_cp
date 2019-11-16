// 2014-2015 ACM-ICPC, NEERC, Eastern Subregional Contest
// 100507G

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	vector <int> fa(n + 1, 0), fb(n + 1, 0);
	fa[0] = 1;
	fb[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = max(i - a, 0); j < i; j++) {
			add(fa[i], fb[j]);
		}
		for (int j = max(i - b, 0); j < i; j++) {
			add(fb[i], fa[j]);
		}
	}
	int ans = fa[n];
	add(ans, fb[n]);
	cout << ans << "\n";
}
