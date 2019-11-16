#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int n;
int x[MAXN], y[MAXN];
vector<int> G[MAXN], X, Y;
int match[MAXN], used[MAXN], mk;

bool kuhn(int u) {
	if (used[u] == mk) return false;
	used[u] = mk;
	for (int i = 0; i < G[u].size(); i++) {
		int to = G[u][i];
		if (match[to] == 0 || kuhn(match[to])) {
			match[to] = u;
			return true;
		}
	}
	return false;
}

bool BM() {
	int r = 0;
	for (int i = 0; i < X.size(); i++) {
		mk++;
		if (kuhn(1 + i)) r++;
		if (r > 3) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("e.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		X.push_back(x[i]);
		Y.push_back(y[i]);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (int i = 0; i < n; i++) {
		int a = upper_bound(X.begin(), X.end(), x[i]) - X.begin();
		int b = upper_bound(Y.begin(), Y.end(), y[i]) - Y.begin();
		G[a].push_back(b);
	}
	if (BM()) cout << "1\n";
	else cout << "0\n";
}
