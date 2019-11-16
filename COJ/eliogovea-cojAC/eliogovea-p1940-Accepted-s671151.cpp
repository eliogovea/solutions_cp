//============================================================================
// Name        : 1940.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include <cstdio>

using namespace std;

typedef long long LL;

const int MAXN = 300;

LL tc, x;
vector<int> v;
string str;
LL dp[MAXN + 5][MAXN + 5];

int main() {
	dp[0][0] = 1LL;
	for (int i = 1; i <= MAXN; i++)
		for (int j = 0; j + i <= MAXN; j++)
			for (int k = 0; k < MAXN; k++)
				dp[j + i][k + 1] += dp[j][k];

	for (int i = 0; i <= MAXN; i++)
		for (int j = 1; j <= MAXN; j++)
			dp[i][j] += dp[i][j - 1];
	//freopen("e.in", "r", stdin);
	while (getline(cin, str)) {
		istringstream ss(str);
		v.clear();
		while (ss >> x) v.push_back(x);
		assert(v.size() >= 1 && v.size() <= 3);
		if (v[1] >= MAXN) v[1] = MAXN;
		if (v[2] >= MAXN) v[2] = MAXN;
		if (v.size() == 1) cout << dp[v[0]][MAXN];
		else if (v.size() == 2) cout << dp[v[0]][v[1]];
		else if (v.size() == 3)cout << dp[v[0]][v[2]] - dp[v[0]][v[1] - 1];
		cout << "\n";
	}
}
