#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 18;

int tc, n, m, dp[1 << MAXN][MAXN];
vector<pii> pts;
pii pi;
string str;

int dist(pii &a, pii &b) {
	int d1 = abs(a.first - b.first);
	int d2 = abs(a.second - b.second);
	return min(d1, d2) + abs(d1 - d2);
}

void mini(int a, int &b) {
	if (a < b) b = a;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> tc;
	for (int c = 1; c <= tc; c++) {
		cin >> n >> m;
		pts.clear();
		for (int i = 0; i < n; i++) {
			cin >> str;
			for (int j = 0; j < m; j++) {
				if (str[j] == 'x') pi = make_pair(i, j);
				if (str[j] == 'g') pts.push_back(make_pair(i, j));
			}
		}
		int s = pts.size();
		for (int mask = 0; mask < (1 << s); mask++)
			for (int i = 0; i < s; i++)
				dp[mask][i] = 1 << 29;
		for (int i = 0; i < s; i++)
			dp[1 << i][i] = dist(pts[i], pi);
		for (int mask = 1; mask < (1 << s); mask++)
			for (int i = 0; i < s; i++)
				if (mask & (1 << i))
					for (int j = 0; j < s; j++)
						if (!(mask & (1 << j)))
							mini(dp[mask][i] + dist(pts[i], pts[j]), dp[mask | (1 << j)][j]);

		int sol = 1 << 29;
		for (int i = 0; i < s; i++)
			mini(dp[(1 << s) - 1][i] + dist(pts[i], pi), sol);
		cout << "Case " << c << ": ";
		if (sol == 1 << 29) cout << "0\n";
		else cout << sol << '\n';
	}
}
