#include <bits/stdc++.h>

using namespace std;

const int inf = 1 << 29;

const int N = 16;

int n;
int l[N], ph[N];

int len[N][1 << N];
int fre[N][1 << N];

void mini(int &a, int b) {
	if (b < a) {
		a = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> ph[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << n); j++) {
			len[i][j] = inf;
		}
	}
	for (int i = 0; i < n; i++) {
		len[i][1 << i] = l[i];
		fre[i][1 << i] = l[i] - 1;
	}
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				for (int k = 0; k < n; k++) {
					if (!(i & (1 << k))) {
						if (abs(ph[j] - ph[k]) >= 3) {
							if (len[j][i] + l[k] < len[k][i | (1 << k)]) {
								len[k][i | (1 << k)] = len[j][i] + l[k];
								fre[k][i | (1 << k)] = l[k] - 1;
							}
						} else {
							if (fre[j][i] >= l[k] - 1) {
								if (len[j][i] + 1 < len[k][i | (1 << k)]) {
									len[k][i | (1 << k)] = len[j][i] + 1;
									fre[k][i | (1 << k)] = 0;
								}
							} else {
								if (len[j][i] + l[k] - fre[j][i] < len[k][i | (1 << k)]) {
									len[k][i | (1 << k)] = len[j][i] + l[k] - fre[j][i];
									fre[k][i | (1 << k)] = l[k] - fre[j][i] - 1;
								}
							}
						}
					}
				}
			}
		}
	}
	int ans = inf;
	for (int i = 0; i < n; i++) {
		if (len[i][(1 << n) - 1] < ans) {
			ans = len[i][(1 << n) - 1];
		}
	}
	cout << ans << "\n";
}
