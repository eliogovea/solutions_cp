#include <bits/stdc++.h>

using namespace std;

long long t[20][20];
long long p5[20];

int tc, o, e;

long long calc(int e, int o) {
	return t[e + o][o] * p5[e + o] * 2LL;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i <= 18; i++) {
		t[i][0] = t[i][i] = 1;
		for (int j = 1; j < i; j++) {
			t[i][j] = t[i - 1][j - 1] + t[i - 1][j];
		}
	}
	p5[0] = 1;
	for (int i = 1; i <= 18; i++) {
		p5[i] = 5LL * p5[i - 1];
	}
	while (cin >> e >> o && (e | o)) {
        if (e == 1 && o == 0) {
            cout << "9\n";
            continue;
        }
		long long ans = calc(e, o);
		if (e > 0) ans -= calc(e - 1, o);
		cout << ans << "\n";
	}

}
