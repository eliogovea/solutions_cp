#include <bits/stdc++.h>

using namespace std;

const int N = 4 * 100 * 1000 + 10;

int n;
int x[N], y[N];
int xx[N], yy[N];

bool cmp_x(int a, int b) {
	return x[a] < x[b];
}

bool cmp_xx(int a, int b) {
	return xx[a] < xx[b];
}

bool cmp_y(int a, int b) {
	return y[a] < y[b];
}

int arr[N];
vector <int> g[N];

int timer;
int low[N];
int dfs_num[N];
int st[N], top;
int id[N];
int scc_count;
int scc_size[N];

vector <int> scc_g[N];

void dfs(int u) {
	low[u] = dfs_num[u] = timer++;
	st[top++] = u;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (dfs_num[v] == -1) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (id[v] == -1) {
			low[u] = min(low[u], dfs_num[v]);
		}
	}
	// cerr << u << " " << dfs_num[u] << " " << low[u] << "\n";
	if (dfs_num[u] == low[u]) {
        xx[scc_count] = x[u];
        yy[scc_count] = y[u];
        while (st[top - 1] != u) {
            id[st[top - 1]] = scc_count;
            scc_size[scc_count]++;
            top--;
        }
        id[st[top - 1]] = scc_count;
        scc_size[scc_count]++;
        top--;
        scc_count++;
    }
}

inline void SCC() {
	for (int i = 0; i < n; i++) {
		id[i] = -1;
		dfs_num[i] = -1;
		low[i] = -1;
	}
	timer = 0;
	scc_count = 0;
	top = 0;
	for (int i = 0; i < n; i++) {
        if (dfs_num[i] == -1) {
            dfs(i);
        }
	}
}

int val[N];

int calc(int u) {
	if (val[u] != -1) {
		return val[u];
	}
	int res = scc_size[u];
	for (int i = 0; i < scc_g[u].size(); i++) {
		int v = scc_g[u][i];
		res += calc(v);
	}
	val[u] = res;
	return res;
}

set <pair <int, int> > S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	sort(arr, arr + n, cmp_x);
	for (int i = n - 1; i > 0; i--) {
		g[arr[i]].push_back(arr[i - 1]);
		// cerr << arr[i] << " -> " << arr[i - 1] << "\n";
	}

	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	sort(arr, arr + n, cmp_y);
	for (int i = n - 1; i > 0; i--) {
		g[arr[i]].push_back(arr[i - 1]);
		// cerr << arr[i] << " -> " << arr[i - 1] << "\n";
	}

	SCC();

	// cerr << scc_count << "\n";
	// for (int i = 0; i < n; i++) {
        // cerr << id[i] << "\n";
	// }
	// cerr << "\n\n";
	// for (int i = 0; i < scc_count; i++) {
        // cerr << scc_size[i] << " ";
	// }
	// cerr << "\n";
	// return 0;

	for (int i = 0; i < scc_count; i++) {
        arr[i] = i;
	}

	sort(arr, arr + scc_count, cmp_xx);

    val[ arr[0] ] = scc_size[ arr[0] ];
    for (int i = 1; i < scc_count; i++) {
        val[ arr[i] ] = val[ arr[i - 1] ] + scc_size[ arr[i] ];
    }
	// for (int u = 0; u < n; u++) {
		// for (int j = 0; j < g[u].size(); j++) {
			// int v = g[u][j];
			// if (id[u] != id[v] && S.find(make_pair(id[i], id[v])) == S.end()) {
                // S.insert(make_pair(id[u], id[v]));
				// scc_g[id[u]].push_back(id[v]);
			// }
		// }
	// }

	for (int i = 0; i < n; i++) {
		cout << val[id[i]] - 1 << "\n";
	}
}
