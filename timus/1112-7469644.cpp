// Problem: pace=1&num=1112
// Verdict: Accepted

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector <pair <int, int> > s(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		s[i] = make_pair(b, a);
	}
	
	sort(s.begin(), s.end());
	
	vector <int> dp(n);
	vector <int> from(n);
	
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		from[i] = -1;
		for (int j = 0; j < i; j++) {
			if (s[j].first <= s[i].second) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
					from[i] = j;
				}
			}
		}
	}
	
	int best = 0;
	for (int i = 1; i < n; i++) {
		if (dp[i] > dp[best]) {
			best = i;
		}
	}
	
	vector <pair <int, int> > answer;
	int now = best;
	while (now >= 0) {
		answer.push_back(make_pair(s[now].second, s[now].first));
		now = from[now];
	}
	reverse(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].first << " " << answer[i].second << "\n";
	}
}