#include <bits/stdc++.h>

using namespace std;

const int SIZE = 3 * 100 * 1000 + 5;

int bit[SIZE];

void init(int n) {
	for (int i = 0; i <= n; i++) {
		bit[i] = 0;
	}
}

inline void update(int p, int n, int v) {
	while (p <= n) {
		bit[p] += v;
		p += p & -p;
	}
}

inline int query(int p) {
	int res = 0;
	while (p > 0) {
		res += bit[p];
		p -= p & -p;
	}
	return res;
}

int findFirstActive(int l, int r, int n) {
	int a = query(l - 1);
	int b = query(r);
	if (b > a) { // at least one active center
		int sum = a + 1;
		int lo = l;
		int hi = r;
		int res = hi;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (query(mid) - a >= sum) {
				res = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		return res;
	}
	return -1;
}

inline void manacher(string &s, int *u) {
	int n = s.size() * 2;
	for (int i = 0, j = 0, k; i < n; i += k, j = std::max(j - k, 0)) {
		while (i >= j && i + j + 1 < n && s[(i - j) >> 1] == s[(i + j + 1) >> 1]) ++j;
		for (u[i] = j, k = 1; i >= k && u[i] >= k && u[i - k] != u[i] - k; ++k) {
			u[i + k] = std::min(u[i - k], u[i] - k);
		}
	}
}

int t;
string s;
int maxPal[2 * SIZE];

vector <int> removeEvents[SIZE];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> s;
		if (s.size() < 4) {
			cout << "0\n";
			continue;
		}

		manacher(s, maxPal);

		init(s.size());
		for (int i = 0; i + 1 < s.size(); i++) {
			removeEvents[i + 1].clear();
		}

		int ans = 0;
		for (int i = 0; i + 1 < s.size(); i++) {
			int pos = i + 1;
			int center = i + i + 1;
			int radius = maxPal[center] / 2;
			if (radius >= 2) {
				int lPos = pos - radius / 2;
				int rPos = pos - 1;
				int first = findFirstActive(lPos, rPos, s.size() - 1);
				if (first != -1) {
					ans = max(ans, pos - first);
				}
			}
			for (int j = 0; j < removeEvents[pos].size(); j++) {
				update(removeEvents[pos][j], s.size(), -1);
			}
			if (radius >= 1) {
				update(pos, s.size(), 1);
				removeEvents[pos + radius].push_back(pos);
			}
		}
		cout << 4 * ans << "\n";
	}
}
