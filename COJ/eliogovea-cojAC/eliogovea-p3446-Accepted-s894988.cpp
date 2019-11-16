#include <bits/stdc++.h>

using namespace std;

int t;
string sn, sk;
int n, k;

int last[20];

int val[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	val[0] = 0;
	val[1] = 1;
	for (int i = 2; i <= 24; i++) {
		val[i] = (val[i - 1] + val[i - 2]) % 6;
	}
	cin >> t;
	while (t--) {
		cin >> sn >> sk;
		if (sn == "0") {
            cout << "1\n";
            continue;
		}
		k = sk[sk.size() - 1] - '0';
		if (k == 0) {
            cout << "0\n";
            continue;
		}
		last[0] = 1;
		for (int i = 1; i < 6; i++) {
			last[i] = (last[i - 1] * k) % 7;
		}
		int r = 0;
		for (int i = 0; sn[i]; i++) {
			r = (7 * r + sn[i] - '0') % 24;
		}
		cout << last[val[r]] << "\n";
	}
}
