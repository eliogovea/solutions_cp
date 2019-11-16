#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int n, m, a[MAXN], mx = -1;
bool mark[MAXN][MAXN];
vector<int> sol;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1, x, y; i <= m; i++) {
		cin >> x >> y;
		if (mark[x][y]) continue;
		mark[x][y] = 1;
		a[x]++;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] > mx) {
			sol.clear();
			sol.push_back(i);
			mx = a[i];
		}
		else if (a[i] == mx) sol.push_back(i);
	}
	sort(sol.begin(), sol.end());
	int s = sol.size();
	cout << sol[0];
	for (int i = 1; i < s; i++) cout << ' ' << sol[i];
	cout << '\n';
}
