#include <bits/stdc++.h>

using namespace std;

const int MOD1 = 1000000007;
const int MOD2 = 1000000047;

const int N = 210000;

int hash1[N + 5];
int hash2[N + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("dat.txt", "r", stdin);
	hash1[0] = 1;
	hash2[0] = 1;
	map <pair <int, int>, int> M;
	map <pair <int, int>, int> :: iterator it;
	for (int i = 1; i <= N; i++) {
		hash1[i] = (long long)hash1[i - 1] * i % MOD1;
		hash2[i] = (long long)hash2[i - 1] * i % MOD2;
		M[make_pair(hash1[i], hash2[i])] = i;
	}
	string s;
	cin >> s;
	int v1 = 0;
	int v2 = 0;
	for (int i = 0; i < s.size(); i++) {
		v1 = (long long)v1 * 10LL % MOD1;
		v1 = (v1 + s[i] - '0') % MOD1;
		v2 = (long long)v2 * 10LL % MOD2;
		v2 = (v2 + s[i] - '0') % MOD2;
	}
	cout << M[make_pair(v1, v2)] << "\n";
}
