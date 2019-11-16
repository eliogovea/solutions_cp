#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;

int digitsSum[N];

int best[65];

inline string intToString(int n) {
	if (n == 0) {
		return "0";
	}
	string res;
	while (n) {
		res += '0' + (n % 10);
		n /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

string solve(int s) {
	if (s < 60 && best[s] != -1) {
		return intToString(best[s]);
	}
	if (best[s % 18] != -1) {
		string ans = "";
		if (s % 18 != 0) {
            ans = intToString(best[s % 18]);
		}
		int c9 = 2 * (s / 18);
		for (int i = 0; i < c9; i++) {
			ans += "9";
		}
		return ans;
	}
	if (s > 18 && best[18 + ((s - 18) % 18)] != -1) {
		string ans = intToString(best[18 + ((s - 18) % 18)]);
		int c9 = 2 * ((s - 18) / 18);
		for (int i = 0; i < c9; i++) {
			ans += "9";
		}
		return ans;
	}
	if (s > 36 && best[36 + ((s - 36) % 18)] != -1) {
		string ans = intToString(best[36 + ((s - 36) % 18)]);
		int c9 = 2 * ((s - 36) / 18);
		for (int i = 0; i < c9; i++) {
			ans += "9";
		}
		return ans;
	}
	return "-1";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	for (int i = 1; i < N; i++) {
		digitsSum[i] = digitsSum[i / 10] + (i % 10);
	}
	for (int i = 0; i < 60; i++) {
		best[i] = -1;
	}
	for (int i = 0; i < N; i += 11) {
	    if (best[digitsSum[i]] == -1) {
            best[digitsSum[i]] = i;
	    }
	}
	int s;
	while (cin >> s && s) {
		cout << solve(s) << "\n";
	}
}
