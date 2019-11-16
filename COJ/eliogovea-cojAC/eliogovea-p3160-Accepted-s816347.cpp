#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n;
string a, b;
int ca[N], cb[N];
bool dp[N][N];
int rec[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		ca[i] = ca[i - 1] + (a[i - 1] == '0');
		cb[i] = cb[i - 1] + (b[i - 1] == '0');
	}
	dp[0][0] = true;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (dp[i][j]) {
				if (i + 1 <= n) {
					int cer = ca[i + 1] + cb[j];
					int uno = i + 1 + j - cer;
					if (abs(cer - uno) <= 1) {
						dp[i + 1][j] = true;
						rec[i + 1][j] = 1;
					}
				}
				if (j + 1 <= n) {
					int cer = ca[i] + cb[j + 1];
					int uno = i + j + 1 - cer;
					if (abs(cer - uno) <= 1) {
						dp[i][j + 1] =  true;
						rec[i][j + 1] = 2;
					}
				}
			}
		}
	}
	vector<int> ans;
	int x = n;
	int y = n;
	while (true) {
		ans.push_back(rec[x][y]);
		if (rec[x][y] == 1) {
			x--;
		} else {
			y--;
		}
		if (x == 0 && y == 0) {
			break;
		}
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
}
