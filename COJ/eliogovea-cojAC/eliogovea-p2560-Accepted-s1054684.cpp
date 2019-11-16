#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

const int N = 1005;

int n;
int dp[N][N][5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int firstStack = 1; firstStack <= n; firstStack++) {
		dp[firstStack][firstStack][(firstStack & 1) ^ 1] = 1;
	}
	for (int total = 1; total <= n; total++) {
		for (int lastStack = 1; lastStack <= total; lastStack++) {
			for (int odd = 0; odd < 2; odd++) {
				if (dp[total][lastStack][odd]) {
					for (int newStack = lastStack; newStack + total <= n; newStack++) {
						add(dp[total + newStack][newStack][odd ^ ((newStack & 1) ^ 1)], dp[total][lastStack][odd]);
					}
				}
			}
		}
	}
	int answer = 0;
	for (int lastStack = 1; lastStack <= n; lastStack++) {
		add(answer, dp[n][lastStack][1]);
	}
	cout << answer << "\n";
}
