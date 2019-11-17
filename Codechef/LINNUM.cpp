#include <bits/stdc++.h>

using namespace std;

int t;
int n;
string s[105];
int x;
int cnt[105];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		cin >> x;
		ans = -1;
		for (int i = 0; i < n; i++) {
            cnt[i] = 0;
			for (int j = 0; s[i][j]; j++) {
				if (s[i][j] - '0' == x) {
					cnt[i]++;
				}
			}
			if (ans == -1 || cnt[i] > cnt[ans]) {
				ans = i;
			}
		}
		cout << s[ans] << "\n";
	}
}

