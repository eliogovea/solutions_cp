#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

const int BASE1 = 31;
const int BASE2 = 43;

const int MOD1 = 1000000007;
const int MOD2 = 1000000009;

inline void add(int &a, int b, int MOD) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b, int MOD) {
	return (long long)a * b % MOD;
}

inline int val(char ch) {
	return ch - 'a' + 1;
}

int t, k;
int n;
string a, b;

int p1[N], p2[N];
int h1a[N], h1b[N], h2a[N], h2b[N];

inline int get(int *hash, int *p, int MOD, int s, int e) {
	int r = hash[e];
	int l = mul(hash[s], p[e - s], MOD);
	add(r, MOD - l, MOD);
	return r;
}

int lcp(int sa, int sb) {
	int lo = 0;
	int hi = min(n - sa, n - sb);
	int res = 0;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		bool ok1 = (get(h1a, p1, MOD1, sa, sa + mid) == get(h1b, p1, MOD1, sb, sb + mid));
		bool ok2 = (get(h2a, p2, MOD2, sa, sa + mid) == get(h2b, p2, MOD2, sb, sb + mid));
		//cout << mid << ":\n";
		//cout << " " << get(h1a, p1, MOD1, sa, sa + mid) << " : " << get(h1b, p1, MOD1, sb, sb + mid) << " " << ok1 << "\n";
        //cout << " " << get(h2a, p2, MOD2, sa, sa + mid) << " : " << get(h2b, p2, MOD2, sb, sb + mid) << " " << ok2 << "\n";
		if (ok1 && ok2) {
			res = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	p1[0] = 1;
	p2[0] = 1;
	for (int i = 1; i < N; i++) {
		p1[i] = mul(p1[i - 1], BASE1, MOD1);
		p2[i] = mul(p2[i - 1], BASE2, MOD2);
	}
	cin >> t >> k;
	int ansmin = -1;
	int ansmax = -1;
	while (t--) {
		cin >> a;
		n = a.size();
		b = a;
		reverse(b.begin(), b.end());
		for (int i = 1; i <= n; i++) {
			h1a[i] = mul(h1a[i - 1], BASE1, MOD1); add(h1a[i], val(a[i - 1]), MOD1);
			h2a[i] = mul(h2a[i - 1], BASE2, MOD2); add(h2a[i], val(a[i - 1]), MOD2);
			h1b[i] = mul(h1b[i - 1], BASE1, MOD1); add(h1b[i], val(b[i - 1]), MOD1);
			h2b[i] = mul(h2b[i - 1], BASE2, MOD2); add(h2b[i], val(b[i - 1]), MOD2);
		}

		int tot = 0;
		//cout << "odd:\n";
		for (int i = 0; i < n; i++) {
			int v = lcp(i, n - 1 - i) - 1;
			if (2 * v + 1 < k) {
				continue;
			}
			int lo = 0;
			int hi = v;
			int x = v;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (2 * mid + 1 >= k) {
					x = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
			tot += v - x + 1;
			//cout << "center: " << i << " lcp: " << v << "\n";
		}
		//cout << "even:\n";
		for (int i = 1; i < n; i++) {
			int v = lcp(i, n - 1 - (i - 1));
			if (2 * v < k) {
				continue;
			}
			int lo = 0;
			int hi = v;
			int x = v;
			while (lo <= hi) {
				int mid = (lo + hi) >> 1;
				if (2 * mid >= k) {
					x = mid;
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
			tot += v - x + 1;
			//cout << "center: " << i << " lcp: " << v << "\n";
		}
		//cout << "total: "<< tot << "\n";
		if (ansmin == -1 || tot < ansmin) {
			ansmin = tot;
		}
		if (ansmax == -1 || tot > ansmax) {
			ansmax = tot;
		}
	}
	cout << ansmin << " " << ansmax << "\n";
}
