#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int tc, N;
vector<int> a, b;
long long dp[3][100005];

void update(int x, int pos, long long val) {
	for (; pos <= N; pos += pos & -pos)
		dp[x][pos] += val;
}

long long query(int x, int pos) {
	long long ret = 0;
	for (; pos; pos -= pos & -pos)
		ret += dp[x][pos];
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("e.in", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> N;
		a.clear(); a.resize(N);
		b.clear(); b.resize(N);

		for (int i = 0; i < 3; i++)
			for (int j = 0; j <= N; j++)
				dp[i][j] = 0;

		for (int i = 0; i < N; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		for (int i = 0; i < N; i++) {
			a[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
			for (int j = 1; j < 3; j++) {
				long long tmp = query(j - 1, N) - query(j - 1, a[i]);
				update(j, a[i], tmp);
			}
			update(0, a[i], 1);
		}
		cout << query(2, N) << "\n";
	}
}
