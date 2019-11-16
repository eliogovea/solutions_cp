#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int sum[N + 5];
vector <int> dv[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= N; i++) {
		for (int j = i + i; j <= N; j += i) {
			sum[j] += i;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + i; j <= N; j += i) {
			if (sum[j] == j) {
				dv[j].push_back(i);
			}
		}
	}
	int n;
	while (cin >> n && n != -1) {
		if (sum[n] != n) {
			cout << n << " is NOT perfect.\n";
		} else {
		    cout << n << " = ";
			for (int i = 0; i < dv[n].size(); i++) {
				cout << dv[n][i];
				if (i + 1 < dv[n].size()) {
					cout << " + ";
				}
			}
			cout << "\n";
		}
	}
}
