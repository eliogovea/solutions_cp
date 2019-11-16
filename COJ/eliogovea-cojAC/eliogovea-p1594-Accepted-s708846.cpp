#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;

int tc, a, b, c, aa, bb, cc, ans;
pair<int, int> x, y;
map<pair<int, int>, int > m;
queue<pair<int, int> > Q;

int main() {
	ios::sync_with_stdio(false);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d%d", &a, &b, &c);
		if (c > a && c > b) {
			printf("-1\n");
			continue;
		}
		ans = -1;
		m.clear();
		while (!Q.empty()) Q.pop();
		m[make_pair(0, 0)] = 0;
		Q.push(make_pair(0, 0));
		while (!Q.empty()) {
			x = Q.front();
			Q.pop();
			aa = x.first;
			bb = x.second;
			cc = m[x];
			if (aa == c || bb == c) {
				ans = cc;
				break;
			}
			if (aa != 0) {
				y = make_pair(0, bb);
				if (m.find(y) == m.end()) {
					m[y] = cc + 1;
					Q.push(y);
				}
				if (aa <= b - bb) {
					y = make_pair(0, bb + aa);
					if (m.find(y) == m.end()) {
						m[y] = cc + 1;
						Q.push(y);
					}
				} else {
					y = make_pair(aa - (b - bb), b);
					if (m.find(y) == m.end()) {
						m[y] = cc + 1;
						Q.push(y);
					}
				}
			}
			if (aa != a) {
				y = make_pair(a, bb);
				if (m.find(y) == m.end()) {
					m[y] = cc + 1;
					Q.push(y);
				}
			}
			if (bb != 0) {
				y = make_pair(aa, 0);
				if (m.find(y) == m.end()) {
					m[y] = cc + 1;
					Q.push(y);
				}
				if (bb <= a - aa) {
					y = make_pair(aa + bb, 0);
					if (m.find(y) == m.end()) {
						m[y] = cc + 1;
						Q.push(y);
					}
				} else {
					y = make_pair(a, bb - (a - aa));
					if (m.find(y) == m.end()) {
						m[y] = cc + 1;
						Q.push(y);
					}
				}
			}
			if (bb != b) {
				y = make_pair(aa, b);
				if (m.find(y) == m.end()) {
					m[y] = cc + 1;
					Q.push(y);
				}
			}
		}
		printf("%d\n", ans);
	}
}
