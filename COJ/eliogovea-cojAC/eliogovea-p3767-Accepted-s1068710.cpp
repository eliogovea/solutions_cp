#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL N = 55;

const LL INF = 1e9;

int t;
int n, m, bo;
int e[55], s[55];
LL a[N][N];

LL usedx[N], usedy[N];
LL labelx[N], labely[N], link[N];

bool dfs(LL x) {
	usedx[x] = true;
	for (LL y = 0; y < n; y++) {
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

LL match() { // hungarian
	for (LL i = 0; i < n; i++) {
		link[i] = -1;
		labely[i] = 0;
	}
	for (LL i = 0; i < n; i++) {
		labelx[i] = 0;
		for (LL j = 0; j < n; j++) {
			labelx[i] = max(labelx[i], a[i][j]);
		}
	}
	for (LL k = 0; k < n; k++) {
		while (true) {
			for (LL i = 0; i < n; i++) {
				usedx[i] = usedy[i] = 0;
			}
			if (dfs(k)) break;
			LL del = INF;
			for (LL i = 0; i < n; i++) {
				if (usedx[i]) {
					for (LL j = 0; j < n; j++) {
						if (!usedy[j]) {
							del = min(del, labelx[i] + labely[j] - a[i][j]);
						}
					}
				}
			}
			if (del == 0 || del == INF) break;
			for (LL i = 0; i < n; i++) {
				if (usedx[i]) labelx[i] -= del;
				if (usedy[i]) labely[i] += del;
			}
		}
	}
	LL res = 0;
	for (LL i = 0; i < n; i++) {
		res += labelx[i];
		res += labely[i];
	}
	return res;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	cin >> t;
	while (t--) {
		cin >> n >> bo >> m;
		for (LL i = 0; i < n; i++) {
			cin >> e[i];
		}
		for (LL i = 0; i < n; i++) {
			cin >> s[i];
		}
		sort(e, e + n);
		sort(s, s + n);
		bool ok = true;
		for (LL i = 0; i < n; i++) {
			if (e[i] >= s[i]) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout << "impossible\n";
			continue;
		}
		for (LL i = 0; i < n; i++) {
			for (LL j = 0; j < n; j++) {
				if (e[i] < s[j]) {
					a[i][j] = min(m, (s[j] - e[i] - bo) * (s[j] - e[i] - bo));
				} else {
					a[i][j] = -INF;
				}
			}
		}
		LL ansMax = match();
		for (LL i = 0; i < n; i++) {
			for (LL j = 0; j < n; j++) {
				if (e[i] < s[j]) {
					a[i][j] = m - min(m, (s[j] - e[i] - bo) * (s[j] - e[i] - bo));
				} else {
					a[i][j] = -INF;
				}
			}
		}
		LL ansMin = n * m - match();
		cout << ansMin << " " << ansMax << "\n";
	}
}
