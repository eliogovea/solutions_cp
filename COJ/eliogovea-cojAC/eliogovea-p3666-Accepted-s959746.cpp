#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
typedef long long LL;

int n, q;
LL h[N];
int id[N];
int blockSize;
vector <LL> block[1000];
LL lazy[1000];

void build() {
	blockSize = sqrt((double)n) + 1;
	for (int i = 0; i < n; i++) {
		id[i] = i / blockSize;
		block[id[i]].push_back(h[i]);
	}
	for (int i = 0; i <= id[n - 1]; i++) {
		sort(block[i].begin(), block[i].end());
	}
}

void update(int l, int r, LL v) {
	if (l > r) {
		swap(l, r);
	}
	if (v == 0) {
		return;
	}
	if (id[l] == id[r]) {
		for (int i = 0; i < blockSize && id[l] * blockSize + i < n; i++) {
			h[id[l] * blockSize + i] += lazy[id[l]];
		}
		lazy[id[l]] = 0;
		for (int i = l; i <= r; i++) {
			h[i] += v;
		}
		for (int i = 0; i < blockSize && id[l] * blockSize + i < n; i++) {
			block[id[l]][i] = h[id[l] * blockSize + i];
		}
		sort(block[id[l]].begin(), block[id[l]].end());
	} else {
		if (l % blockSize != 0) {
			for (int i = 0; i < blockSize && id[l] * blockSize + i < n; i++) {
				h[id[l] * blockSize + i] += lazy[id[l]];
			}
			lazy[id[l]] = 0;
			int nextl = (id[l] + 1) * blockSize;
			for (int i = l; i < nextl; i++) {
				h[i] += v;
			}
			for (int i = 0; i < blockSize && id[l] * blockSize + i < n; i++) {
				block[id[l]][i] = h[id[l] * blockSize + i];
			}
			sort(block[id[l]].begin(), block[id[l]].end());
			l = nextl;
		}
		if (r % blockSize != blockSize - 1) {
			for (int i = 0; i < blockSize && id[r] * blockSize + i < n; i++) {
				h[id[r] * blockSize + i] += lazy[id[r]];
			}
			lazy[id[r]] = 0;
			int prevr = id[r] * blockSize - 1;
			for (int i = r; i > prevr; i--) {
				h[i] += v;
			}
			for (int i = 0; i < blockSize && id[r] * blockSize + i < n; i++) {
				block[id[r]][i] = h[id[r] * blockSize + i];
			}
			sort(block[id[r]].begin(), block[id[r]].end());
			r = prevr;
		}
		for (int i = id[l]; i <= id[r]; i++) {
			lazy[i] += v;
		}
	}
}

LL query(int l, int r) {
	if (l > r) {
		swap(l, r);
	}
	LL val = max(h[l] + lazy[id[l]], h[r] + lazy[id[r]]);
	if (id[l] == id[r]) {
		int res = 0;
		for (int i = l; i <= r; i++) {
			if (h[i] + lazy[id[i]] > val) {
				res++;
			}
		}
		return res;
	}
	int res = 0;
	if (l % blockSize != 0) {
		for (int i = 0; i < blockSize && id[l] * blockSize + i < n; i++) {
			h[id[l] * blockSize + i] += lazy[id[l]];
		}
		lazy[id[l]] = 0;
		for (int i = 0; i < blockSize && id[l] * blockSize + i < n; i++) {
			block[id[l]][i] = h[id[l] * blockSize + i];
		}
		sort(block[id[l]].begin(), block[id[l]].end());
		int nextl = (id[l] + 1) * blockSize;
		for (int i = l; i < nextl; i++) {
			if (h[i] > val) {
				res++;
			}
		}
		l = nextl;
	}
	if (r % blockSize != blockSize - 1) {
		for (int i = 0; i < blockSize && id[r] * blockSize + i < n; i++) {
			h[id[r] * blockSize + i] += lazy[id[r]];
		}
		lazy[id[r]] = 0;
		for (int i = 0; i < blockSize && id[r] * blockSize + i < n; i++) {
			block[id[r]][i] = h[id[r] * blockSize + i];
		}
		sort(block[id[r]].begin(), block[id[r]].end());
		int prevr = id[r] * blockSize - 1;
		for (int i = r; i > prevr; i--) {
			if (h[i] > val) {
				res++;
			}
		}
		r = prevr;
	}
	for (int i = id[l]; i <= id[r]; i++) {
		res += block[i].end() - upper_bound(block[i].begin(), block[i].end(), val - lazy[i]);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	build();
	while (q--) {
		char ch;
		cin >> ch;
		if (ch == 'Q') {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			cout << query(l, r) << "\n";
		} else {
			int l, r;
			LL v;
			cin >> l >> r >> v;
			l--;
			r--;
			update(l, r, v);
		}
	}
}
