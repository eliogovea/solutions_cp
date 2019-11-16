#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector <int> getPrimes(int limit) {
	vector <bool> sieve(limit);
	sieve[0] = sieve[1] = true;
	for (int i = 2; i * i <= limit; i++) {
		if (!sieve[i]) {
			for (int j = i * i; j <= limit; j += i) {
				sieve[j] = true;
			}
		}
	}
	vector <int> res;
	for (int i = 2; i <= limit; i++) {
		if (!sieve[i]) {
			res.push_back(i);
		}
	}
	return res;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	const int N = 40;

	vector <int> p = getPrimes(N);

	vector <int> mask(N);
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < p.size(); j++) {
			if (i % p[j] == 0) {
				mask[i] |= (1 << j);
			}
		}
	}

	int n;
	int cas = 1;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		vector <int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		vector <vector <int> > dp(n + 1, vector <int> (1 << p.size(), INF));
		vector <vector <int> > trace(n + 1, vector <int> (1 << p.size(), INF));
		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int m = 0; m < (1 << p.size()); m++) {
				if (dp[i][m] != INF) {
                    //cerr << i << " " << m << " " << dp[i][m] << "\n";
					for (int x = 1; x < N; x++) {
                        //cerr << "  " << x << " " << mask[x] << "\n";
						if (!(m & mask[x])) {
							if (dp[i][m] + abs(v[i] - x) < dp[i + 1][m | mask[x]]) {
								dp[i + 1][m | mask[x]] = dp[i][m] + abs(v[i] - x);
								trace[i + 1][m | mask[x]] = x;
							}
						}
					}
				}
			}
		}
		int bestM = -1;
		for (int m = 0; m < (1 << p.size()); m++) {
            //cerr << m << " " << dp[n][m] << "\n";
			if (bestM == -1 || dp[n][m] < dp[n][bestM]) {
				bestM = m;
			}
		}

		vector <int> ans(n);
		for (int i = n; i > 0; i--) {
            //cerr << i << " " << bestM << "\n";
			ans[i - 1] = trace[i][bestM];
			bestM ^= mask[trace[i][bestM]];
		}
		assert(bestM == 0);
		cout << "Case #" << cas++ << ":";
		for (int i = 0; i < n; i++) {
			cout << " " << ans[i];
		}
		cout << "\n";
	}
}
