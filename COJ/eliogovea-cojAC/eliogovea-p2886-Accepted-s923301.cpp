#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct ST {
	struct data {
		int mn, freq;
		data() {
			mn = INF;
			freq = 0;
		}
		data(int _mn, int _freq) {
			mn = _mn; freq = _freq;
		}
	};
	data merge(const data &a, const data &b) {
		if (a.mn < b.mn) {
			return a;
		} else if (b.mn < a.mn) {
			return b;
		} else {
			return data(a.mn, a.freq + b.freq);
		}
	}
	int n;
	vector <data> tree;
	vector <int> to_add;
	ST(int _n) {
		n = _n;
		tree = vector <data> (4 * n);
		to_add = vector <int>(4 * n, 0);
	}
	void build(int x, int l, int r) {
		tree[x].mn = 0;
		tree[x].freq = r - l + 1;
		if (l != r) {
			int m = (l + r) >> 1;
			build(2 * x, l, m);
			build(2 * x + 1, m + 1, r);
		}
	}
	void build() {
		build(1, 1, n);
	}
	void push(int x, int l, int r) {
		if (to_add[x] != 0) {
			tree[x].mn += to_add[x];
			if (l != r) {
				to_add[2 * x] += to_add[x];
				to_add[2 * x + 1] += to_add[x];
			}
			to_add[x] = 0;
		}
	}
	void update(int x, int l, int r, int ul, int ur, int v) {
		push(x, l, r);
		if (l > ur || r < ul) {
			return;
		}
		if (l >= ul && r <= ur) {
			to_add[x] += v;
			push(x, l, r);
		} else {
			int m = (l + r) >> 1;
			update(2 * x, l, m, ul, ur, v);
			update(2 * x + 1, m + 1, r, ul, ur, v);
			tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
		}
	}
	void update(int ul, int ur, int v) {
		update(1, 1, n, ul, ur, v);
	}
	data query(int x, int l, int r, int ql, int qr) {
		push(x, l, r);
		if (l > qr || r < ql) {
			return data();
		}
		if (l >= ql && r <= qr) {
			return tree[x];
		}
		int m = (l + r) >> 1;
		data q1 = query(2 * x, l, m, ql, qr);
		data q2 = query(2 * x + 1, m + 1, r, ql, qr);
		return merge(q1, q2);
	}
	int query() {
		data res = query(1, 1, n, 1, n);
		if (res.mn != 0) {
			return 0;
		}
		return res.freq;
	}
};

const int MAXN = 100000;

vector <int> factors[MAXN + 5];
vector <int> primes;
vector <int> pos;

void fill_sieve() {
	pos = vector <int> (MAXN + 5, 0);
	for (int i = 2; i <= MAXN; i++) {
		if (!factors[i].size()) {
			pos[i] = primes.size();
			primes.push_back(i);
			for (int j = i; j <= MAXN; j += i) {
				factors[j].push_back(i);
			}
		}
	}
}

bool solve_case() {
	int n, m, k;
	cin >> n >> k >> m;
	if (n == 0 && k == 0 && m == 0) {
        return false;
	}
	vector <int> arr(n + 5);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	vector <set <int> > ppos(primes.size());
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < factors[ arr[ i ] ].size(); j++) {
			ppos[ pos[ factors[ arr[ i ] ][ j ] ] ].insert(i);
		}
	}
	ST st(n - k + 1);
	st.build();
	for (int i = 0; i < primes.size(); i++) {
		if (ppos[i].size() > 1) {
			set <int>::iterator a, b;
			a = ppos[i].begin();
			b = a; b++;
			while (b != ppos[i].end()) {
				if (*b - *a + 1 <= k) {
					st.update(max(*b - k + 1, 1), *a, 1);
				}
				a++;
				b++;
			}
		}
	}
	cout << n - k + 1 - st.query() << "\n";
	int p, v;
	while (m--) {
		cin >> p >> v;
		for (int i = 0; i < factors[ arr[p] ].size(); i++) {
			int prime = factors[arr[p]][i];
			int pp = pos[prime];
			set <int> &S = ppos[pp];
			if (S.size() == 1) {
				S.clear();
				continue;
			}
			set <int>::iterator it = S.find(p);
			if (it == S.begin()) {
				set <int>::iterator y = it; y++;
				if (*y - *it + 1 <= k) {
					st.update(max(*y - k + 1, 1), *it, -1);
				}
				S.erase(it);
				continue;
			}
			set <int>::iterator y = it; y++;
			if (y == S.end()) {
				set <int>::iterator x = it; x--;
				if (*it - *x + 1 <= k) {
					st.update(max(*it - k + 1, 1), *x, -1);
				}
				S.erase(it);
				continue;
			}
			set <int>::iterator x = it; x--;
			if (*y - *it + 1 <= k) {
				st.update(max(*y - k + 1, 1), *it, -1);
			}
			if (*it - *x + 1 <= k) {
				st.update(max(*it - k + 1, 1), *x, -1);
			}
			if (*y - *x + 1 <= k) {
				st.update(max(*y - k + 1, 1), *x, 1);
			}
			S.erase(it);
		}
		arr[p] = v;
		for (int i = 0; i < factors[ arr[ p ] ].size(); i++) {
			int prime = factors[ arr[ p ] ][ i ];
			int pp = pos[prime];
			set <int> &S = ppos[pp];
			assert(S.find(p) == S.end());
			S.insert(p);
			if (S.size() == 1) {
				continue;
			}
			set <int>::iterator it = S.find(p);
			if (it == S.begin()) {
				set <int>::iterator y = it; y++;
				if (*y - *it + 1 <= k) {
					st.update(max(*y - k + 1, 1), *it, 1);
				}
				continue;
			}
			set <int>::iterator y = it; y++;
			if (y == S.end()) {
				set <int>::iterator x = it; x--;
				if (*it - *x + 1 <= k) {
					st.update(max(*it - k + 1, 1), *x, 1);
				}
				continue;
			}
			set <int>::iterator x = it; x--;
			if (*it - *x + 1 <= k) {
				st.update(max(*it - k + 1, 1), *x, 1);
			}
			if (*y - *it + 1 <= k) {
				st.update(max(*y - k + 1, 1), *it, 1);
			}
			if (*y - *x + 1 <= k) {
				st.update(max(*y - k + 1, 1), *x, -1);
			}
		}
		cout << n - k + 1 - st.query() << "\n";
	}
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += (long long)arr[i];
	}
	cout << sum << "\n";
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	fill_sieve();
	while (solve_case());
}
