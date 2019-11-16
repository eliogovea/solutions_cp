#include <bits/stdc++.h>

using namespace std;

const int N = 50;

const int INF = 1e9;

int n;
int a[N][N];

int usedx[N], usedy[N];
int labelx[N], labely[N], link[N];

bool dfs(int x) {
	usedx[x] = true;
	for (int y = 0; y < n; y++) {
		if (!usedy[y] && labelx[x] + labely[y] == a[x][y]) {
			usedy[y] = true;
			if (link[y] == -1 || dfs(link[y])) {
				link[y] = x;
				return true;
			}
		}
	}
	return false;
}

int match() {
	for (int i = 0; i < n; i++) {
		link[i] = -1;
		labely[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		labelx[i] = 0;
		for (int j = 0; j < n; j++) {
			labelx[i] = max(labelx[i], a[i][j]);
		}
	}
	for (int k = 0; k < n; k++) {
		while (true) {
			for (int i = 0; i < n; i++) {
				usedx[i] = usedy[i] = 0;
			}
			if (dfs(k)) break;
			int del = INF;
			for (int i = 0; i < n; i++) {
				if (usedx[i]) {
					for (int j = 0; j < n; j++) {
						if (!usedy[j]) {
							del = min(del, labelx[i] + labely[j] - a[i][j]);
						}
					}
				}
			}
			if (del == 0 || del == INF) break;
			for (int i = 0; i < n; i++) {
				if (usedx[i]) labelx[i] -= del;
				if (usedy[i]) labely[i] += del;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += labelx[i];
		res += labely[i];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int maxval = match();
	const int MAX = 100;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = MAX - a[i][j];
		}
	}
	int minval = n * MAX - match();
	cout << maxval << " " << minval << "\n";
}
