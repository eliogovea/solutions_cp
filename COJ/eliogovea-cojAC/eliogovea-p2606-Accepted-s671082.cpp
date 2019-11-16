#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 105;

int n, hor[MAXN][MAXN], ver[MAXN][MAXN];
string s[MAXN];
vector<int> G[MAXN * MAXN];
int match[MAXN * MAXN];
int used[MAXN * MAXN], mk;

bool kuhn(int u) {
	if (used[u] == mk) return false;
	used[u] = mk;
	for (int i = 0; i < G[u].size(); i++) {
		int to = G[u][i];
		if (match[to] == -1 || kuhn(match[to])) {
			match[to] = u;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	int id = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (s[i][j] == 'X') id++;
			else hor[i][j] = id;
		id++;
	}
	int cnt = id;
	id = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (s[j][i] == 'X') id++;
			else ver[j][i] = id;
		id++;
	}
	for (int i = 0; i < id; i++) match[i] = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (s[i][j] == '.')
				G[hor[i][j]].push_back(ver[i][j]);
	int ans = 0;
	for (int i = 0; i < cnt; i++)
		if (G[i].size()) {
			mk++;
			if (kuhn(i)) ans++;
		}
	cout << ans << "\n";
}
