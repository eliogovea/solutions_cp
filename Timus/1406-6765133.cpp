// Problem: pace=1&num=1406
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

string s;

bool get(int len, int need_sum, string &res) {
	if (need_sum < 0 || 9 * len < need_sum) {
		return false;
	}
	res = "";
	int cnt = need_sum / 9;
	for (int i = 0; i < cnt; i++) {
		res += '9';
	}
	need_sum %= 9;
	if (need_sum != 0) {
		res += '0' + need_sum;
	}
	while (res.size() < len) {
		res += '0';
	}
	reverse(res.begin(), res.end());
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int n = s.size();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += s[i] - '0';
	}
	int cur_sum = 0;
	string cur_num = "";
	string aux;
	string ans = "-1";
	for (int i = 0; i + 1 < n; i++) {
		for (int j = '9'; j > s[i]; j--) {
			if (get(n - i - 1, sum - cur_sum - (j - '0'), aux)) {
				ans = cur_num + " " + aux;
				ans[i] = j;
			}
		}
		cur_num += s[i];
		cur_sum += s[i] - '0';
	}
	cout << ans << "\n";
}
