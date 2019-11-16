#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 505;

int n, a, b;
string ph[MAXN];
vector<int> G[MAXN];
int mark[MAXN];

void dfs(int s, int u) {
	mark[u] = s;
	for (vector<int>::iterator it = G[u].begin(); it != G[u].end(); it++)
		if (!mark[*it]) dfs(s, *it);
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ph[i];
	while (cin >> a >> b) {
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		if (!mark[i] && ph[i][0] != '0')
			dfs(i, i);
	for (int i = 1; i <= n; i++)
		cout << ph[mark[i]] << '\n';
}
