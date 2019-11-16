#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 300005;
const int MAX = 1000005;
 
int n, a[N];
 
struct Query {
	int b, e, id;
};
 
bool operator < (const Query &aa, const Query &bb) {
	if (aa.e != bb.e) {
		return aa.e < bb.e;
	}
	return aa.b < bb.b;
}
 
int nq;
vector<Query> Q;
Query qq;
int ans[N];
int last[MAX];
 
int T[4 * MAX];
 
void update(int x, int l, int r, int p, int v) {
	if (p < l || p > r) {
		return;
	}
	if (l == r) {
		T[x] = v;
	} else {
		int m = (l + r) >> 1;
		update(2 * x, l, m, p, v);
		update(2 * x + 1, m + 1, r, p, v);
		T[x] = T[2 * x] + T[2 * x + 1];
	}
}
 
int query(int x, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) {
		return 0;
	}
	if (l >= ql && r <= qr) {
		return T[x];
	}
	int m = (l + r) >> 1;
	return query(2 * x, l, m, ql, qr) + query(2 * x + 1, m + 1, r, ql, qr);
}
 
int main() {
	//freopen("dat.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		qq.b = -1;
		qq.e = i;
		qq.id = -1;
		Q.push_back(qq);
	}
	cin >> nq;
	for (int i = 1, a, b; i <= nq; i++) {
		cin >> a >> b;
		qq.b = a;
		qq.e = b;
		qq.id = i;
		Q.push_back(qq);
 
	}
	sort(Q.begin(), Q.end());
	for (int i = 0; i < Q.size(); i++) {
		if (Q[i].b == -1) {
			int x = a[Q[i].e];
			if (last[x] != 0) {
				update(1, 1, n, last[x], 0);
			}
			last[x] = Q[i].e;
			update(1, 1, n, last[x], 1);
		} else {
			ans[Q[i].id] = query(1, 1, n, Q[i].b, Q[i].e);
		}
	}
	for (int i = 1; i <= nq; i++) {
		cout << ans[i] << "\n";
	}
} 
