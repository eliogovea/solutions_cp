#include <bits/stdc++.h>

using namespace std;

const int N = 50005;

struct Rect {
	int w, h;
};

bool operator < (const Rect &a, const Rect &b) {
	if (a.w != b.w) return a.w < b.w;
	return a.h > b.h;
}
struct Line {
		long long m, n;
		long long y(long long x) {
			return m * x + n;
		}
	};

struct ConvexHullTrick {
	Line ch[N];
	int size;
	void clear() {
		size = 0;
	}
	bool ok(Line a, Line b, Line c) {
		// (a.n - c.n) / (c.m - a.m)
		// (b.n - c.n) / (c.m - b.m)
		return (b.n - c.n) * (c.m - a.m) > (a.n - c.n) * (c.m - b.m);
	}
	void add(Line l) {
		while (size > 1 && !ok(ch[size - 2], ch[size - 1], l)) {
			size--;
		}
		ch[size++] = l;
	}
	long long get_min(long long x) {
		int lo = 1;
		int hi = size - 1;
		int pos = 0;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (ch[mid].y(x) <= ch[mid - 1].y(x)) {
				pos = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		return ch[pos].y(x);
	}
} CH;

int n;
Rect a[N];
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
	CH.clear();
	CH.add((Line) {a[0].h, 0});
	for (int i = 0; i < top; i++) {
		dp[i] = CH.get_min(a[i].w);
		CH.add((Line) {a[i + 1].h, dp[i]});
	}
	cout << dp[top - 1] << "\n";
}
