#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 86405;

int tc, n;
pair<int, int> v[MAXN];

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;
		sort(v, v + n);
		bool con = false;
		for (int i = 1; i < n; i++)
			if (v[i].first <= v[i - 1].second) {
				con = true;
				break;
			}
		cout << (con ? "Conflict\n" : "No Conflict\n");
	}
}
