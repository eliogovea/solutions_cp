#include <bits/stdc++.h>

using namespace std;

int sum[100][100][100];

vector<int> vx, vy, vz;

int n, k;
int x[100], y[100], z[100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> z[i];
		cin >> x[n + i] >> y[n + i] >> z[n + i];
		vx.push_back(x[i]); vx.push_back(x[n + i]);
		vy.push_back(y[i]); vy.push_back(y[n + i]);
		vz.push_back(z[i]); vz.push_back(z[n + i]);
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	sort(vz.begin(), vz.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	vy.erase(unique(vy.begin(), vy.end()), vy.end());
	vz.erase(unique(vz.begin(), vz.end()), vz.end());
	for (int i = 0; i < n; i++) {
		int xlo = upper_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
		int xhi = upper_bound(vx.begin(), vx.end(), x[n + i]) - vx.begin();
		int ylo = upper_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
		int yhi = upper_bound(vy.begin(), vy.end(), y[n + i]) - vy.begin();
		int zlo = upper_bound(vz.begin(), vz.end(), z[i]) - vz.begin();
		int zhi = upper_bound(vz.begin(), vz.end(), z[n + i]) - vz.begin();
		for (int xx = xlo; xx < xhi; xx++) {
			for (int yy = ylo; yy < yhi; yy++) {
				for (int zz = zlo; zz < zhi; zz++) {
					sum[xx][yy][zz]++;
				}
			}
		}
	}
	long long ans = 0;
	for (int xx = 1; xx < vx.size(); xx++) {
		for (int yy = 1; yy < vy.size(); yy++) {
			for (int zz = 1; zz < vz.size(); zz++) {
				if (sum[xx][yy][zz] >= k) {
					ans += 1LL * (vx[xx] - vx[xx - 1]) * (vy[yy] - vy[yy - 1]) * (vz[zz] - vz[zz - 1]);
				}
			}
		}
	}
	cout << ans << "\n";
}
