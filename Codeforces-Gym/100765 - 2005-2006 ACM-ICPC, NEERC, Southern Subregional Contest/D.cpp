// 2005-2006 ACM-ICPC, NEERC, Southern Subregional Contest
// 100765D

#include <bits/stdc++.h>

using namespace std;

typedef vector <int> big;

big operator + (const big &a, const big &b) {
	big res;
	res.resize(max(a.size(), b.size()));
	int carry = 0;
	for (int i = 0; i < res.size(); i++) {
		if (i < a.size()) carry += a[i];
		if (i < b.size()) carry += b[i];
		res[i] = carry % 10;
		carry /= 10;
	}
	if (carry) res.push_back(carry);
	return res;
}


big get(string &s) {
	big res;
	for (int i = s.size() - 1; i >= 0; i--) {
		res.push_back(s[i] - '0');
	}
	return res;
}

bool menor(const big &a, const big &b) {
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] != b[i]) return a[i] < b[i];
	}
	return false;
}

void print(const big &x) {
	for (int i = x.size() - 1; i >= 0; i--) {
		cout << x[i];
	};
}

int n;
big a[1005];
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		a[i] = get(s);
	}
	sort(a, a + n, menor);

	for (int i = 0; i + 2 < n; i++) {
		big sum = a[i] + a[i + 1];
		if (menor(a[i + 2], sum)) {
			print(a[i]);
			cout << " ";
			print(a[i + 1]);
			cout << " ";
			print(a[i + 2]);
			cout << "\n";
			return 0;
		}
	}
	cout << "0 0 0\n";
	return 0;
}
