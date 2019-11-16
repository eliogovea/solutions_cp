//============================================================================
// Name        : 2997.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : 
//============================================================================

#include <iostream>

using namespace std;

typedef long long LL;

const LL mod = 1000000007;

LL n, dp[105];

int main() {
	dp[1] = 1;
	for (int i = 2; i <= 100; i++)
		for (int j = 1; j < i; j++) {
			dp[i] += (dp[j] * dp[i - j]) % mod;
			dp[i] %= mod;
		}
	while (cin >> n) cout << dp[n] << "\n";
}
