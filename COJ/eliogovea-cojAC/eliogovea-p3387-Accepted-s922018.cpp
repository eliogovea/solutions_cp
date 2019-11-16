#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char ch['z' + 5];

int n;
string a, b;

struct item {
	bool ok;
	int x;
};

bool operator < (const item &a, const item &b) {
	if (!a.ok && b.ok) {
		return false;
	}
	if (a.ok && !b.ok) {
		return true;
	}
	if (a.ok && b.ok) {
		if (a.x < b.x) {
			return true;
		} else {
			return false;
		}
	}
	return false;
}

bool solved[N][N][5];
item dp[N][N][5];

item solve(int s, int e, int rev) {
	int len = e - s;
	if (len == 0) {
		return (item) {true, 0};
	}
	if (solved[s][e][rev]) {
		return dp[s][e][rev];
	}
	solved[s][e][rev] = true;
	if (!rev) {
		item v1 = (item) {false, 0};
		item v2 = (item) {false, 0};
		if (a[s] == b[n - len]) {
			item tmp = solve(s + 1, e, false);
			if (tmp < v1) {
				v1 = tmp;
			}
		}
		if (ch[a[e - 1]] == b[n - len]) {
			item tmp = solve(s, e - 1, true);
			tmp.x++;
			if (tmp < v2) {
				v2 = tmp;
			}
		}
		if (v1 < v2) {
			dp[s][e][rev] = v1;
		} else {
			dp[s][e][rev] = v2;
		}
	} else {
		item v1 = (item) {false, 0};
		item v2 = (item) {false, 0};
		if (ch[a[e - 1]] == b[n - len]) {
			item tmp = solve(s, e - 1, true);
			if (tmp < v1) {
				v1 = tmp;
			}
		}
		if (a[s] == b[n - len]) {
			item tmp = solve(s + 1, e, false);
			tmp.x++;
			if (tmp < v2) {
				v2 = tmp;
			}
		}
		if (v1 < v2) {
			dp[s][e][rev] = v1;
		} else {
			dp[s][e][rev] = v2;
		}
	}
	return dp[s][e][rev];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	cin >> n >> a >> b;

	ch['o'] = 'o';
	ch['v'] = 'v';
	ch['w'] = 'w';
	ch['x'] = 'x';
	ch['b'] = 'd';
	ch['d'] = 'b';
	ch['p'] = 'q';
	ch['q'] = 'p';

	for (int i = 0; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			solved[i][j][0] = solved[i][j][1] = false;
		}
	}
	item ans = solve(0, n, 0);
	if (!ans.ok) {
        cout << "-1\n";
	} else {
        cout << ans.x << "\n";
	}
}
