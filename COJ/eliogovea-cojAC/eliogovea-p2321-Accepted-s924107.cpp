#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const double EPS = 1e-9;

int t;
int k;
double n;
double f[15];

struct cmp {
	bool operator () (const double &a, const double &b) {
		if (a < b && fabs(b - a) > EPS) {
			return true;
		}
		return false;
	}
};

map <double, bool, cmp> dp;
map <double, bool, cmp>::iterator it;

bool solve(double x) {
	if (x <= 1.0 + 1e-14) {
		return false;
	}
	it = dp.find(x);

	if (it != dp.end()) {
		return it->second;
	}

	for (int i = 0; i < k; i++) {
		if (!solve(x * f[i])) {
			dp[x] = true;
			return true;
		}
	}
	dp[x] = false;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> f[i];
		}
		sort(f, f + k);
		dp.clear();
		cout << (!solve(n) ? "Mikael" : "Nils") << "\n";
	}
}
