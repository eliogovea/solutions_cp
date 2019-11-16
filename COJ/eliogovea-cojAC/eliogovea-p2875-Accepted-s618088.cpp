#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define sf scanf
#define pf printf

typedef long long ll;

const int MAXN = 5000;
const ll mod = 1000000007;

int tc, n;
ll dp[MAXN +10];

int main() {
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= MAXN; i++) {
        for (int j = 1; j < i; j++)
            dp[i] = (dp[i] + (dp[j] * dp[i - j]) % mod) % mod;
    }
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        if (n == 1) printf("0\n");
        else printf("%lld\n", dp[n]);
    }
}
