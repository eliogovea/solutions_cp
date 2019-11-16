#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 30005;
 
struct event {
	int val;
	int a, b, id;
} e;
 
bool operator < (const event &a, const event &b) {
	if (a.val != b.val) {
		return a.val > b.val;
	}
 return a.id > b.id;
}
 
vector<event> E;
 
int n, q, a[N], ans[200005];
 
int bit[N];
 
void update(int p, int v) {
	while (p <= n) {
		bit[p] += v;
		p += p & -p;
	}
}
 
int query(int p) {
	int res = 0;
	while (p > 0) {
		res += bit[p];
		p -= p & -p;
	}
	return res;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		e.val = a[i];
		e.a = i;
		e.b = -1;
		e.id = -1;
		E.push_back(e);
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> e.a >> e.b >> e.val;
		e.id = i;
		E.push_back(e);
	}
	sort(E.begin(), E.end());
	for (int i = 0; i < E.size(); i++) {
		//cout << E[i].val << " " << E[i].id << " " << E[i].a << " " << E[i].b << "\n";
		if (E[i].id == -1) {
			update(E[i].a, 1);
		} else {
			ans[E[i].id] = query(E[i].b) - query(E[i].a - 1);
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << "\n";
	}
} 
