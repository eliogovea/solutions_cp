#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int MAXN = 500;

int n;
vector<int> G[MAXN + 5];
bool mark_x[MAXN + 5], mark_y[MAXN + 5], used_x[MAXN];
int match[MAXN + 5];

bool kuhn(int u) {
	if (used_x[u]) return false;
	used_x[u] = true;
	for (int i = 0; i < G[u].size(); i++) {
		int to = G[u][i];
		if (match[to] == 0 || kuhn(match[to])) {
			match[to] = u;
			return true;
		}
	}
	return false;
}

bool solve() {
	for (int i = 1; i <= MAXN; i++)
    if (mark_x[i]) {
      for (int j = 1; j <= MAXN; j++) used_x[i] = false;
      if (!kuhn(i)) return false;
	}
	for (int i = 1; i <= MAXN; i++)
		if (mark_y[i] && !match[i]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("e.in", "r", stdin);
	cin >> n;
	for (int x, y; n--;) {
		cin >> x >> y;
		G[x].push_back(y);
		mark_x[x] = mark_y[y] = true;
	}
	if (solve()) cout << "Slavko\n";
	else cout << "Mirko\n";
}
