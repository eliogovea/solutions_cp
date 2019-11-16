#include <iostream>

using namespace std;

const int MAXN = 105;

int n, a[MAXN], b[MAXN], c[MAXN], cnt, mx;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i], c[b[i]] = i;
	for (int i = 1; i <= n; i++)
		if (a[i] != b[i]) {
			cnt++;
			int tmp = a[i], next = c[a[i]];
			a[i] = 0;
			int len = 0;
			while (true) {
				len++;
				if (a[next] == 0) {
					a[next] = tmp;
					break;
				}
				swap(tmp, a[next]);
				next = c[tmp];
			}
			if (mx < len) mx = len;
		}
  cout << cnt << ' ';
  if (cnt) cout << mx  << '\n';
  else cout << "-1\n";
}
