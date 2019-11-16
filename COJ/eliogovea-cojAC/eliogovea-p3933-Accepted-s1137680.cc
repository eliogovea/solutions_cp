#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 10;
const int Q = 50 * 1000 + 10;
const int LN = 20;

int n;
vector <int> G[N];

int q;
int qu[Q], qk[Q];

bool used[N];

int sub_tree_size[N];
int bfs_parent[N];
int bfs_queue[N];
int bfs_head;
int bfs_tail;

inline int get_centroid(int now) {
	bfs_head = 0;
	bfs_tail = 0;
	bfs_parent[now] = -1;
	bfs_queue[bfs_tail++] = now;
	while (bfs_head < bfs_tail) {
		int u = bfs_queue[bfs_head++];
		sub_tree_size[u] = 1;
		for (auto v : G[u]) {
			if (!used[v] && v != bfs_parent[u]) {
				bfs_parent[v] = u;
				bfs_queue[bfs_tail++] = v;
			}
		}
	}
	int component_size = bfs_head;
	for (int i = bfs_head - 1; i > 0; i--) {
		sub_tree_size[bfs_parent[bfs_queue[i]]] += sub_tree_size[bfs_queue[i]];
	}
	
	int centroid = -1;
	int best_max;
	for (int i = 0; i < bfs_head; i++) {
		int u = bfs_queue[i];
		int max_sub_tree_size = component_size - sub_tree_size[u];
		for (auto v : G[u]) {
			if (!used[v] && v != bfs_parent[u]) {
				max_sub_tree_size = max(max_sub_tree_size, sub_tree_size[v]);
			}
		}
		if (centroid == -1 || max_sub_tree_size < best_max) {
			centroid = u;
			best_max = max_sub_tree_size;
		}
	}
	return centroid;
}

int dist[LN][N];

inline void calc_dist(int now, int _depth) {
	bfs_head = 0;
	bfs_tail = 0;
	bfs_parent[now] = -1;
	dist[_depth][now] = 0;
	bfs_queue[bfs_tail++] = now;
	while (bfs_head < bfs_tail) {
		int u = bfs_queue[bfs_head++];
		for (auto v : G[u]) {
			if (!used[v] && v != bfs_parent[u]) {
				bfs_parent[v] = u;
				dist[_depth][v] = dist[_depth][u] + 1;
				bfs_queue[bfs_tail++] = v;
			}
		}
	}
}

int depth[N];
int parent[N];

int timer;
int time_in[N];
int time_out[N];

void _centroid_decomposition(int now, int _parent = -1, int _depth = 0) {
	now = get_centroid(now);
	calc_dist(now, _depth);
	parent[now] = _parent;
	depth[now] = _depth;
	time_in[now] = timer++;
	
	used[now] = true;
	
	for (auto to : G[now]) {
		if (!used[to]) {
			_centroid_decomposition(to, now, _depth + 1);
		}
	}
	
	time_out[now] = timer - 1;
}

inline void centroid_decomposition() {
	for (int u = 0; u < n; u++) {
		used[u] = false;
	}
	_centroid_decomposition(0);
}


/// type: 0 point, 1 query
struct event {
	int id;
	int value;
	int type;
	int left;
	int right;
	
	event(int _id, int _value, int _type, int _left, int _right) {
		id = _id;
		value = _value;
		type = _type;
		left = _left;
		right = _right;
	}
};

bool operator < (const event &a, const event &b) {
	if (a.value != b.value) {
		return a.value < b.value;
	}
	return a.type < b.type;
}

vector <event> E[LN];

int f[N];

inline void reset() {
	for (int i = 0; i <= n; i++) {
		f[i] = 0;
	}
}

inline void update(int p, int v) {
	while (p <= n) {
		f[p] += v;
		p += p & -p;
	}
}

inline int query(int p) {
	int res = 0;
	while (p > 0) {
		res += f[p];
		p -= p & -p;
	}
	return res;
}

inline int query(int left, int right) {
	return query(right) - query(left - 1);
}

int t[LN][N];

int answer[N];

