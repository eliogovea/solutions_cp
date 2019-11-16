#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int MAXN = 105;

int n, q;
vector<int> G[MAXN];
int mark[MAXN];

void upd(int u) {
	mark[u] ^= 1;
	for (int i = 0; i < G[u].size(); i++) upd(G[u][i]);
}

int col(int u) {
	int r = mark[u];
	for (int i = 0; i < G[u].size(); i++)
		r += col(G[u][i]);
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	while (cin >> n >> q) {
		for (int i = 0; i < n; i++) G[i].clear(), mark[i] = 0;
		for (int i = 1, x, y; i < n; i++) {
			cin >> x >> y;
			G[x].push_back(y);
		}
		for (int i = 0, a, b; i < q; i++) {
			cin >> a >> b;
			if (a == 0) upd(b);
			else cout << col(b) << '\n';
		}
	}
}
