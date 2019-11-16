// 2016-2017 ACM-ICPC, NEERC, Moscow Subregional Contest
// 101137L

#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(16);
	//freopen("dat.txt", "r", stdin);
	int n;
	cin >> n;
	n *= 2;
	vector <char> op(n);
	vector <int> t(n);
	for (int i = 0; i < n; i++) {
		cin >> op[i] >> t[i];
	}
	vector <int> C(n, 0);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (op[i] == '+') {
			sum++;
		} else {
			C[i] = sum;
			sum--;
		}
	}
	LD A = 0.0;
	LD B = 0.0;
	vector <LD> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		if (op[i] == '-') {
			A = A * ((LD)(C[i] - 1.0) / (LD)C[i]) + ((LD)t[i]) / ((LD)C[i]);
			B = B * ((LD)(C[i] - 1.0) / (LD)C[i]) + 1.0 / ((LD)C[i]);
		} else {
			ans[i] = A - ((LD)t[i]) * B;
		}
	}
	for (int i = 0; i < n; i++) {
		if (op[i] == '+') {
			cout << fixed << ans[i] << "\n";
		}
	}
}
