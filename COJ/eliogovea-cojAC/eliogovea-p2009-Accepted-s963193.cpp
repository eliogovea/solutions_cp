#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000007;

vector <int> sum(vector <int> &v) {
	vector <int> res(1 << v.size());
	for (int i = 0; i < v.size(); i++) {
		res[1 << i] = v[i];
	}
	for (int i = 1; i < (1 << v.size()); i++) {
		res[i] = res[i ^ (i & -i)] + res[i & -i];
	}
	return res;
}

vector <pair <int, int> > fun(vector <int> &sum) {
	vector <pair <int, int> > res;
	for (int m = 0; m < sum.size(); m++) {
		int s = m;
		while (true) {
			res.push_back(make_pair(sum[m ^ s] - sum[s], m));
			if (s == 0) {
				break;
			}
			s = (s - 1) & m;
		}
	}
	sort(res.begin(), res.end());
	//res.erase(unique(res.begin(), res.end()), res.end());
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a, b;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i & 1) {
			a.push_back(x);
		} else {
			b.push_back(x);
		}
	}
	if (n <= 1) {
		cout << "0\n";
		return 0;
	}
	vector <int> suma = sum(a);
	vector <int> sumb = sum(b);
	vector <pair <int, int> > va = fun(suma);
	vector <pair <int, int> > vb = fun(sumb);
	vector <bool> mark(1 << n);
	for (int i = 0; i < va.size(); i++) {
		int lo = lower_bound(vb.begin(), vb.end(), make_pair(-va[i].first, -INF)) - vb.begin();
		int hi = upper_bound(vb.begin(), vb.end(), make_pair(-va[i].first, INF)) - vb.begin();
		for (int j = lo; j < hi; j++) {
			mark[(va[i].second << b.size()) | vb[j].second] = true;
		}
	}
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		if (mark[i]) {
			ans++;
		}
	}
	cout << ans << "\n";
}
