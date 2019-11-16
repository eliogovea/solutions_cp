#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int n, k, a[10005];
vector<vector<int> > T;

void resize(int sz) {
	int tmp = 1 + (int)log2(sz);
	tmp = 1 << (1 + tmp);
	T.resize(tmp);
	for (int i = 1; i < tmp; i++)
		T[i].resize(9, 0);
}

void build(int idx, int l, int r) {
	if (l == r) {
		T[idx][a[l] / 31] |= (1 << (a[l] % 31));
	}
	else {
		int ls = idx << 1, rs = ls + 1, mid = (l + r) >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		for (int i = 0; i < 9; i++)
			T[idx][i] = T[ls][i] | T[rs][i];
	}
}

vector<int> query(int idx, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return vector<int>(9, 0);
	if (l >= ql && r <= qr) return T[idx];
	vector<int> aux(9, 0), q1, q2;
	int ls = idx << 1, rs = ls + 1, mid = (l + r) >> 1;
	q1 = query(ls, l, mid, ql, qr);
	q2 = query(rs, mid + 1, r, ql, qr);
	for (int i = 0; i < 9; i++)
		aux[i] = q1[i] | q2[i];
	return aux;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	resize(n);
	for (int i = 1; i <= n; i++) cin >> a[i], a[i]--;
	build(1, 1, n);
	for (int a, b; k--;) {
		cin >> a >> b;
		vector<int> aux = query(1, 1, n, a, b);
		int sol = 0;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 31; j++)
				if (aux[i] & (1 << j)) sol++;
		cout << sol << "\n";
	}
}
