#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

inline int mul(int a, int b) {
	return (long long)a * b % MOD;
}

const int N = 10000;

vector <int> pf[N + 5];

int t;
int n, k;
bool used[N];
bool isUp[N];
set <int> up, down;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i <= N; i++) {
		if (!pf[i].size()) {
			for (int j = i; j <= N; j += i) {
				pf[j].push_back(i);
			}
		}
	}
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		cin >> n >> k;
		up.clear();
		down.clear();
		for (int i = 1; i <= n; i++) {
			isUp[i] = false;
			used[i] = false;
		}
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			up.insert(x);
			isUp[x] = true;
		}
		for (int i = 1; i <= n; i++) {
			if (!isUp[i]) {
				down.insert(i);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (i & 1) { // Jair - higher
				if (up.size() > 0) {
					int x = *up.rbegin();
					used[x] = true;
					up.erase(up.find(x));
					ans = mul(ans, n + 1);
					add(ans, x);
					for (int j = 0; j < pf[x].size(); j++) {
						int p = pf[x][j];
						if (!used[p]) {
							if (isUp[p]) {
								isUp[p] = false;
								up.erase(up.find(p));
								down.insert(p);
							} else {
								isUp[p] = true;
								down.erase(down.find(p));
								up.insert(p);
							}
						}
					}
				} else {
					int x = *down.rbegin();
					used[x] = true;
					down.erase(down.find(x));
					ans = mul(ans, n + 1);
					add(ans, x);
					for (int j = 0; j < pf[x].size(); j++) {
						int p = pf[x][j];
						if (!used[p]) {
							if (isUp[p]) {
								isUp[p] = false;
								up.erase(up.find(p));
								down.insert(p);
							} else {
								isUp[p] = true;
								down.erase(down.find(p));
								up.insert(p);
							}
						}
					}
				}
			} else { // Chadan - lower
				if (up.size() > 0) {
					int x = *up.begin();
					used[x] = true;
					up.erase(up.begin());
					ans = mul(ans, n + 1);
					add(ans, x);
					for (int j = 0; j < pf[x].size(); j++) {
						int p = pf[x][j];
						if (!used[p]) {
							if (isUp[p]) {
								isUp[p] = false;
								up.erase(up.find(p));
								down.insert(p);
							} else {
								isUp[p] = true;
								down.erase(down.find(p));
								up.insert(p);
							}
						}
					}
				} else {
					int x = *down.begin();
					used[x] = true;
					down.erase(down.begin());
					ans = mul(ans, n + 1);
					add(ans, x);
					for (int j = 0; j < pf[x].size(); j++) {
						int p = pf[x][j];
						if (!used[p]) {
							if (isUp[p]) {
								isUp[p] = false;
								up.erase(up.find(p));
								down.insert(p);
							} else {
								isUp[p] = true;
								down.erase(down.find(p));
								up.insert(p);
							}
						}
					}
				}
			}
		}
		cout << "Case #" << cas << ": " << ans << "\n";
	}
}
