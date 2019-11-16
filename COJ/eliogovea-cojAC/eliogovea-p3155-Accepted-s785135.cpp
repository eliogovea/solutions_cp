#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int N =  20000;

int n, k, a[N + 5];
vector<int> b;

const ull B = 20011;
const ull C = 20021;

ull hash[N + 5];
ull POW[N + 5];

map<ull, int> M;
map<ull, int>::iterator it;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(false);
	//freopen("dat.txt", "r", stdin);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b.push_back(a[i]);
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int i = 0; i < n; i++) {
		a[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
	}
	hash[0] = C;
	POW[0] = 1;
	for (int i = 1; i <= n; i++) {
		hash[i] = hash[i - 1] * B + a[i - 1];
		POW[i] = POW[i - 1] * B;
	}
	int lo = 1, hi = n + 1 - k;
	int ans = 0;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		bool ok = false;
		for (int i = 0; i + mid <= n; i++) {
			ull tmp = hash[i + mid] - hash[i] * POW[mid];
			int v = ++M[tmp];
			if (v >= k) {
				ok = true;
				break;
			}
		}
		if (ok) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << ans << "\n";
}
