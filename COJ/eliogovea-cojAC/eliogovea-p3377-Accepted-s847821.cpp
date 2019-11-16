#include  <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

const LL INF = 1LL << 63LL;

bool criba[200];

vector<LL> p;

LL ans;

LL power(LL x, LL n) {
	LL res = 1;
	while (n) {
		if (n & 1LL) res *= x;
		x *= x;
		n >>= 1LL;
	}
	return res;
}

void calc(LL cur, int pos, int n) {
    //cout << cur << " " << pos << " " << n << "\n";
	if (n == 1) {
		if (ans > cur) {
			ans = cur;
		}
	} else {
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				if (cur < INF / power(p[pos], i - 1)) {
					calc(cur * power(p[pos], i - 1), pos + 1, n / i);
				}
				if (i * i != n) {
					if (cur < INF / power(p[pos], n / i - 1)) {
						calc(cur * power(p[pos], n / i - 1), pos + 1, i);
					}
				}
			}
		}
		//if (!criba[n]) {
            if (cur < INF / power(p[pos], n - 1)) {
                calc(cur * power(p[pos], n - 1), pos + 1, 1);
            }
		//}
	}
}

int t, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i <= 100; i++) {
		if (!criba[i]) {
			p.push_back(i);
			for (int j = i * i; j <= 100; j += i) {
				criba[j] = true;
			}
		}
	}
	cin >> t;
	while (t--) {
		cin >> n;
		ans = power(2, n - 1);
		calc(1, 0, n);
		cout << ans << "\n";
	}
}
