#include <iostream>
#include <vector>

using namespace std;

const int N = 205;

int n, m, col[N];
vector<int> g[N];

bool ans;

void check(int u, int c) {
	if (ans == false) return;
	col[u] = c;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (col[v] == c) {
			ans = false;
			break;
		} else if (col[v] == -1) {
			check(v, 1 - c);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n && n) {
		cin >> m;
		ans = true;
		for (int i = 0; i < n; i++) {
			g[i].clear();
			col[i] = -1;
		}
		for (int i = 0, a, b; i < m; i++) {
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		check(0, 0);
		if (ans) cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
	}
}
