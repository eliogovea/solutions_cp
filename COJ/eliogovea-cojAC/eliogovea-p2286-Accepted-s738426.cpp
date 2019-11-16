#include <iostream>
#include <vector>

using namespace std;

const int N = 1000;

const int n = 16;
int id[N][N];
vector<int> g[N];
int dp[30][N]; 

int main() {
	int cur = 1;
	for (int i = 1; i <= 2 * n - 1; i++) {
		int tmp = n - 1;
		if (i <= n) tmp += i;
		else tmp += (2 * n - i);
		for (int j = 1; j <= tmp; j++)
			id[i][j] = cur++;
		for (int j = 1; j <= tmp; j++) {
			if (id[i][j - 1]) g[id[i][j]].push_back(id[i][j - 1]);
			if (id[i][j + 1]) g[id[i][j]].push_back(id[i][j + 1]);
			if (i <= n) {
				if (id[i - 1][j]) {
					g[id[i][j]].push_back(id[i - 1][j]);
					g[id[i - 1][j]].push_back(id[i][j]);
				}
				if (id[i - 1][j - 1]) {
					g[id[i][j]].push_back(id[i - 1][j - 1]);
					g[id[i - 1][j - 1]].push_back(id[i][j]);
				}
			} else {
				if (id[i - 1][j]) {
					g[id[i][j]].push_back(id[i - 1][j]);
					g[id[i - 1][j]].push_back(id[i][j]);
				}
				if (id[i - 1][j + 1]) {
					g[id[i][j]].push_back(id[i - 1][j + 1]);
					g[id[i - 1][j + 1]].push_back(id[i][j]);
				}
			}
		}
	}
	for (int i = 0; i < 15; i++)
    for (int j = 1; j <= cur; j++)
      dp[i][j] = 0;
	dp[0][id[n][n]] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= cur; j++)
			for (int k = 0; k < g[j].size(); k++)
				dp[i + 1][g[j][k]] += dp[i][j];
	}
	int tc, x;
	cin >> tc;
	while (tc--) {
        cin >> x;
        cout << dp[x][id[n][n]] << "\n";
	}
}
