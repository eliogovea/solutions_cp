#include <iostream>

using namespace std;

int tc;
string a, b, c;
bool dp[205][205];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	for (int cas = 1; cas <= tc; cas++) {
		cin >> a >> b >> c;
		for (int i = 0; i <= a.size(); i++) {
			for (int j = 0; j <= b.size(); j++) {
				dp[i][j] = false;
			}
		}
		dp[0][0] = true;
		for (int i = 0; i <= a.size(); i++) {
			for (int j = 0; j <= b.size(); j++) {
				if (dp[i][j]) {
					if (i < a.size() && a[i] == c[i + j]) {
						dp[i + 1][j] = true;
					}
					if (j < b.size() && b[j] == c[i + j]) {
						dp[i][j + 1] = true;
					}
				}
			}
		}
		cout << "Data set " << cas << ": ";
		cout << (dp[a.size()][b.size()] ? "yes" : "no") << "\n";
	}

}
