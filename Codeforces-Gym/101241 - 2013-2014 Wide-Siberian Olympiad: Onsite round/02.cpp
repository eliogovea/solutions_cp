// 2013-2014 Wide-Siberian Olympiad: Onsite round
// 10124102

#include <bits/stdc++.h>

using namespace std;

int n, g;
vector <int> adj[100005];

int depth[100005];

void dfs(int u, int p, int d) {
	depth[u] = d;
	// cerr << "dfs " << u + 1 << " " << p + 1 << " " << d << "\n";
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != p) {
			dfs(v, u, d + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> g;
	g--;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		for (int j = 0; j < c; j++) {
			int x;
			cin >> x;
			x--;
			adj[i].push_back(x);
		}
	}

	for (int i = 0; i < n; i++) {
		depth[i] = -1;
	}

	dfs(g, -1, 0);

	vector <int> end;
	for (int i = 0; i < n; i++) {
		if (adj[i].size() <= 1) {
			end.push_back(i);
			// cerr << "end " << i + 1 << "\n";
		}
	}

	for (int i = 0; i < end.size(); i++) {
		if (depth[end[i]] == -1) {
			cout << "-\n";
		} else if (depth[end[i]] & 1) {
			cout << "CCW\n";
		} else {
			cout << "CW\n";
		}
	}
}
