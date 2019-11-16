#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 500005;

int n, q, parent[MAXN], root;
vector<int> G[MAXN];
int ll[MAXN], rr[MAXN];

int arr[MAXN << 1], id;
int T[MAXN << 3], lazy[MAXN << 3];

void build(int idx, int l, int r) {
  T[idx] = lazy[idx] = 0;
  if (l == r) return;
  int mid = (l + r) >> 1, ls = idx << 1, rs = ls + 1;
  build(ls, l, mid);
  build(rs, mid + 1, r);
}

inline void propagate(int idx, int l, int r) {
  if (lazy[idx]) {
    T[idx] = r - l + 1 - T[idx];
    if (l != r) {
      int ls = idx << 1, rs = ls + 1;
      lazy[ls] = 1 - lazy[ls];
      lazy[rs] = 1 - lazy[rs];
    }
    lazy[idx] = 0;
  }
}

void upd(int idx, int l, int r, int ul, int ur) {
  propagate(idx, l, r);
  if (l > ur || r < ul) return;
  if (l >= ul && r <= ur) {
    T[idx] = r - l + 1 - T[idx];
    if (l != r) {
      int ls = idx << 1, rs = ls + 1;
      lazy[ls] = 1 - lazy[ls];
      lazy[rs] = 1 - lazy[rs];
    }
  }
  else {
    int mid = (l + r) >> 1, ls = idx << 1, rs = ls + 1;
    upd(ls, l, mid, ul, ur);
    upd(rs, mid + 1, r, ul, ur);
    T[idx] = T[ls] + T[rs];
  }
}

int query(int idx, int l, int r, int ql, int qr) {
  propagate(idx, l, r);
  if (l > qr || r < ql) return 0;
  if (l >= ql && r <= qr) return T[idx];
  int mid = (l + r) >> 1, ls = idx << 1, rs = ls + 1;
  return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
}

void dfs(int u) {
  ll[u] = id;
	arr[id++] = u;
	for (int i = 0; i < G[u].size(); i++) {
		dfs(G[u][i]);
	}
	rr[u] = id;
  arr[id++] = u;
}

int main() {
	//freopen("e.in", "r", stdin);
	while (scanf("%d%d", &n, &q) == 2) {
    id = 1;
		for (int i = 0; i < n; i++) {
			G[i].clear();
			parent[i] = -1;
		}
		for (int i = 1, x, y; i < n; i++) {
			scanf("%d%d", &x, &y);
			parent[y] = x;
			G[x].push_back(y);
		}
		for (int i = 0; i < n; i++)
			if (parent[i] == -1) {
				root = i;
				break;
			}
		dfs(root);
		id--;
		build(1, 1, id);
		for (int x, y; q--;) {
      scanf("%d%d", &x, &y);
      if (x == 0) upd(1, 1, id, ll[y], rr[y]);
      else printf("%d\n", query(1, 1, id, ll[y], rr[y]) / 2);
		}
	}
}
