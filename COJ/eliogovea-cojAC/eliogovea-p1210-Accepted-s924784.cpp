#include <bits/stdc++.h>

using namespace std;

const int N = 1005, M = 100005, INF = 1e7;

int ady[M], cap[M], flow[M], next[M], last[N], now[N];
int E;
int source, sink;

inline void add(int a, int b, int c) {
	ady[E] = b; cap[E] = c; flow[E] = 0; next[E] = last[a]; last[a] = E++;
	ady[E] = a; cap[E] = 0; flow[E] = 0; next[E] = last[b]; last[b] = E++;
}

int Q[N], qh, qt;

int total;

int lev[N];

bool bfs() {
	for (int i = 0; i < total; i++) {
		lev[i] = -1;
	}
	qh = qt = 0;
	Q[qt++] = source;
	lev[source] = 0;
	while (qh != qt) {
		int u = Q[qh++];
		for (int e = last[u]; e != -1; e = next[e]) {
			if (cap[e] > flow[e]) {
				int v = ady[e];
				if (lev[v] == -1) {
					lev[v] = lev[u] + 1;
					Q[qt++] = v;
				}
			}
		}
	}
	return (lev[sink] != -1);
}

int dfs(int u, int f) {
	if (u == sink) {
		return f;
	}
	for (int e = now[u]; e != -1; e = now[u] = next[e]) {
		if (cap[e] > flow[e]) {
			int v = ady[e];
			if (lev[v] == lev[u] + 1) {
				int push = dfs(v, min(f, cap[e] - flow[e]));
				if (push > 0) {
					flow[e] += push;
					flow[e ^ 1] -= push;
					return push;
				}
			}
		}
	}
	return 0;
}

int maxFlow() {
	int res = 0;
	while (bfs()) {
		for (int i = 0; i < total; i++) {
			now[i] = last[i];
		}
		while (true) {
			int tmp = dfs(source, INF);
			if (tmp == 0) {
				break;
			}
			res += tmp;
		}
	}
	return res;
}
int n, m, g;

int p[N];
int vs[N][N];
int idvs[N][N];
int ide[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	while (cin >> n >> m >> g) {
		if (n == 0 && m == 0 && g == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			p[i] = 0;
			for (int j = i + 1; j < n; j++) {
				vs[i][j] = 0;
			}
		}
		while (g--) {
			int a, b;
			char ch;
			cin >> a >> ch >> b;
			if (ch == '=') {
				p[a]++;
				p[b]++;
			} else {
				p[b] += 2;
			}
			if (a > b) {
				swap(a, b);
			}
			vs[a][b]++;
		}


		int T = m * (n - 1);
		for (int i = 1; i < n; i++) {
			T -= vs[0][i];
		}
		int mx = p[0] + 2 * T;

		total = 0;
		for (int i = 1; i < n; i++) {
			ide[i] = total++;
		}
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				idvs[i][j] = total++;
			}
		}
		source = total++;
		sink = total++;
		E = 0;
		for (int i = 0; i < total; i++) {
			last[i] = -1;
		}
		int x = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				x += 2 * (m - vs[i][j]);
				add(source, idvs[i][j], 2 * (m - vs[i][j]));
				add(idvs[i][j], ide[i], INF);
				add(idvs[i][j], ide[j], INF);
			}
		}
		bool ok = true;
		for (int i = 1; i < n; i++) {
            if (mx - 1 - p[i] < 0) {
                ok = false;
                break;
            }
			add(ide[i], sink, mx - 1 - p[i]);
		}
		if (!ok) {
            cout << "N\n";
            continue;
		}
		int ans = maxFlow();
		//cout << ans << "\n";
		if (ans == x) {
			cout << "Y\n";
		} else {
			cout << "N\n";
		}
	}
}
