// 2016-2017 CT S03E06: Codeforces Trainings Season 3 Episode 6
// 101124H

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, k;
int up[N];
int down[N];
int pos[N];

int next[35][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> up[i] >> down[i];
		pos[up[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		next[0][i] = pos[down[i]];
	}
	for (int i = 1; i <= 30; i++) {
		for (int x = 1; x <= n; x++) {
			next[i][x] = next[i - 1][next[i - 1][x]];
		}
	}
	for (int i = 1; i <= k; i++) {
		int x, t;
		cin >> x >> t;
		for (int i = 0; i <= 30; i++) {
			if (t & (1 << i)) {
				x = next[i][x];
			}
		}
		cout << x << "\n";
	}
}
