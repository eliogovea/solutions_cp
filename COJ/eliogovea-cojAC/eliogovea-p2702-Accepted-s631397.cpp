#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 1005, MAXM = 50005;

ll n, a[MAXN][MAXN];
ll Q[MAXM][3], ind;
char c;
ll x, y, z;

int main() {
	ios::sync_with_stdio(false);
	//freopen("e.in", "r", stdin);
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> c >> x >> y >> z;
		if (y > z) swap(y, z);
		if (c == 'H') a[x][y]++, a[x][z + 1]--;
		else {
			Q[ind][0] = x;
			Q[ind][1] = y;
			Q[ind][2] = z;
			ind++;
		}
	}
	for (int i = 1; i < MAXN; i++)
		for (int j = 1; j < MAXN; j++)
			a[i][j] += a[i][j - 1];
	for (int i = 1; i < MAXN; i++)
		for (int j = 1; j < MAXN; j++)
			a[j][i] += a[j - 1][i];
	ll sol = 0;
	for (int i = 0; i < ind; i++)
		sol += a[Q[i][2]][Q[i][0]] - a[Q[i][1] - 1][Q[i][0]];
	cout << sol << '\n';
}
