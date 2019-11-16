#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k, n;

string solve(ll k, ll n) {
	ll m;
	string r = "";
	while (true) {
		m = k % n;
		for (int i = 0; i < m; i++) r += 'S';
		k -= m;
		if (k > 1) {
            if (k == 2 && n == 2) r += 'S';
            else r += 'M';
            k /= n;
		}
		else if (k == 1) r += 'S';
		else break;
	}
	reverse(r.begin(), r.end());
	return r;
}

string sol;

int main() {
    ios::sync_with_stdio(false);
	while (cin >> k >> n && k | n) {
        sol = solve(k, n);
        cout << sol.size() << ' ' << sol << '\n';
	}
}
