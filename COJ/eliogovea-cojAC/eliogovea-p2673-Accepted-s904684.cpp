#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

struct line {
	long long m, n;
	long long y(long long x) {
		return m * x + n;
	}
};

inline long double inter(line a, line b) {
	return (long double)(a.n - b.n) / (long double)(b.m - a.m);
}

struct ConvexHullTrick {
	line ch[N];
	int size = 0;
	int last = 0;
	void add(line l) {
		while (size > 1 && inter(l, ch[size - 1]) <= inter(l, ch[size - 2])) {
			size--;
		}
		ch[size++] = l;
	}
	long long get_max(long long x) {
		while (last + 1 < size && ch[last + 1].y(x) >= ch[last].y(x)) {
			last++;
		}
		return ch[last].y(x);
	}
} CH;

int n;
long long a, b, c;
long long x[N];
long long sx[N];
long long dp[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a >> b >> c;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		sx[i] = sx[i - 1] + x[i];
	}
	CH.add((line){0, c});
	for (int i = 1; i <= n; i++) {
		dp[i] = CH.get_max(sx[i]) + a * sx[i] * sx[i] + b * sx[i];
		CH.add((line) {-2LL * a * sx[i], dp[i] + a * sx[i] * sx[i] - b * sx[i] + c});
	}
	cout << dp[n] << "\n";
}
