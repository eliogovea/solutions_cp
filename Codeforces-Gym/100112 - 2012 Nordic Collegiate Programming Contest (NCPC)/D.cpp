// 2012 Nordic Collegiate Programming Contest (NCPC)
// 100112D

#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int w[105], m[105];

inline int get_m(int first, int second) {
	int res = second <= s.size() ? m[second - 1] : m[s.size()];
	if (first <= s.size() && s[first - 1] == 'M') res--;
	return res;
}

inline int get_w(int first, int second) {
	int res = second <= s.size() ? w[second - 1] : w[s.size()];
	if (first <= s.size() && s[first - 1] == 'W') res--;
	return res;
}

inline int total(int first, int second) {
	if (first > s.size()) return s.size();
	return get_w(first, second) + get_m(first, second);
}

int ans = 0;

bool mark[105][105];

void dfs(int first, int second) {
	if (abs(get_w(first, second) - get_m(first, second)) > n) return;
	mark[first][second] = true;
	ans = max(ans, total(first, second));
	if (first > s.size()) return;
	if (first + 1 == second && !mark[first + 1][second]) dfs(first + 1, second + 1);
	if (first + 1 < second && !mark[first + 1][second]) dfs(first + 1, second);
	if (second <= s.size() && !mark[first][second + 1]) dfs(first, second + 1);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= s.size(); i++) {
		w[i] = w[i - 1];
		m[i] = m[i - 1];
		if (s[i - 1] == 'M') m[i]++;
		if (s[i - 1] == 'W') w[i]++;
	}
	dfs(1, 2);
	cout << ans << "\n";
}
