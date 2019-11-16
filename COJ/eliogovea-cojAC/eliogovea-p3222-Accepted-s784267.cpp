#include <bits/stdc++.h>

using namespace std;
/*
const int MAXN = 100010;
vector<int> g[MAXN];


int root;
int main(){ freopen("dat.txt","r",stdin);
	int n;
	while(cin >> n, n){
		for(int i=0;i<n;i++){

		}
	}
}
*/
const int D = 22;
const int N = 2005;

int n, d, a[N], sum[N];
int dp[D][N];

int f(int x) {
	int r = 10 * (x / 10);
	if (x % 10 >= 5) {
		r += 10;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
	}

	for (int i = 0; i <= d; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = 1 << 29;
		}
	}

	for (int i = 1; i <= n; i++) {
		dp[0][i] = f(sum[i]);
	}

	for (int i = 0; i <= d; i++) {
		dp[i][0] = 0;
	}
	for (int i = 1; i <= d; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < j; k++) {
				int tmp = dp[i - 1][k] + f(sum[j] - sum[k]);
				if (tmp < dp[i][j]) {
					dp[i][j] = tmp;
				}
				//cout << i << " " << j << " " << dp[i][j] << "\n";
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= d; i++) {
		if (ans == -1 || dp[i][n] < ans) {
			ans = dp[i][n];
		}
	}
	cout << ans << "\n";
}