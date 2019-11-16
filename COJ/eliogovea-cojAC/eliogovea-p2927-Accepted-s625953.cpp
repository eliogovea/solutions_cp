#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int n, m;
vector<int> G[MAXN];
vector<int>::iterator it;
int lev[MAXN], col[MAXN];
queue<int> Q;

bool bfs(int u) {
	lev[u] = 1;
	col[u] = 1;
	Q.push(u);
	while (!Q.empty()) {
		int act = Q.front();
		Q.pop();
		for (it = G[act].begin(); it != G[act].end(); it++){
			if (!lev[*it]) {
				lev[*it] = lev[act] + 1;
				col[*it] = 1 - col[act];
				Q.push(*it);
			}
			else if (col[*it] == col[act]) return false;
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0, a, b; i < m; i++) {
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bool bip = true;
	for (int i = 1; i <= n && bip; i++)
		if (!lev[i]) bip = bfs(i);
	printf("%s\n", bip ? "YES" : "NO");
}
