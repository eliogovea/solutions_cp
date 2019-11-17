// Problem: pace=1&num=1039
// Verdict: Accepted

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

const int N = 6005;

int n, a[N];
vector<int> g[N];
int dp[3][N];
int p[N];

int solve(int u, bool x) {
	if (dp[x][u] != 1e9) {
		return dp[x][u];
	}
	int res = 0;
	if (x) {
		res += a[u];
	}
	for (int i = 0; i < g[u].size(); i++) {
		int tmp1 = solve(g[u][i], !x);
		if (!x) {
			int tmp2 = solve(g[u][i], x);
			if (tmp2 > tmp1) {
				tmp1 = tmp2;
			}
		}
		res += tmp1;
	}
	dp[x][u] = res;
	return res;
}


int main() {
	//freopen("data.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		dp[0][i] = dp[1][i] = 1e9;
	}
	int x, y;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &x, &y);
		g[y].push_back(x);
		p[x] = y;

	}
	scanf("%d %d", &x, &y);
	assert(x == 0 && y == 0);
	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i] == 0) {
			root = i;
			break;
		}
	}
	int ans = max(solve(root, 0), solve(root, 1));
	printf("%d\n", ans);
}
