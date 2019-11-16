//============================================================================
// Name        : test.cpp
// Author      : eliogovea
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// 3485.     Counting Subsequences


#include <bits/stdc++.h>

using namespace std;

int tc, n;
long long x, y, ans;

priority_queue<long long, vector<long long>, greater<long long> > q;

int main() {
	cin >> tc;
	while (tc--) {
		cin >> n;
		ans = 0;
		while (!q.empty()) {
			q.pop();
		}
		for (int i = 0; i < n; i++) {
			cin >> x;
			q.push(x);
		}

		while (q.size() > 1) {
			x = q.top();
			q.pop();
			y = q.top();
			q.pop();
			ans += x + y;
			q.push(x + y);
		}
		cout << ans << "\n";
	}
}

/*
int tc;
string a, b, c;
bool dp[205][205];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	for (int cas = 1; cas <= tc; cas++) {
		cin >> a >> b >> c;
		for (int i = 0; i <= a.size(); i++) {
			for (int j = 0; j <= b.size(); j++) {
				dp[i][j] = false;
			}
		}
		dp[0][0] = true;
		for (int i = 0; i <= a.size(); i++) {
			for (int j = 0; j <= b.size(); j++) {
				if (dp[i][j]) {
					if (i < a.size() && a[i] == c[i + j]) {
						dp[i + 1][j] = true;
					}
					if (j < b.size() && b[j] == c[i + j]) {
						dp[i][j + 1] = true;
					}
				}
			}
		}
		cout << "Data set " << cas << ": ";
		cout << (dp[a.size()][b.size()] ? "yes" : "no") << "\n";
	}

}
*/
/*
int tc, n, m;
double p[105][605];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	cout.precision(2);
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= 6 * n; j++) {
				p[i][i] = 0.0;
			}
		}
		p[0][0] = 1.0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= 6 * i; j++) {
				for (int k = 1; k <= 6; k++) {
					p[i + 1][j + k] += p[i][j] * 1.0 / 6.0;
				}
			}
		}
		double ans = p[n][m];
		cout << fixed << ans << "\n";
	}
}

*/


/*
 * broken keyboard
int n;
string s, ss;
int cnt[1000], tot, ans;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	while (true) {
		getline(cin, s);
		//cout << s << "\n";
		n = 0;
		for (int i = 0; i < s.size(); i++) {
			n = 10 * n + s[i] - '0';
		}
		if (n == 0) {
			return 0;
		}
		getline(cin, s);
		//cout << s << "\n";
		ans = tot = 0;
		for (int i = 0; i < 256; i++) {
			cnt[i] = 0;
		}
		for (int i = 0, j = 0; i < s.size(); i++) {
			if (cnt[s[i]] == 0) {
				tot++;
			}
			cnt[s[i]]--;
			while (tot > n) {
				if (cnt[s[j]] == 1) {
					tot--;
				}
				cnt[s[j]]--;
			}
			if (tot <= n && ans < i - j + 1) {
				ans = i - j + 1;
			}
		}
		cout << ans << "\n";
	}
}*/


/*
 * Underground Cables
#include <bits/stdc++.h>

using namespace std;

struct edge {
	int a, b;
	double c;
	edge(int aa, int bb, double cc) : a(aa), b(bb), c(cc) {}
};

bool operator < (const edge &a, const edge &b) {
	return a.c < b.c;
}

vector<edge> E;

int p[1005];
double ans;

int find(int x) {
	if (x != p[x]) {
		p[x] = find(p[x]);
	}
	return p[x];
}

bool join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return false;
	}
	p[x] = y;
	return true;
}

int tc, n;
double x[1005], y[1005];

double dist(int i, int j) {
	double dx = x[i] - x[j];
	double dy = y[i] - y[j];
	return sqrt(dx * dx + dy * dy);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	while (cin >> n && n) {
		E.clear();
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			for (int j = 0; j < i; j++) {
				E.push_back(edge(i, j, dist(i, j)));
			}
			p[i] = i;
		}
		sort(E.begin(), E.end());
		for (int i = 0; i < E.size(); i++) {
			if (join(E[i].a, E[i].b)) {
				ans += (double)E[i].c;
			}
		}
		cout << fixed << ans << "\n";
	}
}*/

/*
 *
 * zipper
int tc;
string a, b, c, s1, s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> tc;
	for (int ca = 1; ca <= tc; ca++) {
		cin >> a >> b >> c;
		int i, j, k;
		for (i = 0, j = 0, k = 0; i < c.size(); i++) {
			if (a[j] == c[i]) {
				j++;
			} else if (b[k] == c[i]) {
				k++;
			}
		}
		cout << "Data set " << ca << ": ";
		cout << ((j == a.size() && k == b.size()) ? "yes" : "no") << "\n";
	}
}*/
