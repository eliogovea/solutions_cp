#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int n, a[20];
bool ok[2], p;
vector<int> v[2];
ll x, y, sol;

inline ll form(int x) {
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != 0) {
			ll r = v[x][i];
			for (int j = i - 1; j >= 0; j--) r = 10ll * r;
			for (int j = i + 1; j < v[x].size(); j++)
				r = 10ll * r + v[x][j];
			return r;
		}
}


int main() {
	//freopen("e.in", "r", stdin);
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a, a + n);
		sol = 1e17;
		for (int mask = 1; mask < (1 << n) - 1; mask++) {
			v[0].clear(); v[1].clear();
			ok[0] = ok[1] = false;
			for (int i = 0; i < n; i++) {
        p = ((mask & (1 << i)) != 0);
				v[p].push_back(a[i]);
				ok[p] |= (a[i] != 0);
			}
			if (ok[0] && ok[1]) {
				x = form(0);
				y = form(1);
				if (x + y < sol) sol = x + y;
			}
		}
		printf("%lld\n", sol);
	}
}
