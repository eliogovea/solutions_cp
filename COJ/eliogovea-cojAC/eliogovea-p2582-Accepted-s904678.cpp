#include <bits/stdc++.h>

using namespace std;

const int N = 50005;

struct rect {
	int w, h;
};

bool operator < (const rect &a, const rect &b) {
	if (a.w != b.w) return a.w < b.w;
	return a.h > b.h;
}

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
	long long get_min(long long x) {
		while (last + 1 < size && ch[last].y(x) >= ch[last + 1].y(x)) {
			last++;
		}
		return ch[last].y(x);
	}
} CH;

int n;
rect a[N];
long long dp[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].w >> a[i].h;
	}
	sort(a, a + n);
	int top = 0;
	for (int i = 0; i < n; i++) {
		while (top > 0 && a[i].h >= a[top - 1].h) {
			top--;
		}
		a[top++] = a[i];
	}
	CH.add((line) {a[0].h, 0});
	for (int i = 0; i < top; i++) {
		dp[i] = CH.get_min(a[i].w);
		CH.add((line) {a[i + 1].h, dp[i]});
	}
	cout << dp[top - 1] << "\n";
}
