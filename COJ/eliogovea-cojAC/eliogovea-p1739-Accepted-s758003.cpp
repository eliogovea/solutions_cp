#include <iostream>

using namespace std;

const int N = 2005;

string s;
bool dp[N][N];
long long start[N], finish[N];

int main() {
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
	}
	for (int i = 1; i < n; i++) {
		dp[i - 1][i] = (s[i - 1] == s[i]);
	}
	for (int l = 3; l <= n; l++) {
		for (int i = 0; i + l - 1 < n; i++) {
			dp[i][i + l - 1] = (dp[i + 1][i + l - 2] && (s[i] == s[i + l - 1]));
		}
	}
	long long t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (dp[i][j]) {
				t++;
				start[i]++;
				finish[j]++;
			}
		}
	}
	t = (t * (t - 1LL)) / 2LL;
	for (int i = 1; i < n; i++) {
		finish[i] += finish[i - 1];
	}
	long long x = 0;
	for (int i = 1; i < n; i++) {
		x += start[i] * finish[i - 1];
	}
	long long ans = t - x;
	cout << ans << "\n";
}
