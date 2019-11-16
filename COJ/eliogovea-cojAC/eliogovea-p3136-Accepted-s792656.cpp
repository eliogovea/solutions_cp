#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e9 + 7;

int t;
int n, m, p;
int s, e;
vector<int> ady[N], cost[N];
int par[N], distp[N];
int dist[N];
priority_queue<pair<int, int> > q;
bool used[N];
bool dp[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n >> m >> p;
		for (int i = 1; i <= n; i++) {
			ady[i].clear();
			cost[i].clear();
			dist[i] = inf;
			used[i] = false;
		}
		for (int i = 0; i <= p; i++) {
			dp[i] = false;
		}
		while (m--) {
			int x, y, z;
			cin >> x >> y >> z;
			ady[x].push_back(y);
			cost[x].push_back(z);
			ady[y].push_back(x);
			cost[y].push_back(z);
		}
		cin >> s >> e;
		dist[s] = 0;
		q.push(make_pair(0, s));
		while (!q.empty()) {
			int u = q.top().second;
			q.pop();
			if (used[u]) {
				continue;
			}
			used[u] = true;
			for (int i = 0; i < ady[u].size(); i++) {
				int v = ady[u][i];
				int c = cost[u][i];
				if (dist[v] > dist[u] + c) {
					dist[v] = dist[u] + c;
					par[v] = u;
					q.push(make_pair(-dist[v], v));
				}
			}
		}
		int time = dist[e];
		dp[0] = true;
		while (e != s) {
			int tmp = dist[e] - dist[par[e]];
			if (tmp <= p) {
				for (int i = p; i >= tmp; i--) {
					dp[i] |= dp[i - tmp];
				}
			}
			e = par[e];
		}
		int bst = 0;
		for (int i = 1; i <= p; i++) {
			if (dp[i]) {
				bst = i;
			}
		}
		cout << bst << " " << time + bst << "\n";
	}
}
