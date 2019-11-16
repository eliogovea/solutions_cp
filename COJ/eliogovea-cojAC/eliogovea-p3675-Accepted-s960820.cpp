#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct frac {
	LL x, y;
	frac() {
        x = 0;
        y = 1;
	}
	frac(LL _x, LL _y) : x(_x), y(_y) {}
	void red() {
		LL g = __gcd(x, y);
		x /= g;
		y /= g;
	}
	void print() {
        cout << x << " / " << y << "\n";
	}
};

bool operator < (const frac &a, const frac &b) {
	return a.x * b.y < a.y * b.x;
}

frac operator + (const frac &a, const frac &b) {
	frac res(a.x * b.y + b.x * a.y, a.y * b.y);
	res.red();
	return res;
}

frac get(string s) {
	LL val = 0;
	LL pos = 0;
	while (s[pos] && s[pos] != '.') {
		val = 10LL * val + s[pos] - '0';
		pos++;
	}
	if (s[pos] != '.') {
		return frac(val, 1);
	}
	pos++;
	LL den = 1;
	while (s[pos]) {
		val = 10LL * val + s[pos] - '0';
		den *= 10;
		pos++;
	}
	frac res(val, den);
	res.red();
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	int n;
	string sb, sp;
	cin >> n >> sp >> sb;
	frac b = get(sb);
	frac p = get(sp);
	vector <frac> v(n);
	for (int i = 0; i < n; i++) {
		cin >> sb;
		v[i] = get(sb);
		//v[i].print();
	}
	vector <frac> val(1 << n, frac(0, 1));
	for (int i = 0; i < n; i++) {
		val[1 << i] = v[i];
	}
	vector <frac> sum(1 << n, frac(0, 1));
	for (int i = 1; i < (1 << n); i++) {
		sum[i] = sum[i ^ (i & -i)] + val[i & -i];
	}
	vector <frac> ans;
	for (int i = 0; i < (1 << n); i++) {
	    sum[i].x *= 2LL;
        sum[i] = sum[i] + b;
        if (!(sum[i] < p)) {
            ans.push_back(sum[i]);
        }
	}

	if (ans.size() == 0) {
        cout << "Strong\n";
	} else {
	    sort(ans.begin(), ans.end());
		int value = 1;
		for (int i = 1; i < ans.size(); i++) {
			if ((ans[i] < ans[i - 1]) || (ans[i - 1] < ans[i])) {
				value++;
			}
		}
		cout << value << "\n";
	}
}
