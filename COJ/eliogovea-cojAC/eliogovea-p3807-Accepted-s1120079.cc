#include <bits/stdc++.h>

using namespace std;

const int N = 250 * 1000 + 5;
const int MOD = (1 << 27) + (1 << 25) + 1;

inline int power(int x, int n) {
	int res = 1;
	while (n)  {
		if (n & 1) res = (long long)res * x % MOD;
		x = (long long)x * x % MOD;
		n >>= 1;
	}
	return res;
}

int roots[50], invRoots[50];

void calcRoots() { // !!!
	int a = 2;
	while (power(a, (MOD - 1) / 2) != MOD - 1) a++;
	for (int l = 1, e = 0; (MOD - 1) % l == 0; l *= 2, e++) {
		roots[e] = power(a, (MOD - 1) / l);
		invRoots[e] = power(roots[e], MOD - 2);
	}
}

void fft(vector <int> &P, bool invert) {
	int n = P.size();
	assert((n > 0) && (n == (n & -n)) && ((MOD - 1) % n == 0));
	int ln = 0;
	while ((1 << ln) < n) ln++;
	for (int i = 0; i < n; i++) {
		int x = i;
		int y = 0;
		for (int j = 0; j < ln; j++) {
			y = (y << 1) | (x & 1);
			x >>= 1;
		}
		if (y < i) swap(P[i], P[y]);
	}
	for (int l = 2, e = 1; l <= n; l *= 2, e++) {
		int hl = l >> 1;
		int step = roots[e];
		if (invert) step = invRoots[e];
		for (int i = 0; i < n; i += l) {
			int w = 1;
			for (int j = 0; j < hl; j++) {
				int u = P[i + j];
				int v = (long long)P[i + j + hl] * w % MOD;
				P[i + j] = (u + v) % MOD;
				P[i + j + hl] = (u - v + MOD) % MOD;
				w = (long long)w * step % MOD;
			}
		}
	}
	if (invert) {
		int in = power(n, MOD - 2);
		for (int i = 0; i < n; i++)
			P[i] = (long long)P[i] * in % MOD;
	}
}

vector <int> mul(vector <int> a, vector <int> b) {
  int need = (int)a.size() + (int)b.size() - 1;
  int n = 1;
  while (n < 2 * (int)a.size() || n < 2 * (int)b.size()) n <<= 1;
  a.resize(n);
  b.resize(n);
  fft(a, false);
  fft(b, false);
  for (int i = 0; i < n; i++)
		a[i] = (long long)a[i] * b[i] % MOD;
  fft(a, true);
  a.resize(need);
  return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	calcRoots();

	string a, b;
	const string S = "ACGT";
	while (cin >> a >> b) {
		vector <int> sum(a.size() + b.size() - 1);
		for (int c = 0; c < 4; c++) {
			vector <int> pa(a.size());
			for (int i = 0; i < a.size(); i++) {
				if (S[c] == a[i]) {
					pa[i] = 1;
				}
			}
			vector <int> pb(b.size());
			for (int i = 0; i < b.size(); i++) {
				if (S[c] == b[i]) {
					pb[i] = 1;
				}
			}

			reverse(pb.begin(), pb.end());
			vector <int> ab = mul(pa, pb);
			for (int i = 0; i < ab.size(); i++) {
				sum[i] += ab[i];
			}
		}
		int sz = sum.size();
		int pos = sz - 1;
		for (int i = sz - 2; i >= 0; i--) {
			if (sum[i] > sum[pos]) {
				pos = i;
			}
		}
		// cerr << "____>>>> " << pos << " " << sum[pos] << "\n";
		if (sum[pos] == 0) {
			cout << "0\nNo matches\n\n";
		} else {
			cout << sum[pos] << "\n";
			if (pos >= b.size() - 1) {
				int d = pos - (b.size() - 1);
				int l = max(a.size(), d + b.size());
				for (int i = 0; i < l; i++) {
					if (i < a.size() && (i >= d && i - d < b.size())) {
						cout << ((a[i] == b[i - d]) ? a[i] : 'X');
					} else if (i < a.size()) {
						cout << a[i];
					} else {
						cout << b[i - d];
					}
				}
			} else {
				int d = b.size() - (pos + 1);
				int l = max(b.size(), d + a.size());
				for (int i = 0; i < l; i++) {
					if (i >= d && i < d + a.size() && i < b.size()) {
						cout << ((a[i - d] == b[i]) ? b[i] : 'X');
					} else if (i >= d && i < d + a.size()) {
						cout << a[i - d];
					} else {
						cout << b[i];
					}
				}
			}
			cout << "\n\n";
		}
	}
}
