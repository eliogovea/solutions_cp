// 2016-2017 ACM-ICPC, NEERC, Moscow Subregional Contest
// 101137A

#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n, a[N];
int s[N], t;
int b[N], c[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[n + i] = a[n + n + i] = a[i];
	}
	int l = 3 * n;
	for (int i = 0; i < l; i++) {
		b[i] = c[i] = -1;
	}
	t = 0;
	for (int i = 0; i < l; i++) {
		while (t > 0 && a[i] > a[s[t - 1]]) {
			b[s[t - 1]] = i;
			t--;
		}
		s[t++] = i;
	}
	t = 0;
	for (int i = 0; i < l; i++) {
		while (t > 0 && a[i] < a[s[t - 1]]) {
			c[s[t - 1]] = i;
			t--;
		}
		s[t++] = i;
	}
	int ansL = -1;
	int aa, bb, cc;
	for (int i = 0; i < l; i++) {
		if (b[i] != -1 && c[b[i]] != -1) {
			int d = max(b[i] - i, c[b[i]] - b[i]);
			if (ansL == -1 || d < ansL) {
				ansL = d;
				aa = i + 1;
				bb = (b[i] % n) + 1;
				cc = (c[b[i]] % n) + 1;
			}
		}
	}
	assert(ansL != -1);
	cout << aa << " " << bb << " " << cc << "\n";
}
