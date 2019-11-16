#include <cstdio>
#include <vector>
using namespace std;

int n, a[(1 << 10) + 5], ind = 1;
vector<int> level[15];

void dfs(int u, int lev) {
	if (lev > n) return;
	dfs(2 * u, lev + 1);
	level[lev].push_back(a[ind++]);
	dfs(2 * u + 1, lev + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < (1 << n); i++) scanf("%d", a + i);
	dfs(1, 1);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < level[i].size(); j++)
			printf("%d%c", level[i][j], (j < (int)level[i].size() - 1) ? ' ' : '\n');
}
