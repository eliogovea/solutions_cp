#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vi::iterator viit;

const int MAXN = 100005;

int tc, n, r;
vi G[MAXN];
vector<int> v;

int dfs(int u) {
	int c = 0, x, tot = 0;
	bool b = true;
	for (viit i = G[u].begin(); i != G[u].end(); i++) {
		x = dfs(*i);
		if (c) b &= (x == c);
		else c = x;
		tot += x;
	}
	tot++;
	b &= (n - tot == c || c == 0 || n - tot == 0);
	if (b) v.push_back(u);
	return tot;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			G[i].clear();
		for (int i = 1, x; i <= n; i++) {
			cin >> x;
			if (x == 0) r = i;
			else G[x].push_back(i);
		}
		v.clear();
		dfs(r);
		sort(v.begin(), v.end());
		cout << v.size();
		for (int i = 0; i < v.size(); i++)
			cout << ' ' << v[i];
		cout << '\n';
	}
}
