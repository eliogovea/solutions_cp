#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n;
int arr[N * N];
int ans[N];
map <int, int> M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> arr[i];
		M[arr[i]]++;
	}
	sort(arr, arr + (n * n), greater <int>());
	int pos = 0;
	for (int i = 0; pos < n && i < n * n; i++) {
		if (M[arr[i]] > 0) {
			ans[pos] = arr[i];
			for (int j = 0; j < pos; j++) {
				M[__gcd(ans[j], ans[pos])] -= 2;
			}
			M[ans[pos]]--;
			pos++;
		}
	}
	sort(ans, ans + n);
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (i + 1 < n) {
			cout << " ";
		}
	}
	cout << "\n";
}
