#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int t;
int n;
int k;
int a;
int cnt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < k; i++) {
			cnt[i] = 0;
		}
		cnt[0] = 1;
		int cur = 0;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			cur = (cur + a) % k;
			ans += cnt[cur];
			cnt[cur]++;
		}
		cout << ans << "\n";
	}
}
