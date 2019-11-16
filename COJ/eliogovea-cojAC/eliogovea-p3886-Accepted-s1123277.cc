#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 5;

int n, s, w, q;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> s >> w >> q;
	int g = s;
	for (int i = 0; i < n; i++) {
		a[i] = (g / 7) % 10;
		if (g % 2 == 0) {
			g /= 2;
		} else {
			g = (g / 2) ^ w;
		}
	}

	/*for (int i = 0; i < n; i++) {
        cerr << a[i];
	}
	cerr << "\n";*/
	reverse(a, a + n);
	if (q == 2) {
		int cnt = 0;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if ((a[i] % 2 == 0) && (a[i] != 0)) {
				ans++;
			}
			if (a[i] != 0) {
				ans += cnt;
			}
            if (a[i] % 2 == 0) {
				cnt++;
			}
		}
		cout << ans << "\n";
	} else if (q == 5) {
		int cnt = 0;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 5) {
                ans++;
			}
			if (a[i] != 0) {
				ans += cnt;
			}
			if (a[i] == 0 || a[i] == 5) {
				cnt++;
			}
		}
		cout << ans << "\n";
	} else {
		map <int, int> cnt;
		cnt[0] = 1;
		int x = 0;
		int ans = 0;
		int p10 = 1;
		for (int i = 0; i < n; i++) {
            x = ((long long)x + (long long)p10 * a[i]) % q;
            p10 = (long long)p10 * 10LL % q;
            // cerr << a[i] << " " << x << " " << cnt[x] << "\n";
			if (a[i] != 0) {
				ans += cnt[x];
			}
			cnt[x]++;
		}
		cout << ans << "\n";
	}
}
