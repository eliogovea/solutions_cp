// Problem: pace=1&num=1080
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 150;

int n;
vector <int> g[N];
int color[N];

bool dfs(int u, int c) {
	color[u] = c;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (color[v] != -1) {
			if (color[v] == c) {
				return false;
			}
		} else {
			if (!dfs(v, 1 - c)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		while (cin >> x && x != 0) {
			g[i].push_back(x - 1);
			g[x - 1].push_back(i);
		}
	}
	
	for (int i = 0; i < n; i++) {
		color[i] = -1;
	}
	
	if (!dfs(0, 0)) {
		cout << "-1\n";
	} else {
		for (int i = 0; i < n; i++) {
			cout << color[i];
		}
		cout << "\n";
	}
}