#include <iostream>
#include <queue>

using namespace std;

const int N = 100005;

int n, a[N], b[N], c[N], ans;
priority_queue<pair<int, int> > Q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
    c[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		while (!Q.empty() && Q.top().first > b[i]) {
			c[Q.top().second] = i;
			Q.pop();
		}
		Q.push(make_pair(b[i], i));
	}
	for (int i = 0; i < n; i++) {
		ans += (c[i] == -1);
	}
	cout << ans << "\n";
}
