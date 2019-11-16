#include <bits/stdc++.h>

using namespace std;

int calcNextMask(int mask, int d) {
    if (mask == 0 && d == 0) {
        return 0;
    }
	int res = 0;
	for (int i = 0; i < 11; i++) {
		if (mask & (1 << i)) {
			int v = (10 * i + d) % 11;
			res |= (1 << v);
		}
	}
	res |= (1 << d);
	return res;
}

int nextMask[(1 << 11) + 5][15];

long long dp[25][(1 << 11) + 5][3];

long long getDP(int len, int mask, bool ok) {
	if (len == 0) {
		return ok ? 1 : 0;
	}
	if (dp[len][mask][ok] != -1) {
		return dp[len][mask][ok];
	}
	long long res = 0;
	for (int d = 0; d < 10; d++) {
		res += getDP(len - 1, nextMask[mask][d], ok || (nextMask[mask][d] & 1));
	}
	dp[len][mask][ok] = res;
	return res;
}

long long calc(long long x) {
	if (x == 0) {
		return 0;
	}
	vector <int> v;
	while (x > 0) {
		v.push_back(x % 10LL);
		x /= 10LL;
	}
	reverse(v.begin(), v.end());

	long long res = 0;
	int mask = 0;
	bool ok = false;
	for (int i = 0; i < v.size(); i++) {
		for (int d = 0; d < v[i]; d++) {
			res += getDP(v.size() - (i + 1), nextMask[mask][d], ok || (nextMask[mask][d] & 1));
		}
		mask = nextMask[mask][v[i]];
		ok = (ok || (mask & 1));
	}
	if (ok) {
		res++;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

	for (int m = 0; m < (1 << 11); m++) {
        for (int d = 0; d < 10; d++) {
            nextMask[m][d] = calcNextMask(m, d);
        }
	}

	for (int l = 0; l < 20; l++) {
		for (int m = 0; m < (1 << 11); m++) {
			for (int o = 0; o < 2; o++) {
				dp[l][m][o] = -1;
			}
		}
	}
	int t;
	long long a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << calc(b) - calc(a - 1) << "\n";
	}
}
