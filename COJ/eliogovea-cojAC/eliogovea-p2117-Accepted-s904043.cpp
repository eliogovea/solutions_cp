#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

struct line {
	long long m, n;
	long long y(long long x) {
		return m * x + n;
	}
};

inline long double inter(line a, line b) {
	return (long double)(b.n - a.n) / (long double)(a.m - b.m);
}

struct ConvexHullTrick {
	line ch[N];
	int size;
	void clear() {
		size = 0;
	}
	void add(line l) {
		while (size > 1 && inter(l, ch[size - 1]) < inter(l, ch[size - 2])) {
			size--;
		}
		ch[size++] = l;
	}
	long long get_min(long long x) {
		int id = 0;
		int lo = 1;
		int hi = size - 1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (ch[mid].y(x) < ch[mid - 1].y(x)) {
				id = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		return ch[id].y(x);
	}
} CH;

int n, k, x[N], w[N];
long long sw[N];
long long swx[N];
long long dp[N][N];

bool read_case() {
	if (!(cin >> n >> k)) {
		return false;
	}
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> w[i];
	}
	return true;
}

long long solve() {
	for (int i = 1; i <= n; i++) {
		sw[i] = sw[i - 1] + w[i];
		swx[i] = swx[i - 1] + w[i] * x[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[1][i] = x[i] * sw[i - 1] - swx[i - 1];
	}
	long long res = dp[1][n];
	for (int i = 2; i <= k; i++) {
		CH.clear();
		for (int j = i; j <= n; j++) {
			CH.add((line) {-sw[j - 1], swx[j - 1] + dp[i - 1][j - 1]});
			long long val = CH.get_min(x[j]);
			dp[i][j] = val + x[j] * sw[j] - swx[j];
		}
		res = min(res, dp[i][n]);
	}
	/*for (int i = 1; i <= k; i++) {
		cout << i << " " << dp[i][n] << "\n";
	}*/
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (read_case()) {
		cout << solve() << "\n";
	}
}
