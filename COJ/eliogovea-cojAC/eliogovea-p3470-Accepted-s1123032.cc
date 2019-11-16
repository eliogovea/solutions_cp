#include <bits/stdc++.h>

using namespace std;

const int N = 200 * 1000 + 10;
const int K = 1000 * 1000 + 10;

int n, k;
vector <pair <int, int> > tree[N];
bool used[N];
int subTreeSize[N];

int getSubTreeSize(int u, int p) {
	int size = 1;
	for (int i = 0; i < tree[u].size(); i++) {
		int v = tree[u][i].first;
		if (v != p && !used[v]) {
			size += getSubTreeSize(v, u);
		}
	}
	subTreeSize[u] = size;
	return size;
}

int getCentroid(int u, int p, int size) {
	int maxSubTreeSize = size - subTreeSize[u];
	for (int i = 0; i < tree[u].size(); i++) {
		int v = tree[u][i].first;
		if (v != p && !used[v]) {
			maxSubTreeSize = max(maxSubTreeSize, subTreeSize[v]);
		}
	}
	if (maxSubTreeSize <= size / 2) {
		return u;
	}
	for (int i = 0; i < tree[u].size(); i++) {
		int v = tree[u][i].first;
		if (v != p && !used[v]) {
			int x = getCentroid(v, u, size);
			if (x != -1) {
				return x;
			}
		}
	}
	return -1;
}

int dist_used[K]; // id del nodo(root) para no tener que limpiar la dp (min_cnt)
int min_cnt[K]; // dp

void solve(int root, int u, int p, int cnt, int dist, bool update, int &answer) {
	if (dist > k) {
		return;
	}
	if (!update) {
		if (dist_used[k - dist] == root) {
			int value = cnt + min_cnt[k - dist];
			if (answer == -1 || value < answer) {
				answer = value;
			}
		}
		for (int i = 0; i < tree[u].size(); i++) {
			int v = tree[u][i].first;
			int d = tree[u][i].second;
			if (v != p && !used[v]) {
				solve(root, v, u, cnt + 1, dist + d, false, answer);
				if (u == root) {
					solve(root, v, u, cnt + 1, dist + d, true, answer);
				}
			}
		}
	} else {
		if (dist_used[dist] != root || cnt < min_cnt[dist]) {
			dist_used[dist] = root;
			min_cnt[dist] = cnt;
		}
		for (int i = 0; i < tree[u].size(); i++) {
			int v = tree[u][i].first;
			int d = tree[u][i].second;
			if (v != p && !used[v]) {
				solve(root, v, u, cnt + 1, dist + d, true, answer);
			}
		}
	}
}

int centroidDecomposition(int u) {
	int sz = getSubTreeSize(u, -1);
	u = getCentroid(u, -1, sz);
	used[u] = true;
	dist_used[0] = u;
	min_cnt[0] = 0;
	int res = -1;
	solve(u, u, -1, 0, 0, false, res);
	for (int i = 0; i < tree[u].size(); i++) {
		int v = tree[u][i].first;
		if (!used[v]) {
			int val = centroidDecomposition(v);
			if (val != -1) {
				if (res == -1 || val < res) {
					res = val;
				}
			}
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		tree[a].push_back(make_pair(b, l));
		tree[b].push_back(make_pair(a, l));
	}

	for (int d = 0; d <= k; d++) {
		dist_used[d] = -1;
	}
	int answer = centroidDecomposition(0);

	cout << answer << "\n";
}
