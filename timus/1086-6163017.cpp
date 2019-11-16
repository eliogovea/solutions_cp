// Problem: pace=1&num=1086
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

const int N = 500000;

bool criba[N + 5];
vector<int> p;

int main() {
	//freopen("data.txt", "r", stdin);
	for (int i = 2; i * i <= N; i++) {
		if (!criba[i]) {
			for (int j = i * i; j <= N; j += i) {
				criba[j] = true;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (!criba[i]) {
			p.push_back(i);
		}
		if (p.size() == 15000) {
			break;
		}
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc, n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		cout << p[n - 1] << "\n";
	}
}