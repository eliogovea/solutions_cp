#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 20000 + 10;

int n, m;
vector <int> g[N];
int timer;
int low[N];
int dfs_num[N];
int st[N], top;
int scc_count;
int id[N];

void dfs(int u) {
    // cerr << "-->> " << u << "\n";
	low[u] = dfs_num[u] = timer++;
	st[top++] = u;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		// cerr << u << " >> " << v << "\n";
		if (dfs_num[v] == -1) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (id[v] == -1) {
			low[u] = min(low[u], dfs_num[v]);
		}
	}
	// cerr << u << " " << dfs_num[u] << " " << low[u] << "\n";
	if (dfs_num[u] == low[u]) {
        while (st[top - 1] != u) {
            id[st[top - 1]] = scc_count;
            top--;
        }
        id[st[top - 1]] = scc_count;
        top--;
        scc_count++;
    }
}

inline void SCC() {
	for (int i = 1; i <= 2 * n; i++) {
		id[i] = -1;
		dfs_num[i] = -1;
		low[i] = -1;
	}
	timer = 0;
	scc_count = 0;
	top = 0;
	for (int i = 1; i <= 2 * n; i++) {
        if (dfs_num[i] == -1) {
            dfs(i);
            // cerr << "-------------------\n";
        }
	}
}
inline void get(const string &s, char &c, int &x) {
	c = s[0];
	x = 0;
	for (int i = 1; i < s.size(); i++) {
		x = 10 * x + s[i] - '0';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	string s;
	for (int i = 0; i < m; i++) {
		char ox;
		int x;
		cin >> s;
		get(s, ox, x);
		char oy;
		int y;
		cin >> s;
		get(s, oy, y);
		// cerr << ox << " " << x << " " << oy << " " << y << "\n";
		if (ox == '+' && oy == '+') {
			g[n + x].push_back(y);
			g[n + y].push_back(x);
		} else if (ox == '+' && oy == '-') {
			g[n + x].push_back(n + y);
			g[y].push_back(x);
		} else if (ox == '-' && oy == '+') {
			g[x].push_back(y);
			g[n + y].push_back(n + x);
		} else {
			g[x].push_back(n + y);
			g[y].push_back(n + x);
		}
	}

	SCC();

	for (int i = 1; i <= n; i++) {
		if (id[i] == id[n + i]) {
            cerr << i << " " << id[i] << " " << id[n + i] << "\n";
			cout << "0\n";
			return 0;
		}
	}
	cout << "1\n";
}
