#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int N = 100005;

int n, ans;

struct pt {
	int x, y;
} P[N], aux;

bool operator < (const pt &a, const pt &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

map<pt, int> M;
map<pt, int>::iterator it;

vector<int> G[N];
int col[N], cnt[10];

void dfs(int u, int c) {
	col[u] = c;
	cnt[c]++;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (col[v] == -1)
			dfs(v, 1 - c);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> P[i].x >> P[i].y;
		M[P[i]] = i;
		col[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		for (long long dx = -5; dx <= 5; dx++)
			for (long long dy = -5; dy <= 5; dy++)
				if ((dx != 0LL || dy != 0LL) && dx * dx + dy * dy <= 25LL) {
					aux.x = P[i].x + dx;
					aux.y = P[i].y + dy;
					it = M.find(aux);
					if (it != M.end()) G[i].push_back(it->second);
				}
	}
	for (int i = 0; i < n; i++)
		if (col[i] == -1) {
			cnt[0] = cnt[1] = 0;
			dfs(i, 0);
			if (cnt[0] < cnt[1]) ans += cnt[0];
			else ans += cnt[1];
		}
	cout << ans << "\n";
}
