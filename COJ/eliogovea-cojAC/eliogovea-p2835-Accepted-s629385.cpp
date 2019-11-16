#include <bits/stdc++.h>
using namespace std;

#define ForIt(it, M) for (typeof((M.begin())) it = M.begin(); it != M.end(); it++)

typedef long long ll;
const ll MAXN = 100005;

ll n, edge[MAXN], a, b;
vector<pair<ll, ll> > G[MAXN];
bool mark[MAXN];

ll dfs(ll u) {
	ll ret = 0, cont;
	mark[u] = 1;
	ForIt(it, G[u])
		if (!mark[it->first]) {
			cont = 1 + dfs(it->first);
			edge[it->second] = cont * (n - cont);
			ret += cont;
		}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (ll i = 1; i < n; i++) {
		cin >> a >> b;
		G[a].push_back(make_pair(b, i));
		G[b].push_back(make_pair(a, i));
	}
	dfs(1);
	for (int i = 1; i < n; i++) cout << edge[i] << '\n';
}
