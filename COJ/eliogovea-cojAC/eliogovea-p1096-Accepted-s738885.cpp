#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

int tc, n, m, l;
bool mark[10005];
vector<int> g[10005];
queue<int> q;

void bfs(int s) {
	mark[s] = true;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (!mark[v]) continue;
			mark[v] = true;
			q.push(v);
		}
	}
}

int main() {
	//freopen("dominoesII.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> l;
		for (int i = 1; i <= n; i++) {
			mark[i] = false;
			g[i].clear();
		}
		for (int i = 0, a, b; i < m; i++) {
			cin >> a >> b;
			g[a].push_back(b);
		}
		for (int i = 0, a; i < l; i++) {
			cin >> a;
			mark[a] = true;
			q.push(a);
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int j = 0; j < g[u].size(); j++) {
					int v = g[u][j];
					if (!mark[v]) {
						mark[v] = true;
						q.push(v);
					}
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (mark[i]) ans++;
		cout << ans << "\n";
	}
}
