//============================================================================
// Name        : 2809.cpp
// Author      : eliogovea
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

int n, c;
string w[10];
int let[30]['Z' + 5], aux['Z' + 5], dp[30][1 << 9];

inline bool check(int mask, int col) {
	for (int i = 'A'; i <= 'Z'; i++) aux[i] = 0;
	for (int i = 0; i < n; i++)
		if (mask & (1 << i))
			for (int j = 0; w[i][j]; j++)
				aux[w[i][j]]++;
	for (int i = 'A'; i <= 'Z'; i++)
		if (aux[i] > let[col][i]) return false;
	return true;
}

int main() {
	//freopen("e.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 1; i <= c; i++)
		for (int j = 'A'; j <= 'Z'; j++)
			cin >> let[i][j];
	for (int i = 0; i <= c; i++)
		dp[i][0] = true;

	for (int i = 0; i < c; i++)
		for (int j = 0; j < (1 << n); j++)
				if (dp[i][j])
					for (int k = 0; k < (1 << n); k++) {
						if (dp[i + 1][j | k]) continue;
						if (check(k, i + 1))
							dp[i + 1][j | k] = true;
					}
						

	if (dp[c][(1 << n) - 1]) cout << "YES\n";
	else cout << "NO\n";

}
