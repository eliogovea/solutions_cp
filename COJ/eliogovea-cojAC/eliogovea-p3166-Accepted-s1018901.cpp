#include <bits/stdc++.h>

using namespace std;

vector <int> prefixFunction(const string &s) {
	int n = s.size();
	vector <int> pi(n, 0);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			j++;
		}
		pi[i] = j;
	}
	return pi;
}

vector <int> manacher(const string &s) {
	int n = 2 * s.size();
  vector <int> u(n, 0);
  for (int i = 0, j = 0, k; i < n; i += k, j = max(j - k, 0)) {
    while (i >= j && i + j + 1 < n && s[(i - j) >> 1] == s[(i + j + 1) >> 1]) ++j;
    for (u[i] = j, k = 1; i >= k && u[i] >= k && u[i - k] != u[i] - k; ++k) {
      u[i + k] = min(u[i - k], u[i] - k);
    }
  }
  return u;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	vector <int> c = manacher(a);
	vector <int> pi = prefixFunction(a);
	vector <long long> sum(a.size() + 1, 0);
	for (int i = 0, j = 0; i < b.size(); i++) {
		while (j > 0 && b[i] != a[j]) {
			j = pi[j - 1];
		}
		if (b[i] == a[j]) {
			j++;
		}
		sum[j]++;
	}
	for (int i = ((int)b.size()) - 1, j = 0; i >= 0; i--) {
		while (j > 0 && b[i] != a[j]) {
			j = pi[j - 1];
		}
		if (b[i] == a[j]) {
			j++;
		}
		sum[j]++;
	}
	for (int i = a.size(); i > 0; i--) {
		sum[pi[i - 1]] += sum[i];
	}
	for (int i = 1; i <= a.size(); i++) {
		if (c[i - 1] == i) {
			cout << (sum[i] >> 1LL);
		} else {
			cout << sum[i];
		}
		if (i < a.size()) {
            cout << " ";
		}
	}
	cout << "\n";
}
