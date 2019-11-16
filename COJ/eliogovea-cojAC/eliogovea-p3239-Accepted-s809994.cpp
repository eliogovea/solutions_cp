#include <bits/stdc++.h>

using namespace std;

int tc, n;
string s;
int ans[100005];

stack<int> S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		while (!S.empty()) {
			S.pop();
		}
		for (int i = 0; i < n; i++) {
			ans[i] = -1;
			while (!S.empty() && s[S.top()] < s[i]) {
				ans[S.top()] = i + 1;
				S.pop();
			}
			S.push(i);
		}
		for (int i = 0; i < n; i++) {
			cout << ans[i];
			if (i + 1 < n) {
				cout << " ";
			}
		}
		cout << "\n";
	}
}
