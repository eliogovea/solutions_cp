#include <bits/stdc++.h>

using namespace std;

const int MOD = (1 << 27) + (1 << 25) + 1;
vector <int> roots;

inline int power(int x, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = (long long)res * x % MOD;
		}
		x = (long long)x * x % MOD;
		n >>= 1;
	}
	return res;
}

inline void calcRoots() {
	int t = MOD - 1;
	int p2 = 0;
	while (t % 2 == 0) {
		t /= 2;
		p2++;
	}
	assert(p2 != 0);
	roots.resize(p2 + 1);

	int start = 2;
	while (power(start, (MOD - 1) / 2) == 1) {
		start++;
	}
	int pw = MOD - 1;
	for (int i = 0; i < p2; i++) {
		roots[i] = power(start, pw);
		pw /= 2;
	}
}

void fft(vector <int> &arr, bool inv) {
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		int j = 0;
		int x = i;
		int y = n - 1;
		while (y > 0) {
			j = (j << 1) + (x & 1);
			x >>= 1;
			y >>= 1;
		}
		if (i < j) {
			swap(arr[i], arr[j]);
		}
	}
	for (int p2 = 1, pow2 = 1; p2 < n; p2 *= 2, pow2++) {
		int w = roots[pow2];
		if (inv) {
			w = power(w, MOD - 2);
		}
		for (int big = 0; big < n; big += 2 * p2) {
			int cur = 1;
			for (int small = big; small < big + p2; ++small) {
				int i = small;
				int j = small + p2;
				int u = arr[i];
				int v = (long long)arr[j] * cur % MOD;
				arr[i] = u + v;
				if (arr[i] >= MOD) {
					arr[i] -= MOD;
				}
				arr[j] = u - v;
				if (arr[j] < 0) {
					arr[j] += MOD;
				}
				cur = (long long)cur * w % MOD;
			}
		}
	}
	if (inv) {
		int x = power(n, MOD - 2);
		for (int i = 0; i < n; i++) {
			arr[i] = (long long)arr[i] * x % MOD;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);

	int u, m, c;
	cin >> u >> m >> c;

	vector <int> cp(u + 1, 0);
	vector <int> pp(u + 1, 1);
	for (int i = 2; i <= u; i++) {
		if (cp[i] == 0) {
			for (int j = i; j <= u; j += i) {
				cp[j]++;
				pp[j] *= i;
			}
		}
	}
	vector <int> p(m * c / 2 + 1);
	for (int i = 2; i <= u; i++) {
		if ((cp[i] == 2 && pp[i] == i) || (cp[i] == 1 && pp[i] * pp[i] == i)) {
			p[i % m]++;
		}
	}
	calcRoots();

	int n = 1;
	while (n < 2 * p.size()) {
		n <<= 1;
	}
	p.resize(n);
	fft(p, false);
	for (int i = 0; i < p.size(); i++) {
		p[i] = power(p[i], c);
	}
	fft(p, true);
	cout << p[m * c / 2] << "\n";
}
