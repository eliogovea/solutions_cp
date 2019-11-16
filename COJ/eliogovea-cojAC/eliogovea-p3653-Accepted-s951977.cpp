#include <bits/stdc++.h>

using namespace std;

const int N = 300;

int n;
int X1[N], X2[N], Y1[N], Y2[N];

inline bool inter(int a, int b) {
	return (X1[a] <= X1[b] && X1[b] <= X2[a] && Y1[b] <= Y1[a] && Y1[a] <= Y2[b]);
}

vector <int> g[N];

int used[N], id;
int match[N];

bool dfs(int u) {
	if (used[u] == id) {
		return false;
	}
	used[u] = id;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (match[v] == -1 || dfs(match[v])) {
			match[v] = u;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
		if (X1[i] > X2[i]) {
			swap(X1[i], X2[i]);
		}
		if (Y1[i] > Y2[i]) {
			swap(Y1[i], Y2[i]);
		}
	}
	for (int i = 0; i < n; i++) {
        match[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		int hor = (Y1[i] == Y2[i]);
		if (hor) {
			for (int j = 0; j < n; j++) {
				int ver = (X1[j] == X2[j]);
				if (ver) {
					if (inter(i, j)) {
						g[i].push_back(j);
					}
				}
			}
		}
	}
	int ans = n;
	for (int i = 0; i < n; i++) {
		int hor = (Y1[i] == Y2[i]);
		if (hor) {
			id++;
			if (dfs(i)) {
				ans--;
			}
		}
	}
	cout << ans << "\n";
}
