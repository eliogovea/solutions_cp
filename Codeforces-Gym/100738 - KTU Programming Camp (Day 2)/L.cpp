// KTU Programming Camp (Day 2)
// 100738L

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1005;

typedef long long LL;

int t;
int n, w;
LL mat[N][N];
LL d1[N][N], d2[N][N];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &w);
        for (int i = 1; i <= n + 1; i++) {
            d1[n + 1][i] = d1[i][n + 1] = d2[n + 1][i] = d2[i][n + 1] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%I64d", &mat[i][j]);
                d1[i][j] = (LL)mat[i][j] + d1[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = n; j >= 1; j--) {
                d2[i][j] = (LL)mat[i][j] + d2[i - 1][j + 1];
            }
        }
                int ans = 0;
        for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (mat[i][j] <= w) {
                            int lo = 1;
                            int hi = min(i, min(j, min(n - i + 1, n - j + 1)));
                            int best = 1;
                            while (lo <= hi) {
                                int mid = (lo + hi) >> 1;
                                LL val = d1[i + mid - 1][j + mid - 1] - d1[i - mid][j - mid] + d2[i + mid - 1][j - mid + 1] - d2[i - mid][j + mid] - mat[i][j];
                                if (val <= w) {
                                    best = mid;
                                    lo = mid + 1;
                                } else {
                                    hi = mid - 1;
                                }
                            }
                            ans = max(ans, 2 * best - 1);
                        }
                        int lo = 1;
                        int hi = min(i - 1, min(j - 1, min(n - i + 1, n - j + 1)));
                        int best = 0;
                        while (lo <= hi) {
                            int mid = (lo + hi) >> 1;
                            LL val = d1[i + mid - 1][j + mid - 1] - d1[i - mid - 1][j - mid - 1] + d2[i + mid - 1][j - 1 - mid + 1] - d2[i - 1 - mid][j + mid];
                            if (val <= w) {
                                best = mid;
                                lo = mid + 1;
                            } else {
                                hi = mid - 1;
                            }
                        }
                        ans = max(ans, 2 * best);
                    }
                }
                printf("%d\n", ans);
    }
}
