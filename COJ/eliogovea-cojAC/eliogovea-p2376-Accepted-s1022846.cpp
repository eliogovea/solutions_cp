#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector <int> s(n);
	int t = 0;
	vector <int> r(n, n);
	for (int i = 0; i < n; i++) {
		while (t > 0 && v[s[t - 1]] > v[i]) {
			r[s[t - 1]] = i;
			t--;
		}
		s[t++] = i;
	}
	vector <int> l(n, -1);
	t = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (t > 0 && v[s[t - 1]] > v[i]) {
			l[s[t - 1]] = i;
			t--;
		}
		s[t++] = i;
	}
	vector <int> R(n, n);
	t = 0;
	for (int i = 0; i < n; i++) {
		while (t > 0 && v[s[t - 1]] < v[i]) {
			R[s[t - 1]] = i;
			t--;
		}
		s[t++] = i;
	}
	vector <int> L(n, -1);
	t = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (t > 0 && v[s[t - 1]] < v[i]) {
			L[s[t - 1]] = i;
			t--;
		}
		s[t++] = i;
	}
	map <pair <int, int>, int> last;
	map <pair <int, int>, int> :: iterator it;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long ll = L[i];
		long long rr = R[i];
		it = last.find(make_pair(L[i], R[i]));
		if (it != last.end()) {
			ll = it->second;
		}
		last[make_pair(L[i], R[i])] = i;
		ans += (long long)v[i] * (rr - (long long)i) * ((long long)i - ll);
	}
	last.clear();
	for (int i = 0; i < n; i++) {
		long long ll = l[i];
		long long rr = r[i];
		it = last.find(make_pair(l[i], r[i]));
		if (it != last.end()) {
			ll = it->second;
		}
		last[make_pair(l[i], r[i])] = i;
		ans -= (long long)v[i] * (rr - (long long)i) * ((long long)i - ll);
	}
	cout << ans << "\n";
}
