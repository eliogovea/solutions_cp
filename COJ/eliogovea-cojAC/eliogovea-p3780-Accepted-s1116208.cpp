#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 9;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

inline int power(int x, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = mul(res, x);
		}
		x = mul(x, x);
		n >>= 1;
	}
	return res;
}

const int N = 1001;
const int ALPH = 'z' - 'a' + 1;
// const int ALPH = 3;
int comb[N + 5][N + 5];
int comb2[N + 5][N + 5];
int f[50];
string s;
int k;
int answer;
int solved[ALPH + 5][100][N + 2], ttt;
int dp[ALPH + 5][100][N + 2];

int solve(int pos, int cnt, int cur) {
    // cerr << "enter: " << pos << " " << cnt << " " << cur << "\n";
	if (pos == ALPH) {
        if (cur == k) {
            return 1;
        }
        return 0;
	}
	if (solved[pos][cnt][cur] == ttt) {
		return dp[pos][cnt][cur];
	}
	solved[pos][cnt][cur] = ttt;
	int res = 0;
	for (int use = 0; use <= f[pos]; use++) {
		if (cur * comb[cnt + use][use] > k) {
			break;
		}
		if (((k / cur) % comb[cnt + use][use]) == 0) {
            // int v = mul(comb2[f[pos]][use], solve(pos + 1, cnt + use, cur * comb[cnt + use][use]));
            // cerr << "from: " << pos << " " << cnt << " " << cur << " -> ";
            // cerr << "to: " << pos + 1 << " " << cnt + use << " " << cur * comb[cnt + use][use] << " : ";
            // cerr << "add " << v << "\n";
			add(res, mul(comb2[f[pos]][use], solve(pos + 1, cnt + use, cur * comb[cnt + use][use])));
		}
	}
	// cerr << pos << " " << cnt << " " << cur << " " << res << "\n";
	dp[pos][cnt][cur] = res;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < N; i++) {
		comb[i][0] = comb[i][i] = 1;
		comb2[i][0] = comb2[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
			if (comb[i][j] > N) {
				comb[i][j] = N;
			}
			comb2[i][j] = comb2[i - 1][j - 1];
			add(comb2[i][j], comb2[i - 1][j]);
		}
	}
	while (cin >> s >> k) {

		ttt++;
		for (int i = 0; i < ALPH; i++) {
			f[i] = 0;
		}
		for (int i = 0; i < s.size(); i++) {
			f[s[i] - 'a']++;
		}
		answer = 0;
		if (k == 1) {
			for (int i = 0; i < ALPH; i++) {
				int v = power(2, f[i]); add(v, MOD - 1);
				add(answer, v);
			}
			// add(answer, 1);
			cout << answer << "\n";
		} else {
			// sort(f, f + c);
			cout << solve(0, 0, 1) << "\n";
		}
	}
}
