#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int t;
int n;
long long a[N], b[N];
bool used[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			sum += b[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if (sum % n != 0) {
			cout << "-1\n";
			continue;
		}
		for (int i = 0; i < n; i++) {
			used[i] = false;
		}
		long long x = sum / n;
		//cerr << "DEBUG " << x << "\n";
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (a[i] > x) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout << "-1\n";
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (i > 0 && !used[i - 1]) {
				a[i] += b[i - 1];
				used[i - 1] = true;
			}
			long long need = x - a[i];
			//cerr << "DEBUG " << i << " " << need << "\n";
			if (i == n - 1) {
				if (!used[n - 1]) {
					if (b[n - 1] != need) {
						ok = false;
						break;
					}
				} else {
					if (need != 0) {
						ok = false;
						break;
					}
				}
			} else {
				if (need == 0) {
					continue;
				}
				vector <int> v;
				if (!used[i]) {
					v.push_back(i);
				}
				if (i + 1 < n) {
					v.push_back(i + 1);
				}
				if (v.size() == 1) {
					if (b[v[0]] == need) {
						used[v[0]] = true;
					} else {
						ok = false;
						break;
					}
				} else {
					if (b[v[0]] == need) {
						used[v[0]] = need;
					} else if (b[v[1]] == need) {
						used[v[1]] = true;
					} else if (b[v[0]] + b[v[1]] == need) {
						used[v[0]] = used[v[1]] = true;
					} else {
						ok = false;
						break;
					}
				}
			}
		}
		cout << (ok ? x : -1) << "\n";
	}
}

