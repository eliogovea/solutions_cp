#include <bits/stdc++.h>

using namespace std;

const int M = 20005;

int t;
int n, m;
int arr[M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + m);
		int lo = 0;
		int hi = m - 1;
		int ans = 0;
		while (true) {
            if (hi <= lo) {
                break;
            }
			int need = hi - lo - 1;
			if (arr[lo] == need) {
				ans += need;
				break;
			}
			if (arr[lo] > need) {
				ans += need + 1;
				break;
			}
			ans += arr[lo];
			hi -= arr[lo];
			lo++;
		}
		cout << ans << "\n";
	}
}

