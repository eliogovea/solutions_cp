#include <bits/stdc++.h>
using namespace std;

int tc, n, sol;
pair<pair<int, int>, bool> P[10];
bool mark[10];

bool check() {
	for (int i = 0; i < n; i++) mark[i] = 0;
	for (int i = 0; i < n; i++) {
		if (P[i].second)
            return mark[P[i].first.second] == false;
		else
			for (int j = P[i].first.second; ; j = (j + 1) % n)
				if (mark[j] == false) {
					mark[j] = true;
					break;
				}
	}
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> n;
		sol = 0;
		for (int i = 0; i < n; i++)
			cin >> P[i].first.second,
			P[i].first.first = i;
		P[0].second = true;
		do {
			sol += check();
		} while (next_permutation(P, P + n));
		cout << sol << '\n';
	}
}
