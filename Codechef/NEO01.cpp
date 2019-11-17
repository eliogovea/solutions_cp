#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());

		long long sumAll = 0;
		for (int i = 0; i < n; i++) {
			sumAll += a[i];
		}

		long long answer = sumAll;
		long long curSum = 0;
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			curSum += a[i];
			cnt++;
			answer = max(answer, curSum * cnt + (sumAll - curSum));
		}
		cout << answer << "\n";
	}
}

