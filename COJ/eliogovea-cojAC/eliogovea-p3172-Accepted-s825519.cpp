#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 100000;

int n;
ll a[100005], b[100005];

void print(ll n) {
	if (n < 10000) {
		cout << "0";
	}
	if (n < 1000) {
		cout << "0";
	}
	if (n < 100) {
		cout << "0";
	}
	if (n < 10) {
		cout << "0";
	}
	cout << n << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int l = 0;
	int r = n - 1;
	int p = 0;
	while (l <= r) {
        if (!(p & 1)) {
            b[l] = a[l];
            b[r] = a[r];
        } else {
            b[l] = a[r];
            b[r] = a[l];
        }
        l++;
        r--;
        p ^= 1;
	}
	/*for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
	}
	cout << "\n";*/
	/*b[n / 2] = a[n - 1];
	int cnt = 1;
	int pl = (n / 2 - 1);
	int pr = (n / 2 + 1);
	int men = 0;
	int may = n - 2;
	int stp = 0;
	while (cnt < n) {
        if (stp == 0) {
            b[pl--] = a[men++];
            b[pr++] = a[men++];
        } else {
            b[pl--] = a[may--];
            b[pr++] = a[may--];
        }
        stp ^= 1;
        cnt += 2;
	}*/
	/*for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
	}
	cout << "\n";*/
	ll sum = 0;
	ll tot = 0;
	for (int i = 0; i < n; i++) {
        int nex = (i + 1) % n;
        int pre = (i - 1 + n) % n;
        sum += (b[i] * tot) % mod;
        sum %= mod;
        if (i >= 1) {
            sum -= (b[i] * b[i - 1]) % mod;
            while (sum < 0) {
                sum += mod;
            }
        }
        sum %= mod;
        tot += b[i];
        tot %= mod;

	}
	sum -= (b[0] * b[n - 1]) % mod;
	while (sum < 0) {
        sum += mod;
	}
	print(sum);
}
