#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vi::iterator viit;

const int MAXN = 1005;

int c, p, sol;
vector<int> G[MAXN];
bool dp[MAXN][MAXN], mark[MAXN][MAXN];

bool DP(int a, int b) {
    if (a > b) swap(a, b);
	if (a == 1 || b == 1) return true;
	if (a == b) return false;
	if (mark[a][b]) return dp[a][b];
	mark[a][b] = true;
	bool r = false;
	for (viit i = G[b].begin(); i != G[b].end(); i++) {
        r |= DP(a, *i);
        if (r) return dp[a][b] = true;
	}
	return dp[a][b] = false;
}

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> c >> p;
	for (int i = 0, a, b; i < p; i++) {
		cin >> a >> b;
		G[b].push_back(a);
	}
	sol = c - 1;
	for (int i = 3; i <= c; i++)
		for (int j = 2; j < i; j++)
			sol += DP(i, j);
	cout << sol << '\n';
}