void read_tree() {
	cin >> n;
	for (int u = 0; u < n; u++) {
		G[u].clear();
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

void generate_random_tree(int max_n) {
	n = 1 + rand() % max_n;
	cout << "new case:\n";
	cout << n << "\n";
	for (int u = 0; u < n; u++) {
		G[u].clear();
	}
	for (int u = 1; u < n; u++) {
		int v = rand() % u;
		cout << v + 1 << " " << u + 1 << "\n";
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

void read_queries() {
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> qu[i] >> qk[i];
		qu[i]--;
	}
}

void generate_random_queries(int max_q) {
	q = 1 + rand() % max_q;
	cout << q << "\n";
	for (int i = 0; i < q; i++) {
		qu[i] = rand() % n;
		qk[i] = rand() % n;
		cout << qu[i] + 1 << " " << qk[i] << "\n";
	}
}

int answer_slow[Q];
int dist_slow[N];

int solve_slow() {
	for (int i = 0; i < q; i++) {
		int u = qu[i];
		int k = qk[i];
		bfs_head = 0;
		bfs_tail = 0;
		bfs_queue[bfs_tail++] = u;
		bfs_parent[u] = -1;
		dist_slow[u] = 0;
		while (bfs_head < bfs_tail) {
			int x = bfs_queue[bfs_head++];
			if (dist_slow[x] == k) {
				continue;
			}
			for (auto y : G[x]) {
				if (y != bfs_parent[x]) {
					dist_slow[y] = dist_slow[x] + 1;
					bfs_parent[y] = x;
					bfs_queue[bfs_tail++] = y;
				}
			}
		}
		answer_slow[i] = bfs_head;
	}
}

int answer_fast[N];

int solve_fast() {
	centroid_decomposition();
	int max_depth = 0;
	for (int u = 0; u < n; u++) {
		max_depth = max(max_depth, depth[u]);
	}
	for (int d = 0; d <= max_depth; d++) {
		E[d].clear();
	}
	for (int d = 0; d <= max_depth; d++) {
		for (int u = 0; u < n; u++) {
			if (depth[u] >= d) {
				E[d].push_back(event(u, dist[d][u], 0, -1, -1));
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int u = qu[i];
		int k = qk[i];
		E[depth[u]].push_back(event(i, k, 1, time_in[u] + 1, time_out[u] + 1));
		int v = u;
		while (depth[v] > 0) {
			int w = parent[v];
			int kk = k - dist[depth[w]][u];
			if (kk >= 0) {
				E[depth[w]].push_back(event(i, kk, 1, time_in[w] + 1, time_in[v] + 1 - 1));
				if (time_out[v] < time_out[w]) {
					E[depth[w]].push_back(event(i, kk, 1, time_out[v] + 1 + 1, time_out[w] + 1));
				}
			}
			v = w;
			
		}
	}
	for (int d = 0; d <= max_depth; d++) {
		reset();
		sort(E[d].begin(), E[d].end());
		for (auto &e : E[d]) {
			if (e.type == 0) {
				update(time_in[e.id] + 1, 1);
			} else {
				answer_fast[e.id] += query(e.left, e.right);
			}
		}
	}
}

void test() {
	srand(time(NULL));
	bool all = true;
	for (int it = 0; it < 1; it++) {
		read_tree();
		read_queries();
		// generate_random_tree(15);
		// generate_random_queries(15);
		solve_slow();
		solve_fast();
		
		bool ok = true;
		cout << "answer:\n";
		for (int i = 0; i < q; i++) {
			cout << answer_slow[i] << " " << answer_fast[i];
			if (answer_slow[i] != answer_fast[i]) {
				ok = false;
				cout << " !!!!!!!!!!!!!!!!!!!!!!!!!!";
			}
			cout << "\n";
		}
		if (ok) {
			cout << "OK\n";
		} else {
			cout << "WRONG!!!!!\n";
			// break;
		}
		
	}
	if (all) {
		cout << "OK\n";
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	read_tree();
	read_queries();
	solve_fast();
	for (int i = 0; i < q; i++) {
		cout << answer_fast[i] << "\n";
	}
}


