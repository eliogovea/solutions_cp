#include <bits/stdc++.h>

using namespace std;

struct BIT {
	int n;
	vector <int> t;

	BIT() {}
	BIT(int _n) {
		n = _n;
		t = vector <int> (n + 1, 0);
	}

	void update(int p, int v) {
		while (p <= n) {
			t[p] += v;
			p += p & -p;
		}
	}

	int query(int p) {
		int res = 0;
		while (p > 0) {
			res += t[p];
			p -= p & -p;
		}
		return res;
	}
	int query(int l, int r) {
        return query(r) - query(l - 1);
	}
};

struct query {
	int id;
	int x, y;
	bool end;
	query() {}
	query(int _id, int _x, int _y, bool _end) : id(_id), x(_x), y(_y), end(_end) {}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	const int N = 1000 * 1000;
	vector <int> maxPrime(N + 1);
	for (int i = 2; i <= N; i++) {
		if (maxPrime[i] == 0) {
			for (int j = i; j <= N; j += i) {
				maxPrime[j] = i;
			}
		}
	}

	BIT bit(N);

	int n;
	cin >> n;
	vector <int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int q;
	cin >> q;

	vector <vector <query> > b(n);
	for (int i = 0; i < q; i++) {
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		l--;
		r--;

		if (l != 0) {
			b[l - 1].push_back(query(i, x, y, false));
		}
		b[r].push_back(query(i, x, y, true));
	}

	vector <int> answer(n);

	for (int i = 0; i < n; i++) {
		int val = a[i];
		// cerr << "-->>> " << i << " " << val << "\n";
		while (val != 1) {
			int p = maxPrime[val];
			int e = 0;
			while (val != 1 && maxPrime[val] == p) {
				e++;
				val /= p;
			}
			// cerr << "update: " << i << " " << p << " " << e << "\n";
			bit.update(p, e);
		}
		for (int j = 0; j < b[i].size(); j++) {
			if (b[i][j].end) {
				answer[b[i][j].id] += bit.query(b[i][j].x, b[i][j].y);
			} else {
				answer[b[i][j].id] -= bit.query(b[i][j].x, b[i][j].y);
			}
		}
	}

	for (int i = 0; i < q; i++) {
		cout << answer[i] << "\n";
	}
}

/*
4
2 3 4 5
2
1 3 2 3
1 4 2 5

4
5
*/

