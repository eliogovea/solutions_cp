// 2010-2011 ACM-ICPC, NEERC, Southern Subregional Contest
// 101246E

#include <bits/stdc++.h>

using namespace std;

int n, k;
int l[250][250];
int r[250];

bool dp[250][250];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    //freopen("dat.txt", "r", stdin);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> l[i][j];
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> r[i];
	}
	dp[0][0] = true;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j]) {
				for (int k = 0; k < n; k++) {
					if (r[i] == l[j][k]) {
						dp[i + 1][k] = true;
					}
				}
			}
		}
	}
	vector <int> ans;
	for (int i = 0; i < n; i++) {
		if (dp[k][i]) {
			ans.push_back(i + 1);
		}
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i + 1 < ans.size()) {
			cout << " ";
		}
	}
	cout << "\n";
}
