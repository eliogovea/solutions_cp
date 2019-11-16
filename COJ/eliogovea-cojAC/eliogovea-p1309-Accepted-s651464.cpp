#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

int tc, m, size;
string line, aux;
vector<int> T;
vector<char> lazy;

void resize(int size) {
	int tmp = 1 << (1 + (int)log2(size));
	T.clear();
	T.resize(tmp);
	lazy.clear();
	lazy.resize(tmp);
}

int build(int idx, int l, int r) {
	if (l == r) return T[idx] = line[l] - '0';
	int ls = idx << 1, rs = ls + 1, mid = (l + r) >> 1;
	return T[idx] = build(ls, l, mid) + build(rs, mid + 1, r);
}

void update(int idx, int l, int r, int ul, int ur, char typ) {
	if (l > ur || r < ul) return;
	if (l >= ul && r <= ur) {
		if (typ == 'F') T[idx] = r - l + 1;
		else if (typ == 'E') T[idx] = 0;
		else if (typ == 'I') T[idx] = r - l + 1 - T[idx];
	}
	if (l == r) return;
	update(idx << 1, l, (l + r) >> 1, ul, ur, typ);
	update((idx << 1) | 1, 1 + ((l + r) >> 1), r, ul, ur, typ);
	T[idx] = T[idx << 1] + T[1 + (idx << 1)];
}

int query(int idx, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) return T[idx];
	return query(idx << 1, l, (l + r) >> 1, ql, qr) +
		query((idx << 1) | 1, 1 + ((l + r) >> 1), r, ql, qr);
}

int main() {
  //freopen("e.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	int cas = 1;
	while (tc--) {
    cout << "Case " << cas++ << ":\n";
		cin >> m;
		line.clear();
		while (m--) {
			int tmp;
			cin >> tmp >> aux;
			while(tmp--) line += aux;
		}
		int size = line.size();
		resize(size);

		build(1, 0, size - 1);
		cin >> m;
		for (int i = 1, x, y; m--;) {
			cin >> aux >> x >> y;
			if (aux[0] == 'S') cout << "Q" << i++ << ": " << query(1, 0, size - 1, x, y) << "\n";
			else update(1, 0, size - 1, x, y, aux[0]);
		}
	}
}
