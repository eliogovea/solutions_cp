#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

int t, n, k, l;

inline vector <int> merge(vector <int> &a, vector <int> &b, vector <int> &vals) {
	vector <int> res(a.size(), 0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			int x = __gcd((long long)k, (long long)vals[i] * vals[j]);
			int p = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
			add(res[p], mul(a[i], b[j]));
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> k >> l;
    vector <int> d;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            d.push_back(i);
            if (i * i != k) {
                d.push_back(k / i);
            }
        }
    }
    sort(d.begin(), d.end());
    vector <int> v(d.size(), 0);
    for (int i = 1; i <= l; i++) {
        int x = __gcd(k, i);
        int p = lower_bound(d.begin(), d.end(), x) - d.begin();
        add(v[p], 1);
    }
    vector <int> res(d.size(), 0);
    res[0] = 1;
    while (n) {
        if (n & 1) {
            res = merge(res, v, d);
        }
        v = merge(v, v, d);
        n >>= 1;
    }
    cout << res[d.size() - 1] << "\n";
}
