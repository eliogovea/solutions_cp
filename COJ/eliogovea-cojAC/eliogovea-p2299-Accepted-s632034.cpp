#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005, inf = 1 << 29;

int f, s, g, u, d, dp[MAXN];
queue<int> Q;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> f >> s >> g >> u >> d;
	for (int i = 1; i <= f; i++)
		dp[i] = inf;
	dp[s] = 0;
	Q.push(s);
	while (!Q.empty()) {
		int a = Q.front();
		Q.pop();
		if (a + u <= f && dp[a + u] > dp[a] + 1) {
			dp[a + u] = dp[a] + 1;
			Q.push(a + u);
		}
		if (a - d >= 1 && dp[a - d] > dp[a] + 1) {
			dp[a - d] = dp[a] + 1;
			Q.push(a - d);
		}
	}
	if (dp[g] == inf) cout << "use the stairs\n";
	else cout << dp[g] << '\n';
}
