#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int solve(vector <int> v, int x, int y) {
	int res = 0;
	if (x) {
		res++;
		v[0] ^= 1;
		if (v.size() > 1) {
			v[1] ^= 1;
		}
	}
	for (int i = 1; i < v.size(); i++) {
		if (v[i - 1] != y) {
			res++;
			v[i - 1] ^= 1;
			v[i] ^= 1;
			if (i + 1 < v.size()) {
				v[i + 1] ^= 1;
			}
		}
	}
	if (v.back() != y) {
		return INF;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> v(n, false);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v[i] = (x & 1);
	}
	int ansOdd = min(solve(v, 0, 1), solve(v, 1, 1));
	int ansEven = min(solve(v, 0, 0), solve(v, 1, 0));
	if (ansOdd == INF) {
		ansOdd = -1;
	}
	if (ansEven == INF) {
		ansEven = -1;
	}
	cout << ansOdd << "\n" << ansEven << "\n";
}
