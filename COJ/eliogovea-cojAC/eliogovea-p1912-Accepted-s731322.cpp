#include <cstdio>

using namespace std;

const int mod = 1000000007;

const int N = 10000000;

int t, k, n;
int v[N + 5];

int main() {
  //freopen("dat.in", "r", stdin);
  scanf("%d%d", &t, &k);
	for (int i = 1; i < k; i++)
		v[i] = v[i - 1] + 1;
	v[k] = (2 * v[k - 1]) % mod;
	for (int i = k + 1; i <= N; i++)
		v[i] = ((2 * v[i - 1] % mod) - v[i - k - 1] + mod) % mod;
	while (t--) {
    scanf("%d", &n);
    printf("%d\n", (v[n] - v[n - 1] + mod) % mod);
	}
}
