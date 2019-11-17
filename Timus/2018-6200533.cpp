// Problem: pace=1&num=2018
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 50005;
const int X = 305;
const int mod = 1e9 + 7;

int n, a, b;
int SA[N];
int SB[N];

/*
	SA[n] cantidad de secuencias que terminan en 1(s)
	SB[n] cantidad de secuencias que terminan en 2(s)
	SA[n] = SB[n - 1] + SB[n - 2] + ... + SB[n - b];
	SB[n] = SA[n - 1] + SA[n - 2] + ... + SA[n - a];
*/

inline void add(int &a, int b) {
	a = (a + b) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> a >> b;
	SA[0] = 1;
	SB[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= b; j++) {
			if (j > i) {
				break;
			}
			add(SA[i], SB[i - j]);
		}
		for (int j = 1; j <= a; j++) {
			if (j > i) {
				break;
			}
			add(SB[i], SA[i - j]);
		}
	}
	int ans = 0;
	add(ans, SA[n]);
	add(ans, SB[n]);
	cout << ans << "\n";
}