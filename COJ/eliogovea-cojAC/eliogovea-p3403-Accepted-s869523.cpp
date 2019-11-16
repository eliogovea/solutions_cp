#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n;
string s;

int next[33][N];

int q, start, len;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> next[0][i];
	}
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= n; j++) {
			next[i][j] = next[i - 1][next[i - 1][j]];
		}
	}
	cin >> q;
	while (q--) {
		cin >> start >> len;
		if (len <= 20) {
			for (int i = 0; i < len; i++) {
				cout << s[start - 1];
				start = next[0][start];
			}
			cout << "\n";
		} else {
			int x = start;
			for (int i = 30; i >= 0; i--) {
				if ((len - 10) & (1 << i)) x = next[i][x];
			}
			for (int i = 0; i < 10; i++) {
				cout << s[start - 1];
				start = next[0][start];
			}
			cout << "...";
			for (int i = 0; i < 10; i++) {
				cout << s[x - 1];
				x = next[0][x];
			}
			cout << "\n";
		}
	}
}
