#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 10005, MAXK = 55, mod = 5000000;

int N, K;
vector<int> a, b;
int dp[MAXK][MAXN];

void update(int x, int pos, int val) {
	for (; pos <= N; pos += pos & -pos)
		dp[x][pos] = (dp[x][pos] + val) % mod;
}

int query(int x, int pos) {
	int ret = 0;
	for (; pos; pos -= pos & -pos)
		ret = (ret + dp[x][pos]) % mod;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("e.in", "r", stdin);
	cin >> N >> K;
	a.resize(N);
	b.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int i = 0; i < N; i++)
		a[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
	for (int i = 0; i < N; i++) {
		update(1, a[i], 1);
		for (int j = 2; j <= K; j++) {
			int tmp = query(j - 1, a[i] - 1);
			update(j, a[i], tmp);
		}
	}
	cout << query(K, N) << "\n";
}
