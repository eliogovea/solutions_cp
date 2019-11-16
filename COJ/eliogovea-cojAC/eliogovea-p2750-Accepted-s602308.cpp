#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 10010, MAXNLOG = 16;

int tc, n, c, r, g, ac[MAXN], RMQ[MAXN][MAXNLOG], pts[110];
vector<pair<int, int> > v;

int main() {
	for (scanf("%d", &tc); tc--;) {

		scanf("%d%d%d%d", &n, &c, &r, &g);

		for (int i = 1, x; i <= n; i++) {
			scanf("%d", &x);
			ac[i] = ac[i - 1] + x;
			RMQ[i][0] = x;
		}

		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 1; i + (1 << j) - 1 <= n; i++)
				RMQ[i][j] = min(RMQ[i][j - 1], RMQ[i + (1 << (j - 1))][j - 1]);

		for (int i = 1, a, b; i <= r; i++)
			for (int j = 1; j <= c; j++) {
				scanf("%d%d", &a, &b);
				int lg = (int)log2(b - a + 1);
				//int pt = (ac[b] - ac[a - 1]), pp = min(RMQ[a][lg], RMQ[b - (1 << lg) + 1][lg]);
				//printf(">>>>> %d %d %d %d\n", a, b, pt, pp);
				pts[j] += (ac[b] - ac[a - 1]) * min(RMQ[a][lg], RMQ[b - (1 << lg) + 1][lg]);
			}
        for (int i = 1; i <= c; i++)
            v.push_back(make_pair(pts[i], i));

		sort(v.begin(), v.end(), greater<pair<int, int> >());
		int pos;
		for (int i = 0; i < v.size(); i++)
			if (v[i].second == c) {
				pos = i;
				break;
			}

        //for (int i = 0; i < v.size(); i++)
          //  printf(">> %d %d\n", v[i].second, v[i].first);

        ////printf("pos %d\n", pos);

		int p = v[pos].first;
		for (int i = pos - 1; i >= 0; i--)
			if (g >= v[i].first - p) g -= v[i].first - p, pos--;
			else break;
		printf("%d\n", pos + 1);

		v.clear();
		for (int i = 1; i <= c; i++) pts[i] = 0;
	}
}
