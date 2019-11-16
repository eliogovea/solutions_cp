#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, d;
	cin >> n >> m >> d;

	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector <int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int answer = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (j < m && b[j] < a[i] - d) {
			j++;
		}
		if (j < m && b[j] <= a[i] + d) {
			answer++;
			j++;
		}
	}

	cout << answer << "\n";
}
