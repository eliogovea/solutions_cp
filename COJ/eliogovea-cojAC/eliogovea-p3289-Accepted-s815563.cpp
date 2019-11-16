#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int t;

int n, m, r;
map<pair<int, int>, int> edges;
map<pair<int, int>, int>::iterator it;

vector<pair<int, int> > g[N];
int c[N];

bool mark[N];

int dfs(int u) {
	int res = 1;
	mark[u] = true;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].first;
		c[v]++;
		if (!mark[v]) {
			res += dfs(v);
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n >> m >> r;
		edges.clear();
		int u, v, w;
		while (m--) {
			cin >> u >> v >> w;
			it = edges.find(make_pair(u, v));
			if (it == edges.end()) {
				edges[make_pair(u, v)] = w;
			} else if (it->second > w) {
				it->second = w;
			}
		}
		if (edges.size() < n - 1) {
			cout << "impossible\n";
			continue;
		}
		for (int i = 0; i < n; i++) {
			mark[i] = false;
			g[i].clear();
			c[i] = 0;
		}
		int sum = 0;
		for (it = edges.begin(); it != edges.end(); it++) {
			u = it->first.first;
			v = it->first.second;
			w = it->second;
			sum += w;
			g[u].push_back(make_pair(v, w));
			//g[v].push_back(make_pair(u, w));
		}
		int cnt = dfs(r);
		if (cnt != n) {
			cout << "impossible\n";
			continue;
		}
		if (edges.size() == n - 1) {
			cout << sum << "\n";
			for (it = edges.begin(); it != edges.end(); it++) {
                cout << it->first.first << " " << it->first.second << " " << it->second << "\n";
			}
			continue;
		} else {
			int mx = 0;
			int a = -1;
			int b = -1;
			for (it = edges.begin(); it != edges.end(); it++) {
				u = it->first.first;
				v = it->first.second;
				w = it->second;
				if (c[v] > 1) {
					if (w > mx) {
						a = u;
						b = v;
						mx = w;
					}
				}
			}
			cout << sum - mx << "\n";;
			for (it = edges.begin(); it != edges.end(); it++) {
				u = it->first.first;
				v = it->first.second;
				w = it->second;
				if (u == a && v == b) {
					continue;
				}
				cout << u << " " << v << " " << w << "\n";
			}
		}
	}
}
