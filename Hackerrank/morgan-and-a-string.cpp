#include <bits/stdc++.h>

using namespace std;

template <class T>
vector <int> normalize(vector <T> v) {
	auto cv = v; vector <int> nv(v.size());
	sort(cv.begin(), cv.end());
	cv.erase(unique(cv.begin(), cv.end()), cv.end());
	for (int i = 0; i < v.size(); i++)
		nv[i] = upper_bound(cv.begin(), cv.end(), v[i])
						- cv.begin();
	return nv;
}

// 0 < *min_element(v.begin(), v.end()) !!!
vector <int> get_suffix_array(vector <int> v, int alpha = -1) {
	if (alpha == -1) alpha = v.size() + 2;
	v.push_back(v.size() + 1); int n = v.size(), classes = alpha;
	vector <int> cnt(max(n, alpha));
	vector <int> p(n), np(n), c(n), nc(n);
	for (int i = 0; i < n; i++) p[i] = i, c[i] = v[i];
	for (int len = 1; len < 2 * n; len <<= 1) {
		int hlen = len >> 1;
		for (int i = 0; i < n; i++)
			np[i] = (p[i] - hlen + n) % n;
		for (int i = 0; i < classes; i++) cnt[i] = 0;
		for (int i = 0; i < n; i++) cnt[c[i]]++;
		for (int i = 1; i < classes; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--)
			p[--cnt[c[np[i]]]] = np[i];
		classes = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0 || c[p[i]] != c[p[i - 1]] ||
			c[(p[i] + hlen) % n] != c[(p[i - 1] + hlen) % n])
				classes++;
			nc[p[i]] = classes - 1;
		}
		for (int i = 0; i < n; i++) c[i] = nc[i];
	}
	p.pop_back(); return p;
}

vector <int> stringToVector(const string & s) {
	vector <int> v(s.size());
	for (int i = 0; i < s.size(); i++) {
		v[i] = (int)s[i];
	}
	return normalize(v);
}

string solve(const string & a, const string & b) {
	auto v = stringToVector(a + char('Z' + 1) + b);
	
	auto sa = get_suffix_array(v);

	vector <int> rank(sa.size());
	for (int i = 0; i < sa.size(); i++) {
		rank[sa[i]] = i;
	}

	int pa = 0;
	int pb = 0;

	string answer = "";

	while (pa < a.size() && pb < b.size()) {
		if (rank[pa] < rank[a.size() + 1 + pb]) {
			answer += a[pa++];
		} else {
			answer += b[pb++];
		}
	}

	while (pa < a.size()) {
		answer += a[pa++];
	}

	while (pb < b.size()) {
		answer += b[pb++];
	}

	return answer;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		string a, b;
		cin >> a >> b;

		cout << solve(a, b) << "\n";
	}

}
