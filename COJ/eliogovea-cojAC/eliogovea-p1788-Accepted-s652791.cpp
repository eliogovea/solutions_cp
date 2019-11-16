#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 305;

int r, c, k,a[MAXN][MAXN], sol;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (cin >> r >> c >> k && (r | c | k)) {
		sol = 1 << 29;
		for (int i = 1; i <= r; i++) {
			cin >> str;
			for (int j = 1; j <= c; j++) {
        if (str[j - 1] == '.') a[i][j] = 1;
				else a[i][j] = 0;
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			}
		}
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= i; j++)
				for (int lo = 1, hi = 1; hi <= c; hi++)
					while (a[i][hi] - a[i][lo - 1] - a[j - 1][hi] + a[j - 1][lo - 1] >= k) {
						sol = min(sol, (i - j + 1) * (hi - lo + 1));
						lo++;
					}
		cout << sol << "\n";
	}
}
