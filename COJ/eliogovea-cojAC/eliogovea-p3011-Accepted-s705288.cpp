#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

typedef long long LL;

const int N = 1120;

bool criba[N + 5];
vector<int> p;

LL dp[N + 5][30];
int a, b;

int main() {
	ios::sync_with_stdio(false);
	for (int i = 2; i * i <= N; i++)
		if (!criba[i])
			for (int j = i * i; j <= N; j += i)
				criba[j] = true;
	for (int i = 2; i <= N; i++)
		if (!criba[i]) p.push_back(i);

    dp[0][0] = 1;
    for (int i = 0; i < p.size(); i++)
        for (int j = N; j >= p[i]; j--)
            for (int k = 14; k > 0; k--)
                dp[j][k] += dp[j - p[i]][k - 1];
    while (cin >> a >> b && (a | b)) {
    	assert(a <= 1120 && b <= 14);
    	cout << dp[a][b] << "\n";
    }
}
