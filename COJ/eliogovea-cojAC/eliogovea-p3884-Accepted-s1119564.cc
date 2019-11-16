#include <bits/stdc++.h>

using namespace std;

const int N = 300;
const int S = N * N + 10;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

inline bool inside(int x, int n) { // [0, n)
	return (0 <= x && x < n);
}

int parent[S];

int find(int x) {
	if (x != parent[x]) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

bool join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return false;
	}
	if (rand() & 1) {
		parent[x] = y;
	} else {
		parent[y] = x;
	}
	return true;
}

int n, m;
int h[N + 5][N + 5];
int id[N + 5][N + 5];

struct item {
	int h, x, y;
	item() {}
	item(int _h, int _x, int _y) {
		h = _h;
		x = _x;
		y = _y;
	}
};

bool operator < (const item &a, const item &b) {
	return a.h < b.h;
}

item a[S];

int q;
int t[100 * 1000 + 10];

bool out[N + 5][N + 5];

int ans[100 * 1000 + 10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int sz = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> h[i][j];
			id[i][j] = sz++;
			a[id[i][j]].h = h[i][j];
			a[id[i][j]].x = i;
			a[id[i][j]].y = j;
			out[i][j] = false;
			parent[id[i][j]] = id[i][j];
		}
	}

	sort(a, a + sz);

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> t[i];
	}

	int cnt = 0;
	for (int i = q - 1, j = sz - 1; i >= 0; i--) {
		while (j > 0 && a[j].h > t[i]) {
			int x = a[j].x;
			int y = a[j].y;
			cnt++;
			out[x][y] = true;
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (inside(nx, n) && inside(ny, m)) {
					if (out[nx][ny]) {
						if (join(id[x][y], id[nx][ny])) {
							cnt--;
						}
					}
				}
			}
			j--;
		}
		ans[i] = cnt;
	}

	for (int i = 0; i < q; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}
