#include <iostream>

using namespace std;

const int MAXN = 505;

int tc, n, m, x, y, a[MAXN], b[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			a[x] = b[x] = i;
		}
		cin >> m;
		while (m--) {
			cin >> x >> y;
			if (a[x] < a[y]) b[x]++, b[y]--;
			else b[x]--, b[y]++;
		}
		for (int i = 1; i <= n; i++) a[i] = -1;
		for (int i = 1; i <= n; i++) a[b[i]] = i;
		bool ok = true;
		for (int i = 1; i <= n && ok; i++)
			if (a[i] == -1) ok = false;
    if (ok)
      for (int i = 1; i <= n; i++) {
        cout << a[i];
        if (i < n) cout << " ";
        else cout << "\n";
      }
    else cout << "IMPOSSIBLE\n";
	}
}
