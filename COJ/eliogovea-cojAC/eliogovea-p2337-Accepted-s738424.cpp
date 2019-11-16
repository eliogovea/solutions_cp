#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

priority_queue<int> Q;
int n, x[1005], y[1005];
double ans, a;

int main() {
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", x + i, y + i);
			for (int j = 0; j < i; j++) {
				Q.push((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
				if (Q.size() > 6) Q.pop();
			}
		}
		ans = 0;
		while (!Q.empty()) {
			a = Q.top(); Q.pop();
			a = sqrt(a);
			ans += a;
		}
		printf("%.2lf\n", ans);
	}
}
