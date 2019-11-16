#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100005;
 
int n;
int a[N];
priority_queue<pair<int, int> > S;
int L[N], R[N];
long long ans;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	while (cin >> n && n) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			//cout << a[i] << " ";
			L[i] = R[i] = -1;
		}
		//cout << "\n";
		while (!S.empty()) {
      S.pop();
		}
		for (int i = 1; i <= n; i++) {
			while (!S.empty() && S.top().first > a[i]) {
				R[S.top().second] = i - 1;
				S.pop();
			}
			S.push(make_pair(a[i], i));
		}
		while (!S.empty()) {
      S.pop();
		}
		for (int i = n; i >= 1; i--) {
			while (!S.empty() && S.top().first > a[i]) {
				L[S.top().second] = i + 1;
				S.pop();
			}
			S.push(make_pair(a[i], i));
		}
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (L[i] == -1) {
				L[i] = 1;
			}
			if (R[i] == -1) {
				R[i] = n;
			}
			//cout << i << " " << L[i] << " " << R[i] << " " << a[i] << "\n";
			long long tmp = ((long long)(R[i] - L[i] + 1LL) * a[i]);
			if (tmp > ans) {
				ans = tmp;
			}
		}
		cout << ans << "\n";
	}
}
