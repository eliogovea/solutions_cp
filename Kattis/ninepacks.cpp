#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("dat.txt", "r", stdin);

	int h;
	cin >> h;
	vector <int> vh(h);
	vector <int> sumh(h + 1);
	for (int i = 0; i < h; i++) {
		cin >> vh[i];
		sumh[i + 1] = sumh[i] + vh[i];
	}

	int b;
	cin >> b;
	vector <int> vb(b);
	vector <int> sumb(b + 1);
	for (int i = 0; i < b; i++) {
		cin >> vb[i];
		sumb[i + 1] = sumb[i] + vb[i];
	}

	vector <int> dph(sumh[h] + 1, -1);

	dph[0] = 0;

	for (int i = 0; i < h; i++) {
		for (int j = sumh[i + 1]; j >= vh[i]; j--) {
			if (dph[j - vh[i]] != -1) {
				if (dph[j] == -1 || dph[j] > dph[j - vh[i]] + 1) {
					dph[j] = dph[j - vh[i]] + 1;
				}
			}
		}
	}

	vector <int> dpb(sumb[b] + 1, -1);
	dpb[0] = 0;

	for (int i = 0; i < b; i++) {
		for (int j = sumb[i + 1]; j >= vb[i]; j--) {
			if (dpb[j - vb[i]] != -1) {
				if (dpb[j] == -1 || dpb[j] > dpb[j - vb[i]] + 1) {
					dpb[j] = dpb[j - vb[i]] + 1;
				}
			}
		}
	}

	int ans = -1;
	for (int sum = 1; sum <= min(sumh[h], sumb[b]); sum++) {
		if (dph[sum] != -1 && dpb[sum] != -1) {
			if (ans == -1 || ans > dph[sum] + dpb[sum]) {
				ans = dph[sum] + dpb[sum];
			}
		}
	}

	if (ans == -1) {
		cout << "impossible\n";
	} else {
		cout << ans << "\n";
	}
}
