#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAXN = 60, MAXM = 1005;

int n, ady[MAXM], cap[MAXM], flow[MAXM], next[MAXM], last[MAXN], E;
int used[MAXN], id;
string s1, s2;
int source, sink;

inline void add(int a, int b) {
	ady[E] = b; cap[E] = 1; flow[E] = 0; next[E] = last[a]; last[a] = E++;
	ady[E] = a; cap[E] = 0; flow[E] = 0; next[E] = last[b]; last[b] = E++;
}

int dfs(int u, int cur) {
	if (u == sink) return cur;
	if (used[u] == id) return 0;
	used[u] = id;
	for (int e = last[u]; e != -1; e = next[e])
		if (cap[e] > flow[e]) {
			int r = dfs(ady[e], min(cur, cap[e] - flow[e]));
			if (r > 0) {
				flow[e] += r;
				flow[e ^ 1] -= r;
				return r;
			}
		}
	return 0;
}

int maxFlow() {
	int f, tot = 0;
	while (true) {
    id++;
		f = dfs(source, 1 << 29);
		if (f == 0) return tot;
		tot += f;
	}
}

int main() {
  ios::sync_with_stdio(false);
  //freopen("e.in", "r", stdin);
	while (cin >> n && n) {
		E = 0;
		for (int i = 0; i < 60; i++)
			last[i] = -1;
		source = 0;
		sink = 1;
		for (int i = 'A'; i <= 'Z'; i++) {
			add(source, i - 'A' + 2);
			add(i - 'A' + 2 + 'Z' - 'A' + 1, sink);
		}
		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2;
			add(s1[0] - 'A' + 2, s2[0] - 'A' + 2 + 'Z' - 'A' + 1);
		}
		cout << maxFlow() << '\n';
	}
}
