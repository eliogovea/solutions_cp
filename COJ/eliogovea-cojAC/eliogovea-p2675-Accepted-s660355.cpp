#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int N, M, K, a[MAXN], b[MAXN];

int main() {
	//freopen("e.in", "r", stdin);
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) scanf("%d", a + i);
	for (int i = 0; i < M; i++) scanf("%d", b + i);
	sort(a, a + N);
	sort(b, b + M);
	int ans = 0;
	for (int i = 0, j = 0; i < N && j < M; i++) {
		j = lower_bound(b + j, b + M, a[i] - K) - b;
		if (abs(a[i] - b[j]) <= K && j < M) {
      ans++;
      j++;
		}
	}
	printf("%d\n", ans);
}
