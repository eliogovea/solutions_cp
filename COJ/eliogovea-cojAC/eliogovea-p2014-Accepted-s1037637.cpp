#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int t;
string s;
int n;
int need;
bool solved[N][N];
bool good[N][N];
char value[N][N];

bool dfs(int pos, int cur) {
	if (cur > need) {
		return false;
	}
	if (pos == n) {
		return (cur == need);
	}
	if (solved[pos][cur]) {
		return good[pos][cur];
	}
	solved[pos][cur] = true;
	if (dfs(pos + 1, cur + (s[pos] != '0'))) {
		good[pos][cur] = true;
		value[pos][cur] = '0';
		return true;
	}
	if (dfs(pos + 1, cur + (s[pos] != '1'))) {
		good[pos][cur] = true;
		value[pos][cur] = '1';
		return true;
	}
	good[pos][cur] = false;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (int c = 1; c <= t; c++) {
		cin >> s >> need;
		n = s.size();
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= need; j++) {
				solved[i][j] = false;
			}
		}
		assert(dfs(0, 0));
		string ans;
		int d = 0;
		for (int i = 0; i < n; i++) {
			ans += value[i][d];
			d += (value[i][d] != s[i]);
		}
		cout << "Case #" << c << ": " << ans << "\n";
	}
}
