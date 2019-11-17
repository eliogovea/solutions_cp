// Problem: pace=1&num=1471
// Verdict: Accepted

#pragma comment(linker, "/STACK:1000000000")

#include <bits/stdc++.h>

using namespace std;

const int N = 50005;

int n, a, b, c;
int E = 0;
int last[N];
int to[2 * N];
long long w[2 * N];
int next[2 * N];
int tin[N];
int tout[N];
int timer;


long long dist[N];
int parent[20][N];

void dfs(int u, int p, long long d) {
	tin[u] = timer++;
	dist[u] = d;
	parent[0][u] = p;
	for (int i = 1; i < 18; i++) {
		parent[i][u] = parent[i - 1][parent[i - 1][u]];
	}
	for (int e = last[u]; e != -1; e = next[e]) {
		if (to[e] != p) {
			dfs(to[e], u, d + w[e]);
		}
	}
	tout[u] = timer++;
}

inline bool anc(int a, int b) {
	return (tin[a] <= tin[b] && tout[b] <= tout[a]);
}

inline int lca(int a, int b) {
	if (anc(a, b)) {
		return a;
	}
	for (int i = 17; i >= 0; i--) {
		if (!anc(parent[i][a], b)) {
			a = parent[i][a];
		}
	}
	return parent[0][a];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		last[i] = -1;
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		to[E] = b; w[E] = c; next[E] = last[a]; last[a] = E++;
		to[E] = a; w[E] = c; next[E] = last[b]; last[b] = E++;
	}
	dfs(0, 0, 0);
	cin >> c;
	while (c--) {
		cin >> a >> b;
		cout << dist[a] + dist[b] - 2LL * dist[lca(a, b)] << "\n";
	}
}